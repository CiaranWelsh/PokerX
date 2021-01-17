//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/Showdown.h"



#include <iostream>
#include "PokerX/engine/Showdown.h"
#include "PokerX/engine/Reset.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Showdown::enter(StateMachine *machine) {
        std::cout << "Entering Showdown" << std::endl;

    }

    void Showdown::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(Reset::getInstance());
    }

    void Showdown::exit(StateMachine *machine) {}

    Showdown &Showdown::getInstance() {
        static Showdown singleton;
        return singleton;
    }

    unsigned int Showdown::getType() const {
        return SHOWDOWN;
    }
}

