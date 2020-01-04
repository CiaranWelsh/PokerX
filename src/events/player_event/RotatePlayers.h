//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_ROTATEPLAYERS_H
#define POKERSIMULATIONSINCPP_ROTATEPLAYERS_H

#include "PlayerEvent.h"

namespace events {
    class RotatePlayers : public PlayerEvent {
    private:
        std::string description = "Rotate players at the begining of each round to "
                                  "maintain fair positioning relative to the dealer";
    public:
        using PlayerEvent::Event;

        void go(game::Players &players);

        void go(Player *player);

    };
}

#endif //POKERSIMULATIONSINCPP_ROTATEPLAYERS_H
