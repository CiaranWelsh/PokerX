
#include <iostream>
#include "PokerX/engine/BigBlind.h"
#include "PokerX/engine/Preflop.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void BigBlind::enter(StateMachine *machine) {
        std::cout << "Entering BigBlind" << std::endl;

    }

    void BigBlind::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(Preflop::getInstance());
    }

    void BigBlind::exit(StateMachine *machine) {}

    BigBlind &BigBlind::getInstance() {
        static BigBlind singleton;
        return singleton;
    }

    unsigned int BigBlind::getType() const {
        return BIG_BLIND;
    }
}
