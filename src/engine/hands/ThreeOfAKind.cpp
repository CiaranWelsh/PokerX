//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/ThreeOfAKind.h"

namespace pokerx {
    bool ThreeOfAKind::isA() const {
        return xOfAKindIsA(3, 1);
    }

    std::shared_ptr<CardCollection> ThreeOfAKind::getBestFive() const {
        // todo figure out whether this is a bug.
        // conceptually two pair is differemt from xofakind
        return std::make_shared<CardCollection>(
                xOfAKindBest5<ThreeOfAKind>(3));
    }

    HandType ThreeOfAKind::getHandType() const {
        return THREE_OF_A_KIND;
    }

    int ThreeOfAKind::getValue() {
        return getValueOfXOfAKind(3);
    }
}
