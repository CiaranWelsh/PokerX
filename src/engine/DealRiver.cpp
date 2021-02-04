
#include <iostream>
#include "PokerX/engine/DealRiver.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void DealRiver::enter(StateMachine *machine) {
        std::cout << "Entering DealRiver" << std::endl;
    }

    void DealRiver::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // liskov wouldn't be happy with this
        engine->dealRiver();
        machine->setState(EnterStreet::getInstance());
    }

    void DealRiver::exit(StateMachine *machine) {}

    DealRiver &DealRiver::getInstance() {
        static DealRiver singleton;
        return singleton;
    }

    unsigned int DealRiver::getType() const {
        return DEAL_RIVER_STATE;
    }
}