
#include <iostream>
#include "PokerX/engine/DealHoleCards.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void DealHoleCards::enter(StateMachine *machine) {
        std::cout << "Entering StreetEnd" << std::endl;
    }

    void DealHoleCards::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // liskov wouldn't be happy with this
        engine->dealHoleCards();
        machine->setState(EnterStreet::getInstance());
    }

    void DealHoleCards::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    DealHoleCards &DealHoleCards::getInstance() {
        static DealHoleCards singleton;
        return singleton;
    }

    unsigned int DealHoleCards::getType() const {
        return DEAL_HOLE_CARDS_STATE;
    }
}