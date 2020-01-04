//
// Created by CiaranWelsh on 04/01/2020.
//

#include "PostBigBlind.h"
#include "players/ActionType.h"

namespace events {

    void PostBigBlind::go(game::Table &table, game::PlayerPtr player) {
        double big_blind_amount = table.getBigBlind();
        player->play(Raise, big_blind_amount);
    };
}