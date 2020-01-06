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

        virtual void go(game::GamePlay &gamePlay, game::PlayerPtr &player) {};

    };
}

#endif //POKERSIMULATIONSINCPP_PLAYEREVENT_H
