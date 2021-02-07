//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/Flop.h"


#include <iostream>
#include "PokerX/engine/Flop.h"
#include "PokerX/engine/Turn.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Flop::enter(StateMachine *machine) {


    }

    void Flop::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(Turn::getInstance());
    }

    void Flop::exit(StateMachine *machine) {}

    Flop &Flop::getInstance() {
        static Flop singleton;
        return singleton;
    }

    unsigned int Flop::getType() const {
        return FLOP_STATE;
    }
}

