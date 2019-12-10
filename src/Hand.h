//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HAND_H
#define POKERSIMULATIONSINCPP_HAND_H

#include <tuple>
#include <utility>
#include "Card.h"

namespace Game {
    struct HoleCards {
        HoleCards(Card &card1, Card &card2) : card1(card1), card2(card2) {};

        Card &card1;
        Card &card2;
    };

    struct CommunityCards {
        /*
         * 0 card constructor
         */
        CommunityCards() {

        }

        /*
         * 3 card constructor
         */
        CommunityCards(Card card1= nullptr, Card &card2, Card &card3) : card1(card1),
                                                   card2(card2), card3(card3) {}

        /*
         * 4 card constructor
         */
        CommunityCards(Card &card1, Card &card2,
                       Card &card3, Card &card4) : card1(card1),
                                                   card2(card2),
                                                   card3(card3),
                                                   card4(card4) {}

        /*
         * 5 card constructor
         */
        CommunityCards(Card &card1,
                       Card &card2,
                       Card &card3,
                       Card &card4,
                       Card &card5) : card1(card1),
                                      card2(card2), card3(card3), card4(card4),
                                      card5(card5) {}


        Card &card1;
        Card &card2;
        Card &card3;
        Card &card4;
        Card &card5;
    };

    class Hand {
    private:
        HoleCards _holeCards;
        CommunityCards _communityCards;
    public:
        Hand(HoleCards holeCards, CommunityCards communityCards) :
                _holeCards(std::move(holeCards)),
                _communityCards(std::move(communityCards)) {}; //constructor
        ~Hand(); // destructor
        Hand(const Hand &hand); // copy constructor

//        Hand evaluate();
    };
};

#endif //POKERSIMULATIONSINCPP_HAND_H
