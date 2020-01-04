//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_PLAYEREVENT_H
#define POKERSIMULATIONSINCPP_PLAYEREVENT_H
#include "events/Event.h"
#include "players/Player.h"

namespace events {
    class PlayerEvent : public Event{
    private:
        TargetType target = None;
        std::string description = "Events relating to players";
    public:
        using Event::Event;

//        virtual void go(game::Players &players) = 0;
//
//        virtual void go(Player* player) = 0;
    };
}

#endif //POKERSIMULATIONSINCPP_PLAYEREVENT_H
