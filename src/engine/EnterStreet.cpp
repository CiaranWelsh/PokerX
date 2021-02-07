
#include <iostream>
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void EnterStreet::enter(StateMachine *machine) {

    }

    void EnterStreet::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // we reset the number of actions for each player still in the game
        for (const auto& player: *engine->getPlayers()){
            // this logic is hard to visualise - so storing it in a variable helps for looking with debugger
            bool truth = !player->hasFolded() && !player->isSittingOut();
            if (truth){
                player->setNumActionsThisStreet(0);
            }
        }
        engine->setState(PlayerToAct::getInstance());
    }

    void EnterStreet::exit(StateMachine *machine) {}

    EnterStreet &EnterStreet::getInstance() {
        static EnterStreet singleton;
        return singleton;
    }

    unsigned int EnterStreet::getType() const {
        return START_STREET_STATE;
    }
}
