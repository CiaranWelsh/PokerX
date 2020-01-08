//
// Created by CiaranWelsh on 07/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_PLAYERACTION_H
#define POKERSIMULATIONSINCPP_PLAYERACTION_H


#include "PlayerEvent.h"

namespace events {
    class PlayerAction : public PlayerEvent {
    public:
        PlayerAction() {
            id = "PlayerAction";
            target = Players;
            done = false;
            description = "Player chooses to check, fold, call or raise.";
        }

        using PlayerEvent::Event;

        void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                double &amount_to_call) override;


    };
}


#endif //POKERSIMULATIONSINCPP_PLAYERACTION_H
