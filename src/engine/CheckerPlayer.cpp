//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/CheckerPlayer.h>

#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::CheckerPlayer::selectAction(StateMachine *engine) {
        return CHECK;
    }

    float pokerx::CheckerPlayer::raise() {
        // call station never raises.
        // raise anyway for testing
        float amount = gameVariables_->getAmountToCall() * 2;
        gameVariables_->getPot() += amount;
        stack_ -= amount;
        return amount;
    }

}












