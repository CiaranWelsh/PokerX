//
// Created by Ciaran Welsh on 02/02/2021.
//

#include "PokerX/engine/PolicyPlayer.h"


namespace pokerx {

    Action pokerx::PolicyPlayer::selectAction(StateMachine *engine) {
        return getPolicy()->nextAction();
    }

    float pokerx::PolicyPlayer::raise() {
        float amount = getPolicy()->getNextRaiseAmount();
        doRaise(amount);
        return amount;
    }


}