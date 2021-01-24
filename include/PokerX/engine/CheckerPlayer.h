//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_CheckerPlayer_H
#define POKERSIMULATIONSINCPP_CheckerPlayer_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"

namespace pokerx {
    class CheckerPlayer : public Player {
    public:
        using Player::Player;

        ~CheckerPlayer() override = default;

        Action selectAction(StateMachine *engine) override;

        void raise() override;


    };
}

#endif //POKERSIMULATIONSINCPP_CheckerPlayer_H
