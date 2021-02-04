//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/SequencePlayer.h>
#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::SequencePlayer::selectAction(StateMachine *engine) {
        return RAISE;
    }
//    Action pokerx::SequencePlayer::selectAction(StateMachine *engine, std::vector<Action>& actions) {
//        Action action = actions[0];
//        actions.erase(actions[0]);
//        return action;
//    }

    float pokerx::SequencePlayer::raise() {
        float amount = gameVariables_->getAmountToCall()*2;

        doRaise(amount);
        return amount;

    }

}












