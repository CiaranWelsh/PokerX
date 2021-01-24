
#include <iostream>
#include "PokerX/engine/DealHoleCards.h"
#include "PokerX/engine/StartStreet.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void DealHoleCards::enter(StateMachine *machine) {
        std::cout << "Entering StreetEnd" << std::endl;
    }

    void DealHoleCards::action(StateMachine *machine) {
        
    }

    void DealHoleCards::exit(StateMachine *machine) {}

    DealHoleCards &DealHoleCards::getInstance() {
        static DealHoleCards singleton;
        return singleton;
    }

    unsigned int DealHoleCards::getType() const {
        return END_STREET_STATE;
    }
}