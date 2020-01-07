//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_NEXTPLAYER_H
#define POKERSIMULATIONSINCPP_NEXTPLAYER_H

#include "PlayerEvent.h"
#include "game/Players.h"

namespace events {
    class NextPlayer : public PlayerEvent {
    public:
        NextPlayer() {
            id = "NextPlayer";
            target = Players;
            done = false;
            description = "Move to the next player that is in the game ";

        }

        using PlayerEvent::Event;

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) override {};


    };
}

#endif //POKERSIMULATIONSINCPP_NEXTPLAYER_H
