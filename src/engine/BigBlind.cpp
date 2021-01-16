//
// Created by Ciaran on 16/01/2021.
//

#include <iostream>
#include "PokerX/engine/BigBlind.h"
#include "PokerX/engine/BigBlind.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eState.h"

namespace pokerx {

    void BigBlind::enter(StateMachine *machine) {
        std::cout << "Entering BigBlind" << std::endl;

    }

    void BigBlind::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

//        engine->setState(BigBlind::getInstance());
    }

    void BigBlind::exit(StateMachine *machine) {}

    BigBlind &BigBlind::getInstance() {
        static BigBlind singleton;
        return singleton;
    }

    unsigned int BigBlind::getType() const {
        return BIG_BLIND;
    }
}