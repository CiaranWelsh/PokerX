//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/GamePlay.h>
#include <events/player_event/RotatePlayers.h>
#include "BeginGame.h"


namespace events {


    void BeginGame::go(game::GamePlay &gamePlay) {
        gamePlay.game_started = true;
    }


    TargetType BeginGame::getTarget() {
        return target;
    }

    std::string BeginGame::getDescription() {
        return description;
    }

    bool BeginGame::getDone() {
        return done;
    }

    std::string BeginGame::getId() {
        return id;
    }

}




