//
// Created by Ciaran Welsh on 02/02/2021.
//

#include "PokerX/engine/PolicyPlayer.h"


namespace pokerx {

    Action pokerx::PolicyPlayer::selectAction(StateMachine *engine) {
        Policy p= getPolicy();
        return p.nextAction();
    }

    float pokerx::PolicyPlayer::raise() {
        float amount = gameVariables_->getAmountToCall() * 3;
        doRaise(amount);
        return amount;
    }


}