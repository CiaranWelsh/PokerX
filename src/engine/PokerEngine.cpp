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

        // And we get a chance to do stuff to this new state immediately after switching
        // we use exit for moving to the next player, which
        // we only want to do after we have performed the action
        // this is different from the original state machine design
        // whereby exit was conducted after assigning state to state_ in setState().

        // also remember that we must call exit first since we'll be calling
        // exit on the last state before changing it.
        state_->exit(this);

        // we then set the new state
        state_ = &state;
        // When we initially enter the setState method we
        // can use the enter method to do stuff
        // with our existing state
        state_->enter(this);


        // enter and exit are by default empty
    }

    void PokerEngine::action() {
        // when its time to take player input we just call action, since we
        // only want to take one action set. Also at showdown we also only want to execute
        // showdown action
        if (state_->getType() == PLAYER_TO_ACT_STATE | state_->getType() == SHOWDOWN_STATE) {
            state_->action(this);
        }

        // otherwise we keep turning the wheel until its a players turn to act
        // so that users only see the player action states
        while ((state_->getType() != PLAYER_TO_ACT_STATE) && !gameVariables_->isDone()) {
            state_->action(this);
        }

    }

    void PokerEngine::action(unsigned int times) {
        for (int i = 0; i < times; i++) {
            state_->action(this);
        }
    }

    void PokerEngine::reset() {
        gameVariables_->reset();
        players_->reset();
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

        // todo inject way of controlling the cards for reproducing games

        // get a reference to the deck
        Deck &deck = getGameVariables()->getDeck();

        // We shuffle the deck. This is the only time we do so
        deck.shuffle();

        // Start left of dealer ( the button)
        int number_of_players = getPlayers()->size();

        for (int card_number = 0; card_number < 2; card_number++) {
            for (int i = 1; i < number_of_players + 1; i++) {
                int idx = i % number_of_players;
                const auto &player = getPlayers()->getPlayer(idx);
                auto card = deck.pop();
                player->getHoleCards().add(card);
            }
        }

    }

    CardCollection PokerEngine::dealFlop() {
        std::vector<ICardPtr> injCards = gameVariables_->getInjectedCommunityCards();
        // if we are reproducing some game then we just take the fist three cards for injected cards
        if (!injCards.empty()){
            // use copy constructor to slice the vector
            ICardPtr f1 = std::move(injCards.at(0));
            return CardCollection(f1);
        }
        // otherwise its a random selection

        // get a reference to the deck
        Deck &deck = getGameVariables()->getDeck();
        CardCollection community = gameVariables_->getCommunityCards();
        // discard top card
        deck.pop();

        community.add(deck.pop());
        community.add(deck.pop());
        community.add(deck.pop());
        return community;

    }

    ICardPtr PokerEngine::dealTurn() const {
        const std::vector<ICardPtr>& injCards = gameVariables_->getInjectedCommunityCards();
        // if we are reproducing some game then we just take the fist three cards for injected cards
        if (!injCards.empty()){
            ICardPtr ptr = std::move(injCards[3]);
            return ptr;
        }
        Deck &deck = getGameVariables()->getDeck();
        // discard top card
        deck.pop();

        return deck.pop();

    }

    ICardPtr PokerEngine::dealRiver() const {
        const std::vector<ICardPtr>& injCards = gameVariables_->getInjectedCommunityCards();
        // if we are reproducing some game then we just take the fist three cards for injected cards
        if (!injCards.empty()){
            return injCards[4];
        }
        Deck &deck = getGameVariables()->getDeck();
        // discard top card
        deck.pop();

        return deck.pop();

    }

    void PokerEngine::determineWinner() {
        Evaluator eval;
        auto[winnerIdx, hand] = eval.evaluate(players_->getPlayerHands());
        std::cout << "winner is " << winnerIdx << " with " << hand << std::endl;

    }

}



















