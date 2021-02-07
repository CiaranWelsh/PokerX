
#include <iostream>
#include "PokerX/engine/DealRiver.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void DealRiver::enter(StateMachine *machine) {

    }

    void DealRiver::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        ICard* river = engine->dealRiver();
        std::cout << "*** RIVER *** " << *river << std::endl;
        CardCollection community = engine->getGameVariables()->getCommunityCards();
        community.add(river);

        engine->getGameVariables()->setCommunityCards(community);

        machine->setState(EnterStreet::getInstance());
    }

    void DealRiver::exit(StateMachine *machine) {}

    DealRiver &DealRiver::getInstance() {
        static DealRiver singleton;
        return singleton;
    }

    unsigned int DealRiver::getType() const {
        return DEAL_RIVER_STATE;
    }
}