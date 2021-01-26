//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/FullHouse.h"
#include "PokerX/engine/hands/Pair.h"
#include "PokerX/engine/hands/ThreeOfAKind.h"
#include "PokerX/engine/hands/FullHouse.h"
#include "PokerX/engine/CardCollection.h"
#include "PokerX/Error.h"

namespace pokerx {

    bool FullHouse::isA() const {
        //check if pair
        Pair pair(cards_);
        ThreeOfAKind three_of_a_kind(cards_);
        return pair.isA() && three_of_a_kind.isA();
    }

std::shared_ptr<CardCollection> FullHouse::getBestFive() const {
    CardCollection cc(cards_);
    Counter<int> count(cc.getRanks());
    int theThree = 0, theTwo = 0;
    for (auto[rank, count]: count.count()) {
        if (count == 2)
            theTwo = rank;
        else if (count == 3)
            theThree = rank;
    }
    CardCollection best5;
    for (auto i : cards_) {
        if (i->getRank() == theThree || i->getRank() == theThree)
            best5.add(i);
    }
    if (best5.size() != 5)
        LOGIC_ERROR << "The best 5 cards do not have 5 cards in the "
                       "CardCollection" << std::endl;

    return std::make_shared<CardCollection>(best5);

}

HandType FullHouse::getHandType() const {
    return FULL_HOUSE;
}

int FullHouse::getValue() {
    value_ = getValueOfXOfAKind(3);
    return value_;
}

}
