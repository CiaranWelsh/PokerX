/**
 * Project PokerSimulationsInCpp
 */


#include "Dealer.h"
#include "cards/Card.h"
#include "cards/CardCollection.h"
#include "cards/CommunityCards.h"

/**
 * Dealer implementation
 */

namespace game {

    Dealer::Dealer(Dealer &dealer) {}

    Dealer::Dealer() = default;

    void Dealer::dealHoleCards(Players &players) {
        // dealer discards the top card
        deck.pop();

        for (int i=0; i<2; i++) {
            for (const PlayerPtr& player: players) {
                player->holeCards.add(deck.pop());
            }
        }
    }

    Card Dealer::dealCard() {
        Card card = deck.pop();
        return card;
    }

    CardCollection Dealer::dealFlop() {
        CardCollection flop;
        deck.pop();
        flop.add(deck.pop());
        flop.add(deck.pop());
        flop.add(deck.pop());
        return flop;
    }

    Card Dealer::dealTurn() {
        deck.pop();
        return deck.pop();
    }

    Card Dealer::dealRiver() {
        deck.pop();
        return deck.pop();
    }

    void Dealer::shuffle() {
        deck.shuffle();
    }

    int Dealer::deckSize() {
        return deck.size();
    }

    Deck Dealer::getDeck() {
        return deck;
    }

}