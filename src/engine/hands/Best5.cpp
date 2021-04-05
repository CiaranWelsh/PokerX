//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/Best5.h"


namespace pokerx {

    Best5::Best5(const std::vector<ICardPtr> &cards)
            : RestrictedCardCollection(cards, 5) {}

}