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
    private:
        TargetType target = None;
        std::string id = "Event";
        std::string description = "Base event class";
        bool done = false;
    public:
        virtual ~Event();

        Event();

        virtual TargetType getTarget();

        virtual std::string getDescription();

        virtual bool getDone();

        virtual std::string getId();

        virtual void go(game::GamePlay &gamePlay);

    };


}

#endif //POKERSIMULATIONSINCPP_EVENT_H
