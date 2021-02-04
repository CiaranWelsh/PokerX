//
// Created by Ciaran on 10/01/2021.
//

#include <iostream>
#include "PokerX/engine/SmallBlind.h"
#include "PokerX/engine/BigBlind.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"
#include "PokerX/Error.h"

namespace pokerx {

    void SmallBlind::enter(StateMachine *machine) {
        std::cout << "Entering SmallBlind" << std::endl;
    }

    void SmallBlind::action(StateMachine *machine) {
        CHECK_NULLPTR(machine, "StateMachine");
        auto* engine = dynamic_cast<PokerEngine*>(machine);
        CHECK_NULLPTR(engine, "engine");
        IPlayerManager* manager = engine->getPlayers();
        CHECK_NULLPTR(manager->getCurrentPlayer(), "playerManager::getCurrentPlayer");
        std::cout << manager->getCurrentPlayer()->getName() <<
            ": posts small blind " << engine->getGameVariables()->getCurrencySymbol()
            << engine->getGameVariables()->getSmallBlind()  << std::endl;
        manager->getCurrentPlayer()->postSmallBlind();
        machine->setState(BigBlind::getInstance());

    }

    void SmallBlind::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    SmallBlind &SmallBlind::getInstance() {
        static SmallBlind singleton;
        return singleton;
    }

    unsigned int SmallBlind::getType() const {
        return SMALL_BLIND_STATE;
    }
}