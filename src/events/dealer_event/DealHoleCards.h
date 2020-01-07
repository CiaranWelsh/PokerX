//
// Created by CiaranWelsh on 06/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_DEALHOLECARDS_H
#define POKERSIMULATIONSINCPP_DEALHOLECARDS_H

#include "DealerEvent.h"

namespace events {
    class DealHoleCards : public DealerEvent {
    public:
        DealHoleCards() {
            target = Dealer;
            id = "DealHoleCards";
            description = "Deal hole cards";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) override;

    };

}


#endif //POKERSIMULATIONSINCPP_DEALHOLECARDS_H
