//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/HighCard.h"

namespace pokerx {


    std::shared_ptr<CardCollection> HighCard::getBestFive() const {
        CardCollection cc(cards_);
        cc.sort();
        return std::make_shared<CardCollection>(cc(2, cc.size()));
    }

    bool HighCard::isA() const {
        return true;
    }

    HandType HighCard::getHandType() const {
        return HIGH_CARD;
    }

    int HighCard::getValue() {
        CardCollection cc(cards_);
        int max = 0;
        for (auto i: cc.getRanks()) {
            if (i > max)
                i = max;
        }
        setValue(max);
    }
}



