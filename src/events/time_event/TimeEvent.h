//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_TIMEEVENT_H
#define POKERSIMULATIONSINCPP_TIMEEVENT_H

#include "events/Event.h"

namespace events {
    class TimeEvent : public Event {
    public:
        TimeEvent() {
            target = None;
            id = "TimeEvent";
            description = "Superclass of events related to time landmarks of Texas holdem poker.";
            done = false;
        }

        virtual void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                        double &amount_to_call);

    };
}


#endif //POKERSIMULATIONSINCPP_TIMEEVENT_H
