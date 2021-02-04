
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
                std::cout << player->getName() << ": checks" << std::endl;
                break;
            }
            
            case FOLD : {
                player->fold();
                std::cout << player->getName() << ": folds" << std::endl;
                break;
            }

            case CALL : {
                // todo need to add amount called to players amountContrib attribute
                // todo check available and bet placed actually indicate the same things. Consolidate.
                player->call();
//                engine->getGameVariables()->setCheckAvailable(false);
                engine->getGameVariables()->setBetPlaced(true);
                std::cout << player->getName() << ": calls" << std::endl;
                break;
            }

            case RAISE : {

                // make riase return amount to raise to and implement the loic i need here
                float amountToRaiseTo = player->raise();
//                engine->getGameVariables()->setCheckAvailable(false);
                // if no one has bet yet is "bets", if someone already bet then its raises
                if (engine->getGameVariables()->hasBetBeenPlaced()) {
                    std::cout << player->getName() << ": raises "
                              << player->getGameVariables()->getAmountToCall() << " to "
                              << amountToRaiseTo << std::endl;
                } else {
                    std::cout << player->getName() << ": bets "
                              << amountToRaiseTo << std::endl;
                }
                // and update the amount to call to the amount raised
                player->getGameVariables()->setAmountToCall(amountToRaiseTo);
                engine->getGameVariables()->setBetPlaced(true);
                break;
            }

            case ALL_IN : {
                player->allIn();

                if (engine->getGameVariables()->hasBetBeenPlaced()) {
                    std::cout << player->getName() << ": raises "
                              << player->getGameVariables()->getAmountToCall() << " to "
                              << player->getStack() << std::endl;
                } else {
                    std::cout << player->getName() << ": bets "
                              << player->getStack() << std::endl;
                }

                engine->getGameVariables()->setBetPlaced(true);
                std::cout << player->getName() << ": raises " << std::endl; // and is all-in
                break;
            }
            default:
                LOGIC_ERROR << "Shouldn't ever get here" << std::endl;
            case NONE:
                break;
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
