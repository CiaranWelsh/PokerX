//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_CONSOLEPLAYER_H
#define POKERSIMULATIONSINCPP_CONSOLEPLAYER_H



#include "Player.h"
#include "Action.h"
#include "PokerEngine.h"

namespace pokerx {
    class ConsolePlayer : public Player {
    public:
        using Player::Player;

        Action selectAction(StateMachine *engine) override;


    };
}

#endif //POKERSIMULATIONSINCPP_CONSOLEPLAYER_H
