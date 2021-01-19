
#include <iostream>
#include "PokerX/engine/Raise.h"
#include "PokerX/engine/Preflop.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Raise::enter(StateMachine *machine) {
        std::cout << "Entering Raise" << std::endl;

    }

    void Raise::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(Preflop::getInstance());
    }

    void Raise::exit(StateMachine *machine) {}

    Raise &Raise::getInstance() {
        static Raise singleton;
        return singleton;
    }

    unsigned int Raise::getType() const {
        return RAISE;
    }
}
