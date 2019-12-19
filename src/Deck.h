//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_DECK_H
#define POKERSIMULATIONSINCPP_DECK_H

#include "Card.h"
#include <vector>
#include "CardCollection.h"
using namespace cards;


class Deck : public CardCollection {
public:
    Deck();
    ~Deck();
    explicit Deck(vector<cards::Card> &cards);
};


#endif //POKERSIMULATIONSINCPP_DECK_H
