//
// Created by Ciaran Welsh on 25/01/2021.
//

#include <PokerX/engine/hands/Straight.h>
#include "PokerX/engine/hands/StraightFlush.h"
#include "PokerX/engine/hands/Flush.h"

namespace pokerx {

    bool StraightFlush::isA() const {
        bool straight = Straight(cards_).isA();
        bool flush = Flush(cards_).isA();
        return straight && flush;
    }

    std::shared_ptr<CardCollection> StraightFlush::getBestFive() const {
        if (!isA())
            return std::make_shared<CardCollection>();
        Straight straight(cards_);
        /*
         * we can directly return the straight here, since we have already checked
         * that we have a straight flush. The straight returns the highest 5 cards
         * in a row and all must be the same suit or we would have already returned empty CardCollection
         */
        return straight.getBestFive();
    }

    HandType StraightFlush::getHandType() const {
        return STRAIGHT_FLUSH;
    }

    int StraightFlush::getValue() {
        auto cc = getBestFive();
        value_ = (*cc)[cc->size() - 1]->getRank();
        return value_;
    }
}
