//
// Created by Ciaran on 17/01/2021.
//


#include <iostream>
#include "PokerX/engine/Turn.h"
#include "PokerX/engine/River.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Turn::enter(StateMachine *machine) {


    }

    void Turn::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(River::getInstance());
    }

    void Turn::exit(StateMachine *machine) {}

    Turn &Turn::getInstance() {
        static Turn singleton;
        return singleton;
    }

    unsigned int Turn::getType() const {
        return TURN_STATE;
    }
}

