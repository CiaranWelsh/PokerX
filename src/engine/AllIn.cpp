
#include <iostream>
#include "PokerX/engine/AllIn.h"
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void AllIn::enter(StateMachine *machine) {
        std::cout << "Entering AllIn" << std::endl;
    }

    void AllIn::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // access the players
        const IPlayerManager *playerManager = engine->getPlayers();

        // get currently active player
        const SharedPlayerPtr &player = playerManager->getCurrentPlayer();

        // call the allIn method
        player->allIn();

        engine->setState(AllPlayersEqual::getInstance());
    }

    void AllIn::exit(StateMachine *machine) {}

    AllIn &AllIn::getInstance() {
        static AllIn singleton;
        return singleton;
    }

    unsigned int AllIn::getType() const {
        return CALL;
    }
}