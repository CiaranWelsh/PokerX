//
// Created by Ciaran on 10/01/2021.
//

#include "PokerX/engine/ButtonMoves.h"
#include "PokerX/engine/SmallBlind.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/Error.h"
#include <iostream>

namespace pokerx {

    void ButtonMoves::enter(StateMachine *machine) {
        /**
         * Todo, implement a StateObserver for logging
         * the game.
         */
        std::cout << "Entering ButtonMoves" << std::endl;
    }

    void ButtonMoves::action(StateMachine *machine) {
        CHECK_NULLPTR(machine, "StateMachine");
        // cast down to PokerEngine
        // problem: liskov substitution principle violated because StateMachine superclass
        // of PokerEngine does not have a PlayerManager
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        IPlayerManager *manager = engine->getPlayers();
        CHECK_NULLPTR(manager->getCurrentPlayer(), "PlayerManager::getCurrentPlayer");

        std::cout << "Player btn was: " << *manager->getCurrentPlayer() << std::endl;

        manager->moveButton();

        std::cout << "Player btn is now: " << *manager->getCurrentPlayer() << std::endl;

        engine->setState(SmallBlind::getInstance());
    }

    void ButtonMoves::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    unsigned int ButtonMoves::getType() const {
        return BUTTON_MOVES_STATE;
    }

    ButtonMoves &ButtonMoves::getInstance() {
        static ButtonMoves singleton;
        return singleton;
    }
}







