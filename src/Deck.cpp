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

Deck *Deck::shuffle() {
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(std::begin(_cards), std::end(_cards), e);
    return this;
}

