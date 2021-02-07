
#include <iostream>
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/engine/NextStreet.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void AllPlayersEqual::enter(StateMachine *machine) {

    }


    void AllPlayersEqual::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get reference to the Player manager
        IPlayerManager *playerManager = engine->getPlayers();

        bool all_players_equal = playerManager->allPlayersEqual();
        bool allPlayersPlayedAtLeastOneActionThisRound = playerManager->allPlayersTakenAtLeastOneTurn();

        if (all_players_equal && allPlayersPlayedAtLeastOneActionThisRound) {
            // if all players are equal
            // and everyone has played an action (including check) then we move on to next street
            engine->setState(NextStreet::getInstance());
        } else {
            // otherwise we go get the next player
            engine->getPlayers()->nextPlayer();
            engine->setState(PlayerToAct::getInstance());
        }
    }

    void AllPlayersEqual::exit(StateMachine *machine) {}

    AllPlayersEqual &AllPlayersEqual::getInstance() {
        static AllPlayersEqual singleton;
        return singleton;
    }

    unsigned int AllPlayersEqual::getType() const {
        return ALL_PLAYERS_EQUAL_STATE;
    }
}