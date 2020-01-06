//
// Created by CiaranWelsh on 04/01/2020.
//

#include "PostSmallBlind.h"
#include "players/ActionType.h"

namespace events {

    void PostSmallBlind::go(game::GamePlay &gamePlay, game::PlayerPtr &current_player, game::Dealer &dealer) {
        current_player->play(Raise, gamePlay.small_blind);
    }
}