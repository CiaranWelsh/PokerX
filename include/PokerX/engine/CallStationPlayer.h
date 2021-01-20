//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H
#define POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"

namespace pokerx {
    class CallStationPlayer : public Player {
    public:
        using Player::Player;

        Action selectAction(StateMachine *engine) override;

        float raise() override;


    };
}

#endif //POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H
