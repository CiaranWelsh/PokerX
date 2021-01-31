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

        std::shared_ptr<CardCollection> bestFiveCards();

        /**
         * @brief determine what hand these cards evaluate to
         * @details Algorithms starts at ROYAL_FLUSH and works its way
         * down the hierachy returning when it evaluates to true.
         */
        HandType getType() const;

        bool operator==(const Hand& other)  const;

        bool operator!=(const Hand &other) const;

        bool operator<(const Hand& other) const;

        bool operator>(const Hand& other) const;


    private:
        [[nodiscard]] bool isHighCard() const;

        [[nodiscard]] bool isPair() const;

        [[nodiscard]] bool isTwoPair() const;

        [[nodiscard]] bool isThreeOfAKind() const;

        [[nodiscard]] bool isStraight() const;

        [[nodiscard]] bool isFlush() const;

        [[nodiscard]] bool isFullHouse() const;

        [[nodiscard]] bool isFourOfAKind() const;

        [[nodiscard]] bool isStraightFlush() const;

        [[nodiscard]] bool isRoyalFlush() const;
    };

}

#endif //POKERX_HAND_H
