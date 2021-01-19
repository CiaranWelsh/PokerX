
#include <iostream>
#include "PokerX/engine/NextPlayer.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void NextPlayer::enter(StateMachine *machine) {
        std::cout << "Entering NextPlayer" << std::endl;

    }

    void NextPlayer::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get a reference to the player manager
        /**
         * Note possible bug. playerManager is a copy,
         * but getPlayers returns a const ref. So are
         * we calling rotate on the right player manager, or a copy?
         */
        PlayerManager playerManager = engine->getPlayers();

        playerManager.rotate();

        engine->setState(PlayerToAct::getInstance());
    }

    void NextPlayer::exit(StateMachine *machine) {}

    NextPlayer &NextPlayer::getInstance() {
        static NextPlayer singleton;
        return singleton;
    }

    unsigned int NextPlayer::getType() const {
        return NEXT_PLAYER;
    }
}
