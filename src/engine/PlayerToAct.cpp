
#include <iostream>
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/Error.h"

namespace pokerx {

    void PlayerToAct::enter(StateMachine *machine) {


    }

    void PlayerToAct::action(StateMachine *machine) {

        // downcast to the poker engine
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get reference to currently active player
        SharedIPlayerPtr player = engine->getPlayers()->getCurrentPlayer();

        // select action using whatever strategy Player types define
        Action action = player->selectAction(machine);

        // when all players are all in or all but one player are all in,
        // then all actions automatically become "check".
        // BUT implementing this way also ignores final CALL that needs to happen
//        if (engine->getPlayers()->numPlayersAllIn() == (engine->getPlayers()->getNumPlayersStillInPot() - 1) ||
//            engine->getPlayers()->numPlayersAllIn() == engine->getPlayers()->getNumPlayersStillInPot()) {
//            action = CHECK;
//        }

/*
 * Hold on this is the wrong strategy. When a player is all in there are lots of scenarios that
 * can occur:
 *  - all players are all in
 *  - all but 1 players are all in
 *  - going to have to look up the rules for all in and pot splitting.
 *  - might be a good idea to do a different test and come back to all in once the
 *    simulator is more robust in the rest of the game
 */
        if (action == NONE) {
            LOGIC_ERROR << "Cannot chooses NONE action when its a players turn to act" << std::endl;
        }

        switch (action) {
            case CHECK : {
                // check *is available when you are big blind and
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
                std::cout << player->getName() << ": calls "
                          << player->getGameVariables()->getCurrencySymbol()
                          << player->getGameVariables()->getAmountToCall()
                             - player->getAmountContrib() << std::endl;
                player->call();
                engine->getGameVariables()->setBetPlaced(true);
                break;
            }

            case RAISE : {

                float amountToRaiseTo = player->raise();
                // if no one has bet yet is "bets", if someone already bet then its raises
                if (engine->getGameVariables()->hasBetBeenPlaced()) {
                    std::cout << player->getName() << ": raises "
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
                float raiseAmount = player->getStack();
                float callAmount = engine->getGameVariables()->getAmountToCall();
                player->allIn();

                if (engine->getGameVariables()->hasBetBeenPlaced()) {
                    std::cout << player->getName() << ": raises "
                              << callAmount  << " to "
                              << raiseAmount << " and is all in" << std::endl;
                } else {
                    std::cout << player->getName() << ": bets "
                              << raiseAmount << " and is all in" << std::endl;
                    engine->getGameVariables()->setBetPlaced(true);
                }
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
        //PokerEngine::nextPlayer(machine);
    }

    PlayerToAct &PlayerToAct::getInstance() {
        static PlayerToAct singleton;
        return singleton;
    }

    unsigned int PlayerToAct::getType() const {
        return PLAYER_TO_ACT_STATE;
    }
}
