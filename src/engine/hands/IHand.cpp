//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/IHand.h"

namespace pokerx {

    bool IHand::operator==(const IHand& hand) {
        if (getHandType() == hand.getHandType()) {
            // we have two of the same type
        }
        return false;
    }

    bool IHand::operator!=(const IHand &hand) {

        return false;
    }

    bool IHand::operator>(const IHand &hand) {

        return false;
    }


    bool IHand::operator<(const IHand &hand) {

        return false;
    }

}































