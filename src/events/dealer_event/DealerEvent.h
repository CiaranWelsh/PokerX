//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_DEALEREVENT_H
#define POKERSIMULATIONSINCPP_DEALEREVENT_H

#include "events/Event.h"


namespace events {
    class DealerEvent : public Event {
    private:
        TargetType target = Dealer;
        std::string description = "Events that the dealer must carry out";
    public:
        using Event::Event;

        virtual void go(game::Dealer &dealer);

    };
}


#endif //POKERSIMULATIONSINCPP_DEALEREVENT_H