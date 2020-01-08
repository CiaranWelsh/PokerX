//
// Created by CiaranWelsh on 07/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_NEXTSTREET_H
#define POKERSIMULATIONSINCPP_NEXTSTREET_H

#include "TimeEvent.h"

namespace events {

    class NextStreet : public TimeEvent {
    public:
        NextStreet() {
            id = "NextStreet";
            target = GamePlay;
            description = "Transition to the next street.";
            done = false;
        }
        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;
    };
}


#endif //POKERSIMULATIONSINCPP_NEXTSTREET_H
