
#include <iostream>
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/Error.h"

namespace pokerx {

    void PlayerToAct::enter(StateMachine *machine) {
        std::cout << "Entering TurnToAct" << std::endl;

    }

    void PlayerToAct::action(StateMachine *machine) {

        // downcast to the poker engine
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        
        // get reference to currently active player
        SharedPlayerPtr player = engine->getPlayers()->getCurrentPlayer();
        
        // select action using whatever strategy Player types define
        Action action = player->selectAction(machine);

        if (action == NONE) {
            LOGIC_ERROR << "Cannot chooses NONE action when its a players turn to act" << std::endl;
        }

        /**
         * We could remove several of the states by implement the
         * logic of actions here, instead of their own state. Try that
         */
        switch (action) {
            case CHECK : {
                player->check();
                break;
            }
            
            case FOLD : {
                player->fold();
                break;
            }

            case CALL : {
                player->call();
                engine->getGameVariables()->setCheckAvailable(false);
                break;
            }

            case RAISE : {
                player->raise();
                engine->getGameVariables()->setCheckAvailable(false);
                break;
            }

            case ALL_IN : {
                player->allIn();
                engine->getGameVariables()->setCheckAvailable(false);
                break;
            }
            default:
                LOGIC_ERROR << "Shouldn't ever get here" << std::endl;
        }

        engine->setState(AllPlayersEqual::getInstance());

    }

    void PlayerToAct::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    PlayerToAct &PlayerToAct::getInstance() {
        static PlayerToAct singleton;
        return singleton;
    }

    unsigned int PlayerToAct::getType() const {
        return PLAYER_TO_ACT_STATE;
    }
}
