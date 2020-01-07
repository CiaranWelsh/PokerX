//
// Created by CiaranWelsh on 04/01/2020.
//

#include "NextPlayer.h"

namespace events {

    void go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
        players.next_player();
    };
}
