//
// Created by CiaranWelsh on 04/01/2020.
//

#include "PostBigBlind.h"
#include "players/ActionType.h"

namespace events {

    void PostBigBlind::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
        players.getCurrentPlayer()->play(Raise, gamePlay.big_blind);
    }
}