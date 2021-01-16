//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H
#define POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H

#include "Player.h"
#include "Action.h"
#include "NoLimitHoldem.h"

namespace pokerx {
    class CallStationPlayer : public Player {
    public:
        using Player::Player;

        Action selectAction(PokerEngine* engine) override;


    };
}

#endif //POKERSIMULATIONSINCPP_CALLSTATIONPLAYER_H
