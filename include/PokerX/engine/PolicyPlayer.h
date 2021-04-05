//
// Created by Ciaran Welsh on 02/02/2021.
//

#ifndef POKERX_POLICYPLAYER_H
#define POKERX_POLICYPLAYER_H


#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"
#include "Policy.h"

namespace pokerx {


    class PolicyPlayer : public Player {
    public:
        using Player::Player;

        ~PolicyPlayer() override = default;

        Action selectAction(StateMachine *engine) override;

        float raise() override;

    };

}

#endif //POKERX_POLICYPLAYER_H
