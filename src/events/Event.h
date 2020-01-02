//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_EVENT_H
#define POKERSIMULATIONSINCPP_EVENT_H

#include <iostream>
//#include "game/Table.h"
#include "players/Player.h"

namespace events {

    class Event {
    private:
        std::string target = "dealer";
        std::string description = "Base event class";
        bool done = false;
    public:
        ~Event();

        Event();

        std::string getTarget();

        std::string getDescription();

        bool getDone();

        virtual void go() = 0;

//        virtual void go(Table &table);
    };
}

#endif //POKERSIMULATIONSINCPP_EVENT_H
