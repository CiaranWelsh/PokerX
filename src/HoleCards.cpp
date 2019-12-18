//
// Created by CiaranWelsh on 18/12/2019.
//

#include "HoleCards.h"

using namespace std;

namespace Game {

    HoleCards::HoleCards() : CardCollection() {};

    HoleCards::~HoleCards() {};

    HoleCards::HoleCards(Card &card1, Card &card2) : CardCollection() {
        this->add(card1);
        this->add(card2);
    }

    HoleCards::HoleCards(const HoleCards &holeCards) : CardCollection(holeCards) {
        this->_cards = holeCards._cards;
    }

    HoleCards::HoleCards(vector<Card> &container) : CardCollection(container) {}

    HoleCards::HoleCards(CardCollection container) {}


}