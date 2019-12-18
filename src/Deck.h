//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_DECK_H
#define POKERSIMULATIONSINCPP_DECK_H

#include "Card.h"
#include <vector>
#include "CardCollection.h"
using namespace Game;


class Deck : public CardCollection {
public:
    Deck();
    ~Deck();
    explicit Deck(vector<Game::Card> &cards);
    Deck * shuffle();
};


#endif //POKERSIMULATIONSINCPP_DECK_H
