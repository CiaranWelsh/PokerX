//
// Created by CiaranWelsh on 04/01/2020.
//

#include <dshow.h>
#include "RotatePlayers.h"

namespace events {

    void RotatePlayers::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer, double &amount_to_call) {
        players.rotate();

    }
}
