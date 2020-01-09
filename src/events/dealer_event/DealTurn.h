//
// Created by CiaranWelsh on 08/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_DEALTURN_H
#define POKERSIMULATIONSINCPP_DEALTURN_H


#include "DealerEvent.h"

namespace events {
    class DealTurn : public DealerEvent {
    public:
        DealTurn() {
            target = Dealer;
            id = "DealHoleCards";
            description = "Deal hole cards";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;

    };

}


#endif //POKERSIMULATIONSINCPP_DEALTURN_H
