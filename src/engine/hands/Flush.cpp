//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/Flush.h"

namespace pokerx {

    bool Flush::isA() const {
        CardCollection cc(cards_);
        Counter<std::string> count(cc.getSuits());
        bool x = false;
        for (auto[suit, count] : count.count()) {
            if (count >= 5)
                x = true;
        }
        return x;
    }

    std::shared_ptr<CardCollection> Flush::getBestFive() const {
        if (!isA())
            return std::make_shared<CardCollection>(CardCollection());
        CardCollection cc(cards_);
        Counter<std::string> count(cc.getSuits());
        CardCollection best5;
        std::string which_suit;
        for (const std::pair<const std::string, int> &i : count.count()) {
            if (i.second >= 5) {
                which_suit = i.first;
            }
        }
        for (auto card : cc) {
            if (card->getSuit() == which_suit)
                best5.add(card);
        }
        if (best5.size() > 5) {
            best5.sort();
            best5 = best5(best5.size() - 5, best5.size());
        }
        return std::make_shared<CardCollection>(best5);
    }

    HandType Flush::getHandType() const {
        return FLUSH;
    }

    int Flush::getValue() {
        SharedCardCollection cc = getBestFive();
        cc->sort();
        return (*cc)[cc->size() - 1]->getRank();
    }
}
