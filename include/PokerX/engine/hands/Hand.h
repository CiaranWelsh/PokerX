//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_HAND_H
#define POKERX_HAND_H

#include "PokerX/engine/RestrictedCardCollection.h"
#include "PokerX/engine/hands/Best5.h"
#include "PokerX/engine/hands/HandType.h"

namespace pokerx {

    class Hand : public RestrictedCardCollection {
    public:

        // as a subclass do we not have access to this anyway?
        // testme
        using RestrictedCardCollection::add;

        using RestrictedCardCollection::RestrictedCardCollection;

        Hand();

        ~Hand() override = default;

        Best5 *bestFive();

        /**
         * @brief determine what hand these cards evaluate to
         * @details Algorithms starts at ROYAL_FLUSH and works its way
         * down the hierachy returning when it evaluates to true.
         */
        HandType getType();


    private:
        bool isHighCard();

        bool isPair();

        bool isTwoPair();

        bool isThreeOfAKind();

        bool isStraight();

        bool isFlush();

        bool isFullHouse();

        bool isFourOfAKind();

        bool isStraightFlush();

        bool isRoyalFlush();
    };

}

#endif //POKERX_HAND_H
