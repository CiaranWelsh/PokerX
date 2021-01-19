
#include <iostream>
#include "PokerX/engine/Check.h"
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Check::enter(StateMachine *machine) {
        std::cout << "Entering Check" << std::endl;

    }

    void Check::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get a reference to the currently active player
        const PlayerManager &playerManager = engine->getPlayers();

        SharedPlayerPtr player = playerManager.getCurrentPlayer();

        // does nothing except throws an error if
        // GameVariables::checkAvailable = false
        player->check();

        engine->setState(AllPlayersEqual::getInstance());
    }

    void Check::exit(StateMachine *machine) {}

    Check &Check::getInstance() {
        static Check singleton;
        return singleton;
    }

    unsigned int Check::getType() const {
        return CHECK;
    }
}
