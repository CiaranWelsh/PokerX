//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/Straight.h"
#include "PokerX/Error.h"

namespace pokerx {
    bool Straight::isA() const {
        CardCollection cards(cards_);
        std::vector<int> ranks = cards.getRanks();
        // three frames are possible with 5 consequative numbers in 7
        int frames[] = {0, 1, 2};

        // deal with low aces
        if (cards[0]->getRank() == 2 && cards[1]->getRank() == 3 && cards[2]->getRank() == 4 &&
            cards[3]->getRank() == 5 && cards[6]->getRank() == 14) {
            return true;
        }

        CardCollection matches;
        for (int frame : frames) {
            matches.clear();
            int current_rank = ranks[frame];
            for (int i = 0; i < ranks.size(); i++) {

                int rank = ranks[i];
                if (current_rank == rank) {
                    matches.add(cards[i]);
                    current_rank++;
                }
                if (matches.size() == 5)
                    return true;
            }
        }
        return false;
    }

    std::shared_ptr<CardCollection> Straight::getBestFive() const {
        if (!isA()) {
            return std::make_shared<CardCollection>();
        }
        CardCollection cc(cards_);
        std::vector<int> ranks = cc.getRanks();
        // three frames are possible with 5 consequative numbers in 7
        int frames[] = {0, 1, 2};

        // Deal with low aces straights
        CardCollection best5_ace_low;
        if (cards_[0]->getRank() == 2 && cards_[1]->getRank() == 3 && cards_[2]->getRank() == 4 &&
            cards_[3]->getRank() == 5 && cards_[6]->getRank() == 14) {
            for (int i : {0, 1, 2, 3, 6}) {
                best5_ace_low.add(cards_[i]);
            }
        }

        CardCollection best5;
        for (int frame : frames) {
            CardCollection best5_temp;
            best5_temp.clear();
            int current_rank = ranks[frame];
            for (size_t i = 0; i < ranks.size(); i++) {
                int rank = ranks[i];
                if (current_rank == rank) {
                    best5_temp.add(cards_[i]);
                    current_rank++;
                }
                if (best5_temp.size() == 5) {
                    best5 = best5_temp.copy(); // will be replaced with a higher ranking straight if necessary
                }
            }
        }
        if (best5.size() == 5 && best5_ace_low.size() != 5) {
            return std::make_shared<CardCollection>(best5);
        } else if (best5.size() != 5 && best5_ace_low.size() == 5)
            return std::make_shared<CardCollection>(best5_ace_low);
        else if (best5.size() == 5 && best5_ace_low.size() == 5) {
            return std::make_shared<CardCollection>(best5); // every other type of straight will beat an Ace low straight
        } else {
            LOGIC_ERROR << "You did a bad" << std::endl;
        }
    }


//    bool Straight::isA() const {
//        CardCollection cc(cards_);
//        std::vector<int> ranks = cc.getRanks();
//
//        // deal with low aces
//        if (cc[0]->getRank() == 2 && cc[1]->getRank() == 3 && cc[2]->getRank() == 4 &&
//            cc[3]->getRank() == 5 && cc[6]->getRank() == 14) {
//            return true;
//        }
//
//        // three frames are possible with 5 consecutive numbers in 7,
//        // assuming no duplicate numbers
//        int frames[] = {0, 1, 2};
//
//        for (int frame : frames) {
//
//            // we create a vector containing the numbers that would make our straight
//            std::vector<int> proposal_straight;
//            for (int i = ranks[frame]; i < ranks[frame] + 5; i++) {
//                proposal_straight.push_back(i);
//            }
//
//            // Get what we have in our hand, from index frame to frame+5
//            // However we also need to track duplicates and if we come
//            // across two equal ranks, we skip this card. Remember
//            // that the CardCollection is sorted at all times, so assume
//            // cards with the same rank are adjacent to one another.
//            std::vector<int> our_cards;
//            our_cards.push_back(ranks[frame]);
//            for (int i = 1; i < 5; i++) {
//                if (ranks[i] == ranks[i - 1]) {
//                    // if we've just added this rank we do nothing
//                } else {
//                    our_cards.push_back(ranks[i]);
//                }
//            }
//
//            if (our_cards == proposal_straight) {
//                return true;
//            }
//        }
//
//        return false;
//    }

//    std::shared_ptr<CardCollection> Straight::getBestFive() const {
//        if (!isA()) {
//            return std::make_shared<CardCollection>();
//        }
//        CardCollection cc(cards_);
//        std::vector<int> ranks = cc.getRanks();
//        // three frames are possible with 5 consequative numbers in 7
//        int frames[] = {0, 1, 2};
//
//        // Deal with low aces straights
//        CardCollection best5_ace_low;
//        if (cc[0]->getRank() == 2 && cc[1]->getRank() == 3 && cc[2]->getRank() == 4 &&
//            cc[3]->getRank() == 5 && cc[6]->getRank() == 14) {
//            for (int i : {0, 1, 2, 3, 6}) {
//                best5_ace_low.add(cc[i]);
//            }
//        }
//        CardCollection best5;
//        for (int frame : frames) {
//            CardCollection best5_temp;
//            best5_temp.clear();
//            int current_rank = ranks[frame];
//            for (size_t i = 0; i < ranks.size(); i++) {
//                int rank = ranks[i];
//                if (current_rank == rank) {
//                    best5_temp.add(cc[i]);
//                    current_rank++;
//                }
//                if (best5_temp.size() == 5) {
//                    best5 = best5_temp.copy(); // will be replaced with a higher ranking straight if necessary
//                }
//            }
//        }
//        if (best5.size() == 5 && best5_ace_low.size() != 5) {
//            return std::make_shared<CardCollection>(best5);
//        } else if (best5.size() != 5 && best5_ace_low.size() == 5)
//            return std::make_shared<CardCollection>(best5_ace_low);
//        else if (best5.size() == 5 && best5_ace_low.size() == 5) {
//            return std::make_shared<CardCollection>(
//                    best5); // every other type of straight will beat an Ace low straight
//        } else {
//            LOGIC_ERROR << "You did a bad" << std::endl;
//        }
//    }

    HandType Straight::getHandType() const {
        return TWO_PAIR;
    }

    int Straight::getValue() {
        // protect against trying to access empty CardCollection
        if (getBestFive()->empty()) {
            value_ = 0;
        } else {
            // when we have a low straight, replace ace with value 1
            std::vector<int> ranks = getBestFive()->getRanks();
            if (
                    ranks[0] == 2 &&
                    ranks[1] == 3 &&
                    ranks[2] == 4 &&
                    ranks[3] == 5 &&
                    ranks[4] == 14) {
                value_ = 5;
            } else {
                // todo couldnt we jus sort and take the last?
                auto result = std::max_element(ranks.begin(), ranks.end());
                auto idx_of_max_element = std::distance(ranks.begin(), result);
                return ranks[idx_of_max_element];
            }
        }
    }
}

