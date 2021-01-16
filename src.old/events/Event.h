//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_EVENT_H
#define POKERSIMULATIONSINCPP_EVENT_H

#include <iostream>
#include "game/Dealer.h"
#include "game/GamePlay.h"

namespace events {

    enum TargetType {
        Dealer, Table, None, Players, GamePlay
    };


    class Event {
    protected:
        TargetType target = None;
        bool done = false;
        std::string description = "Base event class";
        std::string id = "Event";
    public:
        virtual ~Event();

        Event();

        virtual TargetType getTarget();

        virtual std::string getDescription();

        virtual bool getDone();

        virtual std::string getId();

        /*
         * A go method for time_events
         */
        virtual void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                        double &amount_to_call);

    };

}

#endif //POKERSIMULATIONSINCPP_EVENT_H
