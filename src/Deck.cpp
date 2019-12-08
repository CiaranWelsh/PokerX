//
// Created by CiaranWelsh on 08/12/2019.
//

#include "Deck.h"

#include <algorithm>
#include <random>


Deck::Deck() {
    int sizeOfRanks = sizeof(ranks) / sizeof(int);
    int sizeOfSuits = sizeof(suits) / sizeof(char);
    for (int r = 0; r < sizeOfRanks; r++) {
        for (int s = 0; s < sizeOfSuits; s++) {
            Card card = Card(r, s);
            deck.push_back(card);
        }
    }
    // shuffle

}

Deck Deck::shuffle() {
    std::random_device rd;
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(deck), std::end(deck), rng);

    return Deck();
}

