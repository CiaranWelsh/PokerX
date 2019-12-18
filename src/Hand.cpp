//
// Created by CiaranWelsh on 08/12/2019.
//

#include <vector>
#include "Hand.h"
#include "iostream"
#include "CommunityCards.h"
#include "HoleCards.h"

using namespace std;

namespace Game {


    Hand::Hand(HoleCards &holeCards, CommunityCards &communityCards) {
        _holeCards = holeCards;
        _communityCards = communityCards;
    }

    Hand::~Hand() = default;

    Hand::Hand(const Hand &hand) {
        this->_holeCards = hand._holeCards;
    }

    std::vector<Card> Hand::getCards() {
        return std::vector<Card>();
    }

}




