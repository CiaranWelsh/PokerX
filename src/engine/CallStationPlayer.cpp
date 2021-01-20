//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/CallStationPlayer.h>

#include "PokerX/engine/Action.h"

namespace pokerx {

    Action pokerx::CallStationPlayer::selectAction(StateMachine *engine) {
        return CALL;
    }

    float pokerx::CallStationPlayer::raise() {
        // call station never raises.
        // violates interface segregation rule
        return 0;
    }
}
