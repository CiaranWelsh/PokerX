//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_POSTSMALLBLIND_H
#define POKERSIMULATIONSINCPP_POSTSMALLBLIND_H

#include "PlayerEvent.h"

namespace events {
    class PostSmallBlind : public PlayerEvent {
    public:
        PostSmallBlind() {
            target = Players;
            id = "PostSmallBlind";
            done = false;
            description = "Post the small blind";
        }

        void go(game::GamePlay &gamePlay, game::PlayerPtr &current_player, game::Dealer &dealer) override;

    };
}


#endif //POKERSIMULATIONSINCPP_POSTSMALLBLIND_H
