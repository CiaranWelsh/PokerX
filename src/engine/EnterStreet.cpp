
#include <iostream>
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void EnterStreet::enter(StateMachine *machine) {
        std::cout << "Entering EnterStreet" << std::endl;
    }

    void EnterStreet::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        /**
         * Maybe this State isn't needed. Since it gives us options
         * to customize what happens depending on street later on
         * I'll leave it in for now. If this is not needed we can easily
         * remove
         */

        engine->setState(PlayerToAct::getInstance());
    }

    void EnterStreet::exit(StateMachine *machine) {}

    EnterStreet &EnterStreet::getInstance() {
        static EnterStreet singleton;
        return singleton;
    }

    unsigned int EnterStreet::getType() const {
        return START_STREET_STATE;
    }
}
