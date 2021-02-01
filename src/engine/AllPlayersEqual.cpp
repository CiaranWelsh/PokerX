
#include <iostream>
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/engine/EndStreet.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void AllPlayersEqual::enter(StateMachine *machine) {
        std::cout << "Entering AllPlayersEqual" << std::endl;
    }

    void AllPlayersEqual::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get reference to the Player manager
        IPlayerManager *playerManager = engine->getPlayers();

        bool all_players_equal = playerManager->allPlayersEqual();

        if (all_players_equal){
            // if all players are equal we end the street
            engine->setState(EndStreet::getInstance());
        } else {
            // otherwise we go get the next player
            engine->setState(PlayerToAct::getInstance());
        }
    }

    void AllPlayersEqual::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    AllPlayersEqual &AllPlayersEqual::getInstance() {
        static AllPlayersEqual singleton;
        return singleton;
    }

    unsigned int AllPlayersEqual::getType() const {
        return ALL_PLAYERS_EQUAL_STATE;
    }
}