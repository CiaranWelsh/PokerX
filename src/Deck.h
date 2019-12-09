//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_DECK_H
#define POKERSIMULATIONSINCPP_DECK_H

#include "Card.h"
#include <vector>

using namespace Game;


class Deck {
private:

    int ranks[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    char suits[4] = {'S', 'H', 'D', 'H'};
    std::vector<Game::Card> deck;
    vector <Card> buildDeck();
public:
    Deck();
    Deck* shuffle();
    friend std::ostream &operator<<(std::ostream &os, const Deck &d);
    int len();
    Card pop();
};


#endif //POKERSIMULATIONSINCPP_DECK_H
