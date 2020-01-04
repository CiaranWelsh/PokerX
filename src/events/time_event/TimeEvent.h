//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_TIMEEVENT_H
#define POKERSIMULATIONSINCPP_TIMEEVENT_H

#include "events/Event.h"
#include "game/Table.h"

namespace events {
    class TimeEvent : public Event {
    private:
        TargetType target = None;
        std::string description = "Superclass of events related to time landmarks of Texas holdem poker.";

    public:
        using Event::Event;

        virtual void go();

        virtual void go(game::Table &table);
    };
}


#endif //POKERSIMULATIONSINCPP_TIMEEVENT_H
