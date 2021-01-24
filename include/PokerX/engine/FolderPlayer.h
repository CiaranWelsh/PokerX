//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_FolderPlayer_H
#define POKERSIMULATIONSINCPP_FolderPlayer_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"

namespace pokerx {
    class FolderPlayer : public Player {
    public:
        using Player::Player;

        ~FolderPlayer() override = default;

        Action selectAction(StateMachine *engine) override;

        void raise() override;


    };
}

#endif //POKERSIMULATIONSINCPP_FolderPlayer_H
