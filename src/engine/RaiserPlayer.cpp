//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/RaiserPlayer.h>

#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::RaiserPlayer::selectAction(StateMachine *engine) {
        return RAISE;
    }

    void pokerx::RaiserPlayer::raise() {
        float amount = gameVariables_->getAmountToCall()*2;
        gameVariables_->getPot() += amount;
        stack_ -= amount;
    }

}












