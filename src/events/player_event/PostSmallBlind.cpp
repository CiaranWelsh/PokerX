//
// Created by CiaranWelsh on 04/01/2020.
//

#include "PostSmallBlind.h"
#include "players/ActionType.h"

namespace events {

    void PostSmallBlind::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
        players.getCurrentPlayer()->play(Raise, gamePlay.small_blind);
        players.next_player();
        gamePlay.small_blind_posted = true;
    }
}