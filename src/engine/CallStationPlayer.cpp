//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/CallStationPlayer.h>

#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::CallStationPlayer::selectAction(StateMachine *engine) {
        return CALL;
    }

    void pokerx::CallStationPlayer::raise() {
        // call station never raises.
        // raise anyway for testing
        float amount = gameVariables_->getAmountToCall()*2;
        gameVariables_->getPot() += amount;
        stack_ -= amount;
    }

}












