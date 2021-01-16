//
// Created by Ciaran on 10/01/2021.
//

#include <iostream>
#include "PokerX/engine/SmallBlind.h"
#include "PokerX/engine/BigBlind.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eState.h"

namespace pokerx {

    void SmallBlind::enter(StateMachine *machine) {
        std::cout << "Entering SmallBlind" << std::endl;
    }

    void SmallBlind::action(StateMachine *machine) {

//        auto* engine = dynamic_cast<PokerEngine*>(machine);

        machine->setState(BigBlind::getInstance());
    }

    void SmallBlind::exit(StateMachine *machine) {}

    SmallBlind &SmallBlind::getInstance() {
        static SmallBlind singleton;
        return singleton;
    }

    unsigned int SmallBlind::getType() const {
        return SMALL_BLIND;
    }
}