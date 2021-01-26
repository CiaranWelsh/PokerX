//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/FourOfAKind.h"
namespace pokerx{
    bool FourOfAKind::isA() const {
        return xOfAKindIsA(4, 1);
    }

    std::shared_ptr<CardCollection> FourOfAKind::getBestFive() const {
        // todo figure out whether this is a bug.
        // conceptually two pair is differemt from xofakind
        return std::make_shared<CardCollection>(
                xOfAKindBest5<FourOfAKind>(4));
    }

    HandType FourOfAKind::getHandType() const {
        return FOUR_OF_A_KIND;
    }

    int FourOfAKind::getValue() {
        value_ = getValueOfXOfAKind(4);
        return value_;
    }
}
