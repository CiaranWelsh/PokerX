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
            id = "EndGame";
            target = GamePlay;
            description = "This event marks the end of a game.";
            done = true;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;

    };
}

#endif //POKERSIMULATIONSINCPP_ENDGAME_H
