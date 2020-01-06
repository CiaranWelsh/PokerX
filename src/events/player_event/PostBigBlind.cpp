//
// Created by CiaranWelsh on 04/01/2020.
//

#include "PostBigBlind.h"
#include "players/ActionType.h"

namespace events {

    void PostBigBlind::go(game::GamePlay &gamePlay, game::PlayerPtr &player) {
        player->play(Raise, gamePlay.big_blind);
    }

    TargetType PostBigBlind::getTarget() {
        return target;
    }

    std::string PostBigBlind::getDescription() {
        return description;
    }

    bool PostBigBlind::getDone() {
        return done;
    }

    std::string PostBigBlind::getId() {
        return id;
    }
}