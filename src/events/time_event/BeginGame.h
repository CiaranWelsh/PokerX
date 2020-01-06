//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_BEGINGAME_H
#define POKERSIMULATIONSINCPP_BEGINGAME_H

#include <string>
#include <iostream>
#include "TimeEvent.h"
#include "events/Event.h"

namespace events {

    class BeginGame : public TimeEvent {
    public:
        BeginGame() {
            id = "BeginGame";
            target = GamePlay;
            description = "This event marks the start of a game, i.e. before preflop.";
            done = false;
        }
        void go(game::GamePlay &gamePlay, game::PlayerPtr &current_player, game::Dealer &dealer) override;
    };
}

#endif //POKERSIMULATIONSINCPP_BEGINGAME_H
