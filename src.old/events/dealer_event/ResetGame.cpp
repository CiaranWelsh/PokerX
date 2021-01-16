//
// Created by CiaranWelsh on 14/01/2020.
//

#include "ResetGame.h"

void events::ResetGame::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer, double &amount_to_call) {
    gamePlay.pot.value = 0;
    for (auto player: players)
        player->pot = 0;
}
