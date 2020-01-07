//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_DEALEREVENT_H
#define POKERSIMULATIONSINCPP_DEALEREVENT_H

#include "events/Event.h"


namespace events {
    class DealerEvent : public Event {
    public:
        DealerEvent() {
            target = Dealer;
            description = "Events that the dealer must carry out";
            done = false;
            id = "DealerEvent";
        }

        using Event::Event;

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) override;

    };
}


#endif //POKERSIMULATIONSINCPP_DEALEREVENT_H
