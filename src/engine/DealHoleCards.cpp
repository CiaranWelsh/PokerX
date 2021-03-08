
#include <iostream>
#include "PokerX/engine/DealHoleCards.h"
#include "PokerX/engine/StreetStart.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void DealHoleCards::enter(StateMachine *machine) {

    }

    void DealHoleCards::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        std::cout << "*** HOLE CARDS ***" << std::endl;
        engine->dealHoleCards();
        machine->setState(StreetStart::getInstance());
    }

    void DealHoleCards::exit(StateMachine *machine) {}

    DealHoleCards &DealHoleCards::getInstance() {
        static DealHoleCards singleton;
        return singleton;
    }

    unsigned int DealHoleCards::getType() const {
        return DEAL_HOLE_CARDS_STATE;
    }
}