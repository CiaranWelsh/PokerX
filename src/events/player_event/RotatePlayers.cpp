//
// Created by CiaranWelsh on 04/01/2020.
//

#include <dshow.h>
#include "RotatePlayers.h"

namespace events {

    void RotatePlayers::go(game::Players &players) {
        players.rotate();
    }
}
