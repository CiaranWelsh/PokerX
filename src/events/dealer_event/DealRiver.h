//
// Created by CiaranWelsh on 08/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_DEALRIVER_H
#define POKERSIMULATIONSINCPP_DEALRIVER_H


#include "DealerEvent.h"

namespace events {
    class DealRiver : public DealerEvent {
    public:
        DealRiver() {
            target = Dealer;
            id = "DealHoleCards";
            description = "Deal hole cards";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;

    };

}


#endif //POKERSIMULATIONSINCPP_DEALRIVER_H
