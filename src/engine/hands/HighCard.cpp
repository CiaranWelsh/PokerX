//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/HighCard.h"
namespace pokerx{


    std::shared_ptr<CardCollection> HighCard::getBestFive() const {
        CardCollection cc(cards_);
        cc.sort();
        return std::make_shared<CardCollection>(cc(2, cc.size()));
    }

    bool HighCard::isA() const {
        return false;
    }

    HandType HighCard::getHandType() const {
        return TWO_PAIR;
    }
}
