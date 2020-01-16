//
// Created by CiaranWelsh on 06/01/2020.
//

#include "EndGame.h"

namespace events {

    void EndGame::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                     double &amount_to_call) {
        gamePlay.game_ended = true;
        gamePlay.game_started = false;
    }

}
