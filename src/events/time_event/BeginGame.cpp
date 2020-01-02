//
// Created by CiaranWelsh on 02/01/2020.
//

#include "BeginGame.h"
#include "game/Table.h"

namespace events {

    void BeginGame::go() {
        TimeEvent::go();
    }

    void BeginGame::go(game::Table& table) {
        table.reset();
        table.game_started = true;
    }
}