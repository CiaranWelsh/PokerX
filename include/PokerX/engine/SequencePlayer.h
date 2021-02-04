//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_SequencePlayer_H
#define POKERSIMULATIONSINCPP_SequencePlayer_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"

namespace pokerx {

    /**
     * What about a lambda func or callback?
     * I need a way for a player to do a sequence of things,
     * like raise then call. look at the find if algorithm. They have
     * a predicate argument which is a callable.
     */

    class SequencePlayer : public Player {
    public:
        using Player::Player;

        ~SequencePlayer() override = default;

        Action selectAction(StateMachine *engine) override;

        Action selectAction(StateMachine *engine, std::function)

        float raise() override;


    };
}

#endif //POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H
