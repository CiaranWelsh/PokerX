//
// Created by CiaranWelsh on 04/01/2020.
//

#include <dshow.h>
#include "PostSmallBlind.h"
#include "players/ActionType.h"

namespace events {

    void PostSmallBlind::go(game::Table &table, const game::PlayerPtr &player) {
        double small_blind_amount = table.getSmallBlind();
        player->play(Raise, small_blind_amount);
    };


}