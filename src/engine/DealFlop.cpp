
#include <iostream>
#include "PokerX/engine/DealFlop.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void DealFlop::enter(StateMachine *machine) {

    }

    void DealFlop::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // liskov wouldn't be happy with this
        CardCollection flop = engine->dealFlop();
        std::cout << "*** FLOP *** " << flop << std::endl;
        engine->getGameVariables()->setCommunityCards(flop);
        machine->setState(EnterStreet::getInstance());
    }

    void DealFlop::exit(StateMachine *machine) {}

    DealFlop &DealFlop::getInstance() {
        static DealFlop singleton;
        return singleton;
    }

    unsigned int DealFlop::getType() const {
        return DEAL_FLOP_STATE;
    }
}