//
// Created by CiaranWelsh on 08/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_DEALFLOP_H
#define POKERSIMULATIONSINCPP_DEALFLOP_H


#include "DealerEvent.h"

namespace events {
    class DealFlop : public DealerEvent {
    public:
        DealFlop() {
            target = Dealer;
            id = "DealHoleCards";
            description = "Deal hole cards";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;

    };

}


#endif //POKERSIMULATIONSINCPP_DEALFLOP_H
