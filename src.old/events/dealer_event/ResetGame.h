//
// Created by CiaranWelsh on 14/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_RESETGAME_H
#define POKERSIMULATIONSINCPP_RESETGAME_H


#include "DealerEvent.h"

namespace events {
    class ResetGame : public DealerEvent {
    public:
        ResetGame() {
            target = Dealer;
            id = "ResetGame";
            description = "Deal hole cards";
            done = false;
        }

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;

    };

}



#endif //POKERSIMULATIONSINCPP_RESETGAME_H
