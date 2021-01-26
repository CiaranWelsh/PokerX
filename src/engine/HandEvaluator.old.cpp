//
// Created by CiaranWelsh on 19/12/2019.
//

#include "PokerX/engine/HandEvaluator.old.h"
#include "PokerX/engine/hands/Hand.old.h"
#include <iostream>
#include <dshow.h>

using namespace std;

namespace eval {

    std::map<int, HandType> HandEvaluator::evaluate(std::vector<HandPtr> hands) {
        // collect hand subclass objects in a map
        typedef std::map<int, HandPtr> HandMap;
        HandMap hand_types;
        for (int i=0; i < hands.size(); i++){
            hand_types[i] = hands[i]->evaluate();
        }

        // collect the best5 objcets into a map
        typedef std::map<int, CardCollection> CardCollectionMap;
        CardCollectionMap best5map;
        for (int i=0; i < hands.size(); i++){
            best5map[i] = hand_types[i]->best5();
        }

        // convert Hands to their numerical values
        typedef std::map<int, HandType> HandTypeMap;
        HandTypeMap hand_evaluations;
        for (int i = 0; i < hands.size(); i++) {
            hand_evaluations[i] = hand_types[i]->getHandType();
        }

        // copy values to a vector for use with Counter
        std::vector<HandType> hand_evaluations_hand_types;
        for (auto &hand_evaluation : hand_evaluations) {
            hand_evaluations_hand_types.push_back(hand_evaluation.second);
        }

        // Count instances of Hand.old values
        Counter<HandType> counter(hand_evaluations_hand_types);

        // get the value of the element with max HandType value
        pair<HandType, vector<int>> max_hand = getMaxValueOfAMap(hand_evaluations);

        if (max_hand.second.empty()) {
            throw errors::ValueError("You is got an empty", __FILE__, __LINE__);
        }
        // If >1 player has the max hand, switch the dupe_max_hand switch
        bool dupe_max_hand = false;
        if (max_hand.second.size() > 1) {
            dupe_max_hand = true;
        }

        std::map<int, HandType> outmap;
        // handle simpler case when only 1 players has the winning HandType
        if (!dupe_max_hand) {
            // max_hand signature: map<HandType, vector<int>>
            // index of player with max hand is second and the value of max hand is first
            outmap[max_hand.second[0]] = max_hand.first;
            return outmap;

        } else {
            // A split pot only ever happens when > 1 players best5 are identical.
            // so test for this first. If this is not the case, then there will be
            // a winner.

            // work out whether players with same poker hand have the same best5
            CardCollectionMap potential_winners;
            for (auto i : best5map){
                // if i in max_hand.second
                if(std::find(max_hand.second.begin(), max_hand.second.end(), i.first) != max_hand.second.end()){
                    potential_winners[i.first] = i.second;
                }
            }
            vector<CardCollection> hand_ranks_of_potential_winners = getValuesOfMap(potential_winners);
            // test for equality
            bool hands_equal = std::adjacent_find(
                    hand_ranks_of_potential_winners.begin(),
                    hand_ranks_of_potential_winners.end(),
                    std::not_equal_to<>()) == hand_ranks_of_potential_winners.end();
            if (hands_equal) {
                for (auto &i : max_hand.second) {
                    outmap[i] = max_hand.first;
                }
                return outmap;
            } else {
                // return the maximum "value" of the players that have the winning hand type.
                HandType &winning_hand_type = max_hand.first;
                int maximum_value = 0;
                int idx_of_maximum_value = 0; // initialised doesn't exist
                for (auto i : hand_types){
                    if (i.second->getValue() > maximum_value){
                        maximum_value = i.second->getValue();
                        idx_of_maximum_value = i.first;
                    }
                }
                outmap[idx_of_maximum_value] = winning_hand_type;
                return outmap;
            }
        }
    }
}




