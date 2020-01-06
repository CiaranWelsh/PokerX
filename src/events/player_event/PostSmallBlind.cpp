//
// Created by CiaranWelsh on 04/01/2020.
//

#include "PostSmallBlind.h"
#include "players/ActionType.h"

namespace events {

    std::string PostSmallBlind::getId() {
        return id;
    }

    bool PostSmallBlind::getDone() {
        return done;
    }

    std::string PostSmallBlind::getDescription() {
        return description;
    }

    TargetType PostSmallBlind::getTarget() {
        return target;
    }

    void PostSmallBlind::go(game::GamePlay &gamePlay, game::PlayerPtr &player) {
        player->play(Raise, gamePlay.small_blind);
    }
}