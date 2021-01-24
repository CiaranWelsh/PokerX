
#include <iostream>
#include <PokerX/engine/NextStreet.h>
#include "PokerX/engine/EndStreet.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void EndStreet::enter(StateMachine *machine) {
        std::cout << "Entering StreetEnd" << std::endl;
    }

    void EndStreet::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        IGameVariables *variables = engine->getGameVariables();

        engine->setState(NextStreet::getInstance());
    }

    void EndStreet::exit(StateMachine *machine) {}

    EndStreet &EndStreet::getInstance() {
        static EndStreet singleton;
        return singleton;
    }

    unsigned int EndStreet::getType() const {
        return END_STREET_STATE;
    }
}