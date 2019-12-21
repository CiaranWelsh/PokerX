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


Deck::Deck() : CardCollection() {
    _cards = buildDeck();
};

Deck::Deck(vector<cards::Card> &cards) :
        CardCollection(cards) {}

Deck::~Deck() = default;
