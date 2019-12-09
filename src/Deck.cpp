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
    int sizeOfRanks = sizeof(ranks) / sizeof(int);
    int sizeOfSuits = sizeof(suits) / sizeof(char);
    for (int r = 2; r < sizeOfRanks + 2; r++) {
        for (int s = 0; s < sizeOfSuits; s++) {
            Card card = Card(r, this->suits[s]);
            deck.push_back(card);
        }
    }
    return deck;
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

int Deck::len() {
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