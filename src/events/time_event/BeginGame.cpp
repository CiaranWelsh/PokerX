//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/GamePlay.h>
#include "BeginGame.h"


namespace events {


    void BeginGame::go(game::GamePlay &gamePlay, game::PlayerPtr &current_player, game::Dealer &dealer) {
        gamePlay.game_started = true;
    }


}




