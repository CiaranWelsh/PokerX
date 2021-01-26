//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_HIGHCARD_H
#define POKERX_HIGHCARD_H

#include "PokerX/engine/hands/IHand.h"

namespace pokerx {

    class HighCard : public IHand {
    public:

        using IHand::IHand;

        ~HighCard() override = default;

        [[nodiscard]] std::shared_ptr<CardCollection> getBestFive() const override;

        [[nodiscard]] bool isA() const override;

        [[nodiscard]] HandType getHandType() const override;

        int getValue() override;

    };
}


#endif //POKERX_HIGHCARD_H
