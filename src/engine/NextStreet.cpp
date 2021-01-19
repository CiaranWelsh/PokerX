
#include <iostream>
#include "PokerX/engine/NextStreet.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void NextStreet::enter(StateMachine *machine) {
        std::cout << "Entering NextStreet" << std::endl;

    }

    void NextStreet::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        switch (engine->getGameVariables().getStreet()) {
            case PREFLOP_STREET:
                engine->getGameVariables().setStreet(FLOP_STREET);
                engine->setState(PlayerToAct::getInstance());
                break;
            case FLOP_STREET:
                engine->getGameVariables().setStreet(TURN_STREET);
                engine->setState(PlayerToAct::getInstance());
                break;
            case TURN_STREET:
                engine->getGameVariables().setStreet(RIVER_STREET);
                engine->setState(PlayerToAct::getInstance());
                break;
            case RIVER_STREET:
                engine->getGameVariables().setStreet(SHOWDOWN_STREET);
                engine->setState(PlayerToAct::getInstance());
                break;
            case SHOWDOWN_STREET:
                engine->setState(::getInstance());
                break;
        }
    }

    void NextStreet::exit(StateMachine *machine) {}

    NextStreet &NextStreet::getInstance() {
        static NextStreet singleton;
        return singleton;
    }

    unsigned int NextStreet::getType() const {
        return NEXT_STREET_STATE;
    }
}
