//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_PLAYEREVENT_H
#define POKERSIMULATIONSINCPP_PLAYEREVENT_H

#include "events/Event.h"
#include "players/Player.h"

namespace events {
    class PlayerEvent : public Event {
    public:
        PlayerEvent() {
            target = None;
            description = "Events relating to players";
            id = "PlayerEvent";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override {};

    };
}

#endif //POKERSIMULATIONSINCPP_PLAYEREVENT_H
