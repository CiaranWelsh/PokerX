
#include <iostream>
#include "PokerX/engine/EndStreet.h"
#include "PokerX/engine/StartStreet.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void EndStreet::enter(StateMachine *machine) {
        std::cout << "Entering StreetEnd" << std::endl;

    }

    void EndStreet::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        GameVariables variables = engine->getGameVariables().getStreet();

        switch (variables.getStreet()) {
            case PREFLOP_STREET:
                variables.setStreet(FLOP_STREET);
                // then start another round of betting
                engine->setState(StartStreet::getInstance());
                break;
            case FLOP_STREET:
                variables.setStreet(TURN_STREET);
                // then start another round of betting
                engine->setState(StartStreet::getInstance());
                break;
            case TURN_STREET:
                variables.setStreet(RIVER_STREET);
                // then start another round of betting
                engine->setState(StartStreet::getInstance());
                break;
            case RIVER_STREET:
                variables.setStreet(SHOWDOWN_STREET);
                // then start another round of betting
                engine->setState(StartStreet::getInstance());
                break;
            case SHOWDOWN_STREET:
                variables.setStreet(PREFLOP_STREET);
                // This is were we invoke the hand evaluator and declare winner
                // todo figure out hand evaluator code and put it here.
                break;
        }
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