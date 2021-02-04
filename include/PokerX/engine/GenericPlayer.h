//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_GenericPlayer_H
#define POKERSIMULATIONSINCPP_GenericPlayer_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"

namespace pokerx {
    class GenericPlayer : public Player {
    public:
        using Player::Player;

        ~GenericPlayer() override = default;

        Action selectAction(StateMachine *engine) override;

        float raise() override;


    };
}

#endif //POKERSIMULATIONSINCPP_GenericPlayer_H
