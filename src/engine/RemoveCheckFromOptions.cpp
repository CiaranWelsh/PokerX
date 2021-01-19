
#include <iostream>
#include "PokerX/engine/RemoveCheckFromOptions.h"
#include "PokerX/engine/Preflop.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void RemoveCheckFromOptions::enter(StateMachine *machine) {
        std::cout << "Entering RemoveCheckFromOptions" << std::endl;

    }

    void RemoveCheckFromOptions::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(Preflop::getInstance());
    }

    void RemoveCheckFromOptions::exit(StateMachine *machine) {}

    RemoveCheckFromOptions &RemoveCheckFromOptions::getInstance() {
        static RemoveCheckFromOptions singleton;
        return singleton;
    }

    unsigned int RemoveCheckFromOptions::getType() const {
        return REMOVE_CHECK_FROM_OPTIONS;
    }
}
