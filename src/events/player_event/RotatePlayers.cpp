//
// Created by CiaranWelsh on 04/01/2020.
//

#include <dshow.h>
#include "RotatePlayers.h"

namespace events {

    void RotatePlayers::go(game::Players &players) {
        players.rotate();
    }

    TargetType RotatePlayers::getTarget() {
        return target;
    }

    std::string RotatePlayers::getDescription() {
        return description;
    }

    bool RotatePlayers::getDone() {
        return done;
    }

    std::string RotatePlayers::getId() {
        return id;
    }

}
