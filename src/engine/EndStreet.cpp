
#include <iostream>
#include <PokerX/engine/NextStreet.h>
#include "PokerX/engine/EndStreet.h"
#include "PokerX/engine/EnterStreet.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void EndStreet::enter(StateMachine *machine) {

    }

    void EndStreet::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        IGameVariables *variables = engine->getGameVariables();

        // if big blind has the same amount in the pot as everyone
        // else (i.e. everyone calls the big blind), then the big blind still needs
        // an opportunity to raise.
        // if street == PREFLOP && (big blind has not yet acted)
        // how can we indicate whether or not the bb has acted yet?
        // maybe this all players equal thing does not work? maybe instead
        // I should count the number of times a player has acted this street?
        // if all players have acted the same number of times --> next street
        // what about counting the number of calls. if the number of calls since the
        // last raise equals the number of players not folded or sitting out
        // minus 1 (for the raiser) we go to the next street.
        // but then what if everyone checks?
        // could just set a counter for player turns to act. player::numActionsThisStreet()
        // if bb == 0, give him a go.  // or sitting out folded all in?


        // we go directly from player action to end street, who determines
        // whether to go back to player to act or next street.
//        engine->getPlayers()->getPlayerTurnCounts()
//
//
//        engine->setState(NextStreet::getInstance());
    }

    void EndStreet::exit(StateMachine *machine) {}

    EndStreet &EndStreet::getInstance() {
        static EndStreet singleton;
        return singleton;
    }

    unsigned int EndStreet::getType() const {
        return END_STREET_STATE;
    }
}