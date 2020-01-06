//
// Created by CiaranWelsh on 06/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_ENDGAME_H
#define POKERSIMULATIONSINCPP_ENDGAME_H

#include "iostream"
#include "TimeEvent.h"

namespace events {
    class EndGame : public TimeEvent {
    public:
        EndGame() {
            id = "BeginGame";
            target = GamePlay;
            description = "This event marks the start of a game, i.e. before preflop.";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::PlayerPtr &player) override;

    };
}

#endif //POKERSIMULATIONSINCPP_ENDGAME_H
