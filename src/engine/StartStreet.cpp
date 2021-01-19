
#include <iostream>
#include "PokerX/engine/StartStreet.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void StartStreet::enter(StateMachine *machine) {
        std::cout << "Entering StartStreet" << std::endl;

    }

    void StartStreet::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(PlayerToAct::getInstance());
    }

    void StartStreet::exit(StateMachine *machine) {}

    StartStreet &StartStreet::getInstance() {
        static StartStreet singleton;
        return singleton;
    }

    unsigned int StartStreet::getType() const {
        return START_STREET_STATE;
    }
}
