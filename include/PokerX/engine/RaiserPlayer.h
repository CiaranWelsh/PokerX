//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_RAISERPLAYER_H
#define POKERSIMULATIONSINCPP_RAISERPLAYER_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"

namespace pokerx {
    class RaiserPlayer : public Player {
    public:
        using Player::Player;

        ~RaiserPlayer() override = default;

        Action selectAction(StateMachine *engine) override;

        float raise() override;

    };
}

#endif //POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H
