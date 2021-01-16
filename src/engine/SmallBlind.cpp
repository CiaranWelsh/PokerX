//
// Created by Ciaran on 10/01/2021.
//

#include "SmallBlind.h"

namespace engine {

    void SmallBlind::enter(PokerEngine *engine) {}

    void SmallBlind::action(PokerEngine *engine) {

    }

    void SmallBlind::exit(PokerEngine *engine) {}

    PokerEngineState &SmallBlind::getInstance() {
        static SmallBlind singleton;
        return singleton;
    }
}