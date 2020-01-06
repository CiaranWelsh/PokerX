//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_TIMEEVENT_H
#define POKERSIMULATIONSINCPP_TIMEEVENT_H

#include "events/Event.h"

namespace events {
    class TimeEvent : public Event {
    private:
        TargetType target = None;
        std::string id = "TimeEvent";
        std::string description = "Superclass of events related to time landmarks of Texas holdem poker.";
        bool done = false;
    public:
        using Event::Event;

        TargetType getTarget() override;

        std::string getDescription() override;

        bool getDone() override;

        std::string getId() override;

        void go(game::GamePlay &gamePlay) override {};

    };
}


#endif //POKERSIMULATIONSINCPP_TIMEEVENT_H
