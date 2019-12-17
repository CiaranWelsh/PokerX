//
// Created by CiaranWelsh on 08/12/2019.
//

#include "Deck.h"

#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <sstream>

using namespace std;

Deck::Deck() {
    this->buildDeck();
}

vector<Card> Deck::buildDeck() {
    std::vector<Card> cards;
    for (int r = 0; r < Game::RANKS.size(); r++) {
        for (int s = 0; s < Game::SUITS.size(); s++) {
            Card card = Card(Game::RANKS[r], Game::SUITS[s]);
            cards.push_back(card);
        }
    }
    return cards;
}

Deck *Deck::shuffle() {
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(std::begin(deck), std::end(deck), e);
    return this;
}

std::ostream &operator<<(std::ostream &os, const Deck &d) {
    os << "[";
    for (int i = 0; i < d.deck.size(); i++) {
        if (i == d.deck.size() - 1)
            os << d.deck[i] << "]";
        else
            os << d.deck[i] << ", ";
    }
    return os;
}

int Deck::size() {
    return deck.size();
}

/*
 * Remove top card (index 0) from deck
 * and return it
 */
Card Deck::pop() {
    Card card = deck[0];
    deck.erase(deck.begin());
    return card;
}

std::vector<Card>::iterator Deck::end() {
    return this->deck.end();
}

std::vector<Card>::iterator Deck::begin() {
    return this->deck.begin();
}

Card &Deck::operator[](int index) {
    return this->deck[index];
}
