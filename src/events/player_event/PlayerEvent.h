//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_PLAYEREVENT_H
#define POKERSIMULATIONSINCPP_PLAYEREVENT_H

#include "events/Event.h"
#include "players/Player.h"

namespace events {
    class PlayerEvent : public Event {
    private:
        TargetType target = None;
        std::string description = "Events relating to players";
        std::string id = "PlayerEvent";
        bool done = false;
    public:
        using Event::Event;

        TargetType getTarget() override;

        std::string getDescription() override;

        bool getDone() override;

        std::string getId() override ;

        virtual void go(game::GamePlay &gamePlay, game::PlayerPtr &player) {};


//        virtual void go(game::Players &players) = 0;
//
//        virtual void go(Player* player) = 0;
    };
}

#endif //POKERSIMULATIONSINCPP_PLAYEREVENT_H
