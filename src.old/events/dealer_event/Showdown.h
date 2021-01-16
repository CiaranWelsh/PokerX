//
// Created by CiaranWelsh on 12/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_SHOWDOWN_H
#define POKERSIMULATIONSINCPP_SHOWDOWN_H


#include "DealerEvent.h"

namespace events {
    class Showdown : public DealerEvent {
    public:
        Showdown() {
            target = Dealer;
            id = "Showdown";
            description = "Evaluate cards and determine winner";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;
    };

}


#endif //POKERSIMULATIONSINCPP_SHOWDOWN_H
