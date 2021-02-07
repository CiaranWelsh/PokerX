
#include <iostream>
#include "PokerX/engine/DealHoleCards.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void DealHoleCards::enter(StateMachine *machine) {

    }

    void DealHoleCards::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // liskov wouldn't be happy with this (nerd)
        std::cout << "*** HOLE CARDS ***" << std::endl;
        engine->dealHoleCards();
        machine->setState(EnterStreet::getInstance());
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