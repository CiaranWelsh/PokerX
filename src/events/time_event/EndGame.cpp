//
// Created by CiaranWelsh on 06/01/2020.
//

#include "EndGame.h"

namespace events {


    void EndGame::go(game::GamePlay &gamePlay) {
        gamePlay.game_ended = true;
    }


    TargetType EndGame::getTarget() {
        return target;
    }

    std::string EndGame::getDescription() {
        return description;
    }

    bool EndGame::getDone() {
        return done;
    }

    std::string EndGame::getId() {
        return id;
    }

}
