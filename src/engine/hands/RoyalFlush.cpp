//
// Created by Ciaran Welsh on 25/01/2021.
//

#include <PokerX/engine/hands/StraightFlush.h>
#include "PokerX/engine/hands/RoyalFlush.h"

namespace pokerx {

    bool RoyalFlush::isA() const {
        StraightFlush sflush(cards_);
        if (!sflush.isA())
            return false;
        CardCollection sflushcards = *(sflush.getBestFive());
        return sflush.isA() && (sflushcards[0]->getRank() == 10
                                && sflushcards[1]->getRank() == 11
                                && sflushcards[2]->getRank() == 12
                                && sflushcards[3]->getRank() == 13
                                && sflushcards[4]->getRank() == 14);
    }


    std::shared_ptr<CardCollection> RoyalFlush::getBestFive() const {
        if (!isA())
            return std::make_shared<CardCollection>();
        StraightFlush straight_flush(cards_);
        return straight_flush.getBestFive();
    }


    HandType RoyalFlush::getHandType() const {
        return ROYAL_FLUSH;
    }

    int RoyalFlush::getValue() {
        auto cc = getBestFive();
        value_ = (*cc)[cc->size() - 1]->getRank();
        return value_;
    }
}
