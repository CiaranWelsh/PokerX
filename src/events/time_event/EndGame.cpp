//
// Created by CiaranWelsh on 06/01/2020.
//

#include "EndGame.h"

namespace events {

    void EndGame::go(game::GamePlay &gamePlay, game::PlayerPtr &current_player, game::Dealer &dealer) {
        gamePlay.game_ended = true;
    }

}
