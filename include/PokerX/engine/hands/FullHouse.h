//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_FULLHOUSE_H
#define POKERX_FULLHOUSE_H

#include "PokerX/engine/hands/IHand.h"
#include "PokerX/engine/hands/Best5.h"

namespace pokerx {


    class FullHouse : public IHand {

    public:
        using IHand::IHand;

        [[nodiscard]] bool isA() const override;

        [[nodiscard]] std::shared_ptr<CardCollection> getBestFive() const override;

        [[nodiscard]] HandType getHandType() const override;

    };
}



#endif //POKERX_FULLHOUSE_H
