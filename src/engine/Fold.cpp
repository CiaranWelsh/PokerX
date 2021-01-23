
#include <iostream>
#include "PokerX/engine/Fold.h"
#include "PokerX/engine/Preflop.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Fold::enter(StateMachine *machine) {
        std::cout << "Entering Fold" << std::endl;

    }

    void Fold::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get a reference to the currently active player
        IPlayerManager *playerManager = engine->getPlayers();

        SharedPlayerPtr player = playerManager->getCurrentPlayer();

        player->fold();

        engine->setState(Preflop::getInstance());
    }

    void Fold::exit(StateMachine *machine) {}

    Fold &Fold::getInstance() {
        static Fold singleton;
        return singleton;
    }

    unsigned int Fold::getType() const {
        return FOLD;
    }
}
