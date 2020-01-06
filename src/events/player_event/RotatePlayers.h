//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_ROTATEPLAYERS_H
#define POKERSIMULATIONSINCPP_ROTATEPLAYERS_H

#include "PlayerEvent.h"
#include "game/Players.h"

namespace events {
    class RotatePlayers : public PlayerEvent {
    public:
        RotatePlayers() {
            id = "RotatePlayers";
            target = Players;
            done = false;
            description = "Rotate players at the begining of each round to "
                                      "maintain fair positioning relative to the dealer";
        }

        void go(game::Players &players);
    };
}

#endif //POKERSIMULATIONSINCPP_ROTATEPLAYERS_H
