//
// Created by Ciaran on 16/01/2021.
//

#include <iostream>
#include <PokerX/engine/PokerEngine.h>
#include "PokerX/engine/Reset.h"
#include "PokerX/engine/ButtonMoves.h"

namespace pokerx{

    Reset& Reset::getInstance() {
        static Reset singleton;
        return singleton;
    }

    void Reset::action(StateMachine *machine) {
        machine->reset();
        machine->setState(ButtonMoves::getInstance());
    }

    void Reset::enter(StateMachine *machine) {
        std::cout << "Entering ResetState" << std::endl;
    }

    void Reset::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    unsigned int Reset::getType() const {
        return RESET_STATE;
    }

}

