
#include <iostream>
#include <PokerX/engine/NextStreet.h>
#include "PokerX/engine/StreetStart.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void StreetStart::enter(StateMachine *machine) {

    }

    void StreetStart::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // we reset the number of actions for each player still in the game
        for (const auto &player: *engine->getPlayers()) {
            // this logic is hard to visualise - so storing it in a variable helps for looking with debugger
            bool truth = !player->hasFolded() && !player->isSittingOut();
            if (truth) {
                player->setNumActionsThisStreet(0);
                engine->getGameVariables()->setBetPlaced(false);
            }
        }
        // set the amount to call variable to 0 for start of all streets
        // except for PREFLOP when it is equal to big blind
        if (engine->getGameVariables()->getStreet() == PREFLOP_STREET) {
            engine->getGameVariables()->setAmountToCall(
                    engine->getGameVariables()->getBigBlind()
            );
        } else {
            engine->getGameVariables()->setAmountToCall(0);
        }

        // when conditions are right, i.e. all in, we go to Next street
        if (engine->getGameVariables()->allInMode()){
            engine->setState(NextStreet::getInstance());
        } else{
            engine->setState(PlayerToAct::getInstance());
        }

    }

    void StreetStart::exit(StateMachine *machine) {}

    StreetStart &StreetStart::getInstance() {
        static StreetStart singleton;
        return singleton;
    }

    unsigned int StreetStart::getType() const {
        return START_STREET_STATE;
    }
}
