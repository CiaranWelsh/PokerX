//
// Created by Ciaran on 18/01/2021.
//


#include <iostream>
#include <PokerX/engine/PlayerManager.h>
#include "PokerX/engine/Call.h"
#include "PokerX/engine/RemoveCheckFromOptions.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Call::enter(StateMachine *machine) {
        std::cout << "Entering Call" << std::endl;

    }

    void Call::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get a reference to the currently active player
        IPlayerManager *playerManager = engine->getPlayers();

        const SharedPlayerPtr &player = playerManager->getCurrentPlayer();

        // amount is taken care of automatically by the observer mechanism
        // in place between players and gameVariable
        player->call();

        engine->setState(RemoveCheckFromOptions::getInstance());
    }

    void Call::exit(StateMachine *machine) {}

    Call &Call::getInstance() {
        static Call singleton;
        return singleton;
    }

    unsigned int Call::getType() const {
        return CALL;
    }
}
