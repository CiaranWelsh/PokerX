
#include <iostream>
#include "PokerX/engine/DealFlop.h"
#include "PokerX/engine/StartStreet.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void DealFlop::enter(StateMachine *machine) {
        std::cout << "Entering StreetEnd" << std::endl;
    }

    void DealFlop::action(StateMachine *machine) {
        
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