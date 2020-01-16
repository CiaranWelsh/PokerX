//
// Created by CiaranWelsh on 04/01/2020.
//

#include "PostBigBlind.h"
#include "players/ActionType.h"

namespace events {

    void PostBigBlind::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                          double &amount_to_call) {
        players.getCurrentPlayer()->play(gamePlay, Raise, gamePlay.big_blind);
        /*
         * after the blinds we need to move our pointer back to the small blind
         * Since the small blind is always dealt first.
         */
        players.previous_player();
    }
}