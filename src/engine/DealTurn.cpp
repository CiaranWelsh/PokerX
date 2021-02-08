
#include <iostream>
#include "PokerX/engine/DealTurn.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void DealTurn::enter(StateMachine *machine) {

    }

    void DealTurn::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);

        ICard *turn = engine->dealTurn();
        CardCollection community = engine->getGameVariables()->getCommunityCards();
        std::cout << "*** TURN *** " << community << "  [" << *turn << "]" << std::endl;
        community.add(turn);
        engine->getGameVariables()->setCommunityCards(community);
        machine->setState(EnterStreet::getInstance());
    }

    void DealTurn::exit(StateMachine *machine) {}

    DealTurn &DealTurn::getInstance() {
        static DealTurn singleton;
        return singleton;
    }

    unsigned int DealTurn::getType() const {
        return DEAL_TURN_STATE;
    }
}