//
// Created by Ciaran on 18/01/2021.
//


#include <iostream>
#include "PokerX/engine/Call.h"
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Call::enter(StateMachine *machine) {
        std::cout << "Entering Call" << std::endl;

    }

    void Call::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(AllPlayersEqual::getInstance());
    }

    void Call::exit(StateMachine *machine) {}

    Call &Call::getInstance() {
        static Call singleton;
        return singleton;
    }

    unsigned int Call::getType() const {
        return CALL;
    }
}
