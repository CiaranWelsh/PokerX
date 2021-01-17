//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/River.h"


#include <iostream>
#include "PokerX/engine/River.h"
#include "PokerX/engine/Showdown.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void River::enter(StateMachine *machine) {
        std::cout << "Entering River" << std::endl;

    }

    void River::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(Showdown::getInstance());
    }

    void River::exit(StateMachine *machine) {}

    River &River::getInstance() {
        static River singleton;
        return singleton;
    }

    unsigned int River::getType() const {
        return RIVER;
    }
}

