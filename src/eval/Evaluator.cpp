//
// Created by CiaranWelsh on 19/12/2019.
//

#include "Evaluator.h"
#include "Hand.h"
#include <iostream>
#include <dshow.h>

using namespace std;

namespace eval {

    std::map<int, HandType> Evaluator::evaluate(std::vector<HandPtr> hands) {
        // convert Hands to their numerical values
        typedef std::map<int, HandType> Map;
        Map hand_evaluations;
        for (int i = 0; i < hands.size(); i++) {
            hand_evaluations[i] = hands[i]->evaluate()->getHandType();
        }
        // copy values to a vector for use with Counter
        std::vector<HandType> hand_evaluations_values;
        for (auto &hand_evaluation : hand_evaluations)
            hand_evaluations_values.push_back(hand_evaluation.second);

        // Count instances of Hand values
        Counter<HandType> counter(hand_evaluations_values);
        cout << "Counter: HandType to Count" << endl;
        cout << counter << endl;

        // get the value of the element with max HandType value
        pair<HandType, vector<int>> max_hand = getMaxValueOfAMap(hand_evaluations);

        if (max_hand.second.empty()) {
            throw errors::ValueError("You is got an empty", __FILE__, __LINE__);
        }
        // If >1 player has the max hand, switch the dupe_max_hand switch
        bool dupe_max_hand = false;
        if (max_hand.second.size() > 1)
            dupe_max_hand = true;

        std::map<int, HandType> outmap;
        // handle simpler case when only 1 players has the winning HandType
        if (!dupe_max_hand) {
            // max_hand signature: map<HandType, vector<int>>
            for (auto i : max_hand.second)
                cout << i;
            // index of player with max hand is second and the value of max hand is first
            outmap[max_hand.second[0]] = max_hand.first;
            return outmap;

        } else {
            // A split pot only ever happens when > 1 players best5 are identical.
            // so test for this first. If this is not the case, then there will be
            // a winner.
            cout << "two or more players have the same HandType" << endl;

            // work out whether players with same poker hand have the same best5
            std::vector<int> indexes_of_potential_winners = max_hand.second;
            std::vector<CardCollection> hand_ranks_of_potential_winners;
            for (int i : indexes_of_potential_winners) {
                hand_ranks_of_potential_winners.push_back(hands[i]->best5());
                cout << hands[i]->best5() << endl;
            }
            // test for equality
            bool hands_equal = std::adjacent_find(
                    hand_ranks_of_potential_winners.begin(),
                    hand_ranks_of_potential_winners.end(),
                    std::not_equal_to<>()) == hand_ranks_of_potential_winners.end();
            if (hands_equal) {
                cout << " hands are equal, split pot" << endl;
                for (auto &i : max_hand.second) {
                    outmap[i] = max_hand.first;
                }
                return outmap;
            } else {
                cout << "Hands are not equal, so who wins? ";
                HandType &winning_hand_type = max_hand.first;
                cout << "The winning hand was a : << " << winning_hand_type;
                /*
                 * Maybe each hand type needs a new value which
                 * corresponds to its rank when compared against another
                 * hand type of the same kind.
                 *
                 * Pair, toak and foak = the value of the pair
                 * Two pair and full house = the value of the larger
                 *
                 * Straights and straight flush = the highest card
                 *
                 */
                // find out what the winning hand was.
                std::vector<HandType> group1 = {};

            }
        }

//            for (auto &i : hands)
//                cout << *i << endl;
//            cout << "The max hand is: " << max_hand.first << endl;
//            if (max_hand.first == HighCard_){
//                // sum the best 5 cards for both
//            } else if (max_hand.first == Pair_){
//                // figure out player that has the larger pair
//                // if both players have the same pair, then add up
//            }
//        }

//                sum_of_max_hands[i] = hands[i]->sumBest5Ranks();
//                cout << sum_of_max_hands[i] << " " ;
//            }
//
//            // similar logic to get the max from sum_of_max_hands
//            pair<int, vector<int>> max_hand2 = getMaxValueOfAMap(sum_of_max_hands);
//            cout << "Figuring out which has the max value" << endl;
//            cout << "max_hand.first " << max_hand2.first << endl;
//            cout << "max_hand.second " ;
//            for (auto i: max_hand2.second)
//                cout << i;
//            cout << endl;
//
//
//            // if they are equal, we need a split pot.
//            bool split_pot = false;
//            if (max_hand.second.size() > 1)
//                split_pot = true;
//
//            // handle the simpler case of clear winner by high card
//            if (!split_pot) {
//                // return maximum of the argmax2
//                std::map<int, HandType> outmap2;
//                outmap2[max_hand.second[0]] = max_hand.first;
//                return outmap2;
//            } else {
//                cout << "bad man" << endl;
////                throw errors::NotImplementedError("Not yet implemented the situation where "
////                                                  "we need split pot", __FILE__, __LINE__);
//            }
//
//        }
    }
}

//        }
//        for (std::pair<HandType, int> i : counter.count()){
//            if (i.second == max_hand && i.second > 1) {
//                dupe_max_hand = true;
//            }
//        }
//        if (!dupe_max_hand)
//            return std::pair<int, HandType >(max_hand_idx, max_hand);

// deal with situation where >1 player has a hand
//        std::vector<int > same_hand_players_idx;
//        std::vector<HandPtr> same_hand_players;
//        if (dupe_max_hand) {
//             find the players
//            for (int i=0; i<vec.size(); i++) {
//                if (vec[i] == max_hand)
//                    same_hand_players_idx.push_back(i);
//            }
//            bool size_check = same_hand_players_idx.size() >= 1;
//            if (size_check)
//                throw errors::ValueError("Should not happen", __FILE__, __LINE__);
//            for(int i=0; i<same_hand_players_idx.size(); i++){
//                if ()
//            }
//        }





//        return ;


//    }
//}
