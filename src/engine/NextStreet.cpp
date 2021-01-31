
#include <iostream>
#include <PokerX/engine/Reset.h>
#include <PokerX/engine/DealFlop.h>
#include <PokerX/engine/DealTurn.h>
#include <PokerX/engine/DealRiver.h>
#include <PokerX/engine/Showdown.h>
#include "PokerX/engine/NextStreet.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void NextStreet::enter(StateMachine *machine) {
        std::cout << "Entering NextStreet" << std::endl;
    }

    void NextStreet::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        switch (engine->getGameVariables()->getStreet()) {
            case PREFLOP_STREET:
                engine->getPlayers()->resetAmountContribThisStreet();
                engine->getGameVariables()->setStreet(FLOP_STREET);
                engine->setState(DealFlop::getInstance());
                break;
            case FLOP_STREET:
                engine->getPlayers()->resetAmountContribThisStreet();
                engine->getGameVariables()->setStreet(TURN_STREET);
                engine->setState(DealTurn::getInstance());
                break;
            case TURN_STREET:
                engine->getPlayers()->resetAmountContribThisStreet();
                engine->getGameVariables()->setStreet(RIVER_STREET);
                engine->setState(DealRiver::getInstance());
                break;
            case RIVER_STREET:
                engine->getPlayers()->resetAmountContribThisStreet();
                engine->getGameVariables()->setStreet(SHOWDOWN_STREET);
                engine->setState(Showdown::getInstance());
                break;
            case SHOWDOWN_STREET:
                engine->setState(Reset::getInstance());
                break;
        }
    }

    void NextStreet::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    NextStreet &NextStreet::getInstance() {
        static NextStreet singleton;
        return singleton;
    }

    unsigned int NextStreet::getType() const {
        return NEXT_STREET_STATE;
    }
}
