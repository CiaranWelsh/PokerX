//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/CallStationPlayer.h>

#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::CallStationPlayer::selectAction(StateMachine *engine) {
        return CALL; // policy.next_action()???
    }

    float pokerx::CallStationPlayer::raise() {
        // call station never raises.
        // raise anyway for testing
        float amount = gameVariables_->getAmountToCall() * 2;
        return amount;

    }

}












