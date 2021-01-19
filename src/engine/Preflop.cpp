//
// Created by Ciaran on 17/01/2021.
//

#include <iostream>
#include "PokerX/engine/Preflop.h"
#include "PokerX/engine/Flop.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Preflop::enter(StateMachine *machine) {
        std::cout << "Entering Preflop" << std::endl;

    }

    void Preflop::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // inner state machine for round of betting.



        engine->setState(Flop::getInstance());
    }

    void Preflop::exit(StateMachine *machine) {}

    Preflop &Preflop::getInstance() {
        static Preflop singleton;
        return singleton;
    }

    unsigned int Preflop::getType() const {
        return PREFLOP_STATE;
    }
}

