
#include <iostream>
#include "PokerX/engine/EndStreet.h"
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void EndStreet::enter(StateMachine *machine) {
        std::cout << "Entering StreetEnd" << std::endl;

    }

    void EndStreet::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        engine->setState(AllPlayersEqual::getInstance());
    }

    void EndStreet::exit(StateMachine *machine) {}

    EndStreet &EndStreet::getInstance() {
        static EndStreet singleton;
        return singleton;
    }

    unsigned int EndStreet::getType() const {
        return CALL;
    }
}