//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/AllInPlayer.h>

#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::AllInPlayer::selectAction(StateMachine *engine) {
        return ALL_IN;
    }

    float pokerx::AllInPlayer::raise() {
        // call station never raises.
        // raise anyway for testing
        float amount = gameVariables_->getAmountToCall() * 2;
        gameVariables_->getPot() += amount;
        stack_ -= amount;
        return amount;
    }

}












