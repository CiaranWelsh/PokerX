//
// Created by Ciaran on 16/01/2021.
//

#include <iostream>
#include "PokerX/engine/ResetState.h"
#include "PokerX/engine/ButtonMoves.h"

namespace pokerx{

    ResetState& ResetState::getInstance() {
        static ResetState singleton;
        return singleton;
    }

    void ResetState::action(StateMachine *machine) {
        machine->reset();
        machine->setState(ButtonMoves::getInstance());
    }

    void ResetState::enter(StateMachine *machine) {
        std::cout << "Entering ResetState" << std::endl;
    }

    void ResetState::exit(StateMachine *machine) {}

    unsigned int ResetState::getType() const {
        return RESET;
    }

}

