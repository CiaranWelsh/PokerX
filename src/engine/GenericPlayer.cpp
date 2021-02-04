//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/GenericPlayer.h>

#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::GenericPlayer::selectAction(StateMachine *engine) {
        return CALL;
    }

    float pokerx::GenericPlayer::raise() {
        // call station never raises.
        // raise anyway for testing
        float amount = gameVariables_->getAmountToCall()*2;
        std::cout << amount << std::endl;
        gameVariables_->getPot() += amount;
        stack_ -= amount;
        return amount;
    }

}












