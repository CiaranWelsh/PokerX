
#include <iostream>
#include "PokerX/engine/Raise.h"
#include "PokerX/engine/RemoveCheckFromOptions.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Raise::enter(StateMachine *machine) {
        std::cout << "Entering Raise" << std::endl;

    }

    void Raise::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // access the players
        IPlayerManager *playerManager = engine->getPlayers();

        // get currently active player
        SharedPlayerPtr player = playerManager->getCurrentPlayer();

        // call the raise method
        player->raise();

        engine->setState(RemoveCheckFromOptions::getInstance());
    }

    void Raise::exit(StateMachine *machine) {}

    Raise &Raise::getInstance() {
        static Raise singleton;
        return singleton;
    }

    unsigned int Raise::getType() const {
        return RAISE;
    }
}
