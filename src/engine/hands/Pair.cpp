//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/Pair.h"
#include "PokerX/engine/Counter.h"
#include <memory>

namespace pokerx{

    bool Pair::isA() const {
        return xOfAKindIsA(2, 1);
    }

    std::shared_ptr<CardCollection> Pair::getBestFive() const {
        CardCollection cc = xOfAKindBest5<Pair>(2);
        return std::make_shared<CardCollection>(
                xOfAKindBest5<Pair>(2));
    }

    HandType Pair::getHandType() const {
        return PAIR;
    }

    int Pair::getValue() {
        value_ = getValueOfXOfAKind(2);
        return value_;
    }


}
