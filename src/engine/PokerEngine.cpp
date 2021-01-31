//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/Evaluator.h>
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/Reset.h"
#include "PokerX/Error.h"
#include "PokerX/Error.h"

namespace pokerx {

    PokerEngine::PokerEngine(IPlayerManager *playerManager, IGameVariables *variables)
            : StateMachine(&Reset::getInstance()), players_(playerManager), gameVariables_(variables) {

        CHECK_NULLPTR(playerManager, "playerManager");
        CHECK_NULLPTR(variables, "variables");

        // All players subscribe to the IGameVariables instance
        // in order to observe the game play
        playerManager->watch(gameVariables_);
    }


    void PokerEngine::setState(State &state) {
        // When we initially enter the setState method we
        // can use the enter method to do stuff
        // with our existing state
        state_->enter(this);

        // we then set the new state
        state_ = &state;

        // And we get a chance to do stuff to this new state immediately after switching
        state_->exit(this);

        // enter and exit are by default empty
    }

    void PokerEngine::action() {
        state_->action(this);
    }

    void PokerEngine::action(unsigned int times) {
        for (int i = 0; i < times; i++) {
            state_->action(this);
        }
    }

    void PokerEngine::reset() {
        gameVariables_->getPot().reset();
    }

    IGameVariables *PokerEngine::getGameVariables() const {
        return gameVariables_;
    }

    IPlayerManager *PokerEngine::getPlayers() const {
        return players_;
    }

    void PokerEngine::bind(IPlayerManager *manager) {
        CHECK_NULLPTR(manager->getCurrentPlayer(), "IPlayerManager::getCurrentPlayer()");
        players_ = manager;
    }

    void PokerEngine::bind(IGameVariables *gameVariables) {
        gameVariables_ = gameVariables;
    }

    void PokerEngine::nextPlayer(StateMachine *machine) {
        CHECK_NULLPTR(machine, "StateMachine");
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        engine->getPlayers()->nextPlayer();
    }

    void PokerEngine::dealHoleCards() const {
        // get a reference to the deck
        Deck& deck = getGameVariables()->getDeck();

        // We shuffle the deck. This is the only time we do so
        deck.shuffle();

        // Start left of dealer i.e. the button
        int current_player = 1; // Start left of dealer (btn)
        int number_of_players = getPlayers()->size();

        for (int i = 0; i < number_of_players * 2; i++) {
            // todo implement logic for a player to be sitting out here
            getPlayers()->getCurrentPlayer()->getHoleCards().add(deck.pop());
        }
    }

    void PokerEngine::dealFlop() {
        // get a reference to the deck
        Deck& deck = getGameVariables()->getDeck();

        // discard top card
        deck.pop();

        gameVariables_->getCommunityCards().add(deck.pop());
        gameVariables_->getCommunityCards().add(deck.pop());
        gameVariables_->getCommunityCards().add(deck.pop());

    }

    void PokerEngine::dealTurn() {
        Deck& deck = getGameVariables()->getDeck();

        // discard top card
        deck.pop();

        gameVariables_->getCommunityCards().add(deck.pop());

    }

    void PokerEngine::dealRiver() {
        Deck& deck = getGameVariables()->getDeck();

        // discard top card
        deck.pop();

        gameVariables_->getCommunityCards().add(deck.pop());
    }

    void PokerEngine::determineWinner() {
        Evaluator eval;
        eval.evaluate(players_->getPlayerHands());
    }

}