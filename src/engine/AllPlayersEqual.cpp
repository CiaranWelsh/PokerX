
#include <iostream>
#include <PokerX/engine/Showdown.h>
#include "PokerX/engine/AllPlayersEqual.h"
#include "PokerX/engine/NextStreet.h"
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"

namespace pokerx {

    void AllPlayersEqual::enter(StateMachine *machine) {

    }


    void AllPlayersEqual::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);

        // get reference to the Player manager
        IPlayerManager *playerManager = engine->getPlayers();

        // if everyone else has folded we have a winner
        if (playerManager->getNumPlayersStillInPot() == 1) {
            engine->setState(Showdown::getInstance());
            return;
        }

        bool all_players_equal = playerManager->allPlayersEqual();
        bool allPlayersPlayedAtLeastOneActionThisRound = playerManager->allPlayersTakenAtLeastOneTurn();
        int numPlayersAllIn = playerManager->numPlayersAllIn();
        int numPlayersStillInPot = playerManager->getNumPlayersStillInPot();
        int numPlayersNotAllIn = numPlayersStillInPot - numPlayersAllIn;

        // if a player is all in and there is only one other player left and that other
        // player has called the all in
        // we deal the remaining community cards and head to showdown
        //todo implement player->getLastAction
        // Could implement observer for players to log the data produced?
        // or just store within a Player variable? ? ?

        // first deal with situation where all players are all in
        // or all but one players are all in
        if (numPlayersAllIn == numPlayersStillInPot || numPlayersAllIn == (numPlayersStillInPot-1)){
            engine->getGameVariables()->setAllInMode(true);
            engine->setState(NextStreet::getInstance());
            return;
        }

        // A side pot occurs in a game in which there are more than two players left in
        // the hand, and one player has bet all the chips they have in front of them (is all-in).
        // When one player is all-in, the other two may continue to bet between themselves.

        if ( (all_players_equal && allPlayersPlayedAtLeastOneActionThisRound) ) {
            // if all players are equal
            // and everyone has played an action (including check) then we move on to next street
            engine->setState(NextStreet::getInstance());
            // when we change street, we need to start again left of the dealer.
            // so we go to the dealer
            engine->getPlayers()->setCurrentPlayerByName(
                    engine->getPlayers()->getButton()->getName()
            );
            // and hit next player (which recursively bypasses players who are not in the game
            engine->getPlayers()->nextPlayer();

        } else {
            // otherwise we go get the next player
            engine->setState(PlayerToAct::getInstance());
            engine->getPlayers()->nextPlayer();
        }
    }

    void AllPlayersEqual::exit(StateMachine *machine) {}

    AllPlayersEqual &AllPlayersEqual::getInstance() {
        static AllPlayersEqual singleton;
        return singleton;
    }

    unsigned int AllPlayersEqual::getType() const {
        return ALL_PLAYERS_EQUAL_STATE;
    }
}