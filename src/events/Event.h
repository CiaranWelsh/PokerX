//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_EVENT_H
#define POKERSIMULATIONSINCPP_EVENT_H

#include <iostream>
#include "game/Table.h"
#include "players/Player.h"

namespace events {

    enum TargetType {
        Dealer, Table, None, Players
    };

    class Event {
    private:
        TargetType target = None;
        std::string description = "Base event class";
        bool done = false;
    public:
        ~Event();

        Event();

        TargetType getTarget();

        std::string getDescription();

        bool getDone();

    };
}

#endif //POKERSIMULATIONSINCPP_EVENT_H
