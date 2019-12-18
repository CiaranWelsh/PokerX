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
//    explicit Deck(int n): CardCollection(n){};
    Deck(): CardCollection(){
    this->_cards = buildDeck();
};
    ~Deck() = default;
    explicit Deck(vector<Game::Card> &cards): CardCollection(cards){};
    Deck * shuffle();
};


#endif //POKERSIMULATIONSINCPP_DECK_H
