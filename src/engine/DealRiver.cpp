
#include <iostream>
#include "PokerX/engine/DealRiver.h"
#include "PokerX/engine/StreetStart.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void DealRiver::enter(StateMachine *machine) {

    }

    void DealRiver::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        ICardPtr river = engine->dealRiver();

        CardCollection community = engine->getGameVariables()->getCommunityCards();
        std::cout << "*** RIVER *** " << community << "  [" << *river << "]" << std::endl;
        community.add(river);

        engine->getGameVariables()->setCommunityCards(community);

        machine->setState(StreetStart::getInstance());
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