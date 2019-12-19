//
// Created by CiaranWelsh on 08/12/2019.
//

#include <vector>
#include "Hand.h"
#include "iostream"
#include "CommunityCards.h"
#include "HoleCards.h"

using namespace std;

namespace eval {


    Hand::Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) {
        _holeCards = holeCards;
        _communityCards = communityCards;
        _cards = holeCards + communityCards;
        // and sort the concatonated cards
        _cards.sort();
    }

    Hand::~Hand() = default;

    Hand::Hand(const Hand &hand) {
        this->_holeCards = hand._holeCards;
        this->_communityCards = hand._communityCards;
        this->_cards = hand._cards;
    }

    CommunityCards Hand::getCards() {
        return CommunityCards(_cards);
    }

    std::ostream &operator<<(std::ostream &os, const Hand &hand) {
        os << "Hole cards: " << hand._holeCards << "\nCommunity cards: " << hand._communityCards;
        return os;
    }

    void Hand::shuffle() {
        _cards.shuffle();
    }

    HighCard::HighCard(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {}

    CardCollection HighCard::best5() {
//        return CardCollection(_cards[0, 5]);
//    }

    /*
     * every hand is a high card hand
     */
    bool HighCard::isa() {
        return true;
    }
}




