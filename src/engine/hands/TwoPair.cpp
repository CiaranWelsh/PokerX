//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/TwoPair.h"

namespace pokerx {

    bool TwoPair::isA() const {
        return xOfAKindIsA(2, 2);
    }

    std::shared_ptr<CardCollection> TwoPair::getBestFive() const {
        // todo figure out whether this is a bug.
        // conceptually two pair is differemt from xofakind
        return std::make_shared<CardCollection>(
                xOfAKindBest5<TwoPair>(2));
    }

    HandType TwoPair::getHandType() const {
        return TWO_PAIR;
    }

    int TwoPair::getValue() {
        return getValueOfXOfAKind(2);
    }
}
