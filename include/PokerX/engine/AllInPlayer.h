//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_AllInPlayer_H
#define POKERSIMULATIONSINCPP_AllInPlayer_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"

namespace pokerx {
    class AllInPlayer : public Player {
    public:
        using Player::Player;

        ~AllInPlayer() override = default;

        Action selectAction(StateMachine *engine) override;

        float raise() override;


    };
}

#endif //POKERSIMULATIONSINCPP_AllInPlayer_H
