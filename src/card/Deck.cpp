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
    cards_ = buildDeck();
    shuffle();
};

Deck::Deck(vector<cards::Card> &cards) :
        CardCollection(cards) {}

Deck::~Deck() = default;
