//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_IHAND_H
#define POKERX_IHAND_H

#include "PokerX/engine/RestrictedCardCollection.h"
#include "PokerX/engine/hands/HandType.h"

namespace pokerx {

    class IHand : public RestrictedCardCollection {

    public:
        using RestrictedCardCollection::RestrictedCardCollection;

        explicit IHand(const std::vector<ICard *> &cards) : RestrictedCardCollection(cards, 7) {}

        [[nodiscard]] virtual bool isA() const = 0;

        [[nodiscard]] virtual std::shared_ptr<CardCollection> getBestFive() const = 0;

        bool operator==(const IHand& hand);

        bool operator!=(const IHand &hand);

        bool operator>(const IHand &hand);

        bool operator<(const IHand &hand);

        [[nodiscard]] virtual HandType getHandType() const = 0;

        [[nodiscard]] virtual int getValue() = 0;

    protected:
        int value_;
        virtual void setValue(int value);

    };
}


#endif //POKERX_IHAND_H
