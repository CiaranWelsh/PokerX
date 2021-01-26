//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_TWOPAIR_H
#define POKERX_TWOPAIR_H

#include "PokerX/engine/hands/IHand.h"
#include "PokerX/engine/hands/Best5.h"

namespace pokerx {

    class TwoPair : public IHand {

    public:
        using IHand::IHand;

        [[nodiscard]] bool isA() const override;

        [[nodiscard]] std::shared_ptr<CardCollection> getBestFive() const override;

        [[nodiscard]] HandType getHandType() const override;

    };
}


#endif //POKERX_TWOPAIR_H
