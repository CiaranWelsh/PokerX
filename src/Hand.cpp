//
// Created by CiaranWelsh on 08/12/2019.
//

#include <vector>
#include "Hand.h"
#include "iostream"

using namespace std;

namespace Game {
    Hand::~Hand() = default;

    Hand::Hand(const Game::Hand &hand) = default;

//    Hand Hand::evaluate() {
//        return Hand(std::tuple(), std::tuple());
//    }

//    HoleCards::HoleCards() {
//
//    }

    CommunityCards::CommunityCards(std::vector<Card> &cards) {
        {
//            cout << *flop1 << endl;
            std::vector<Card*> order{flop1, flop2, flop3, turn, river};
            for (int i = 0; i < cards.size(); i++) {
                Card card = cards[i];
                order[i] = &card;
            }
//            cout << flop1->suit << endl;
        }
    }

    CommunityCards::CommunityCards(Card *card1, Card *card2, Card *card3) :
            flop1(card1),
            flop2(card2),
            flop3(card3) {}

    CommunityCards::CommunityCards(Card *card1, Card *card2, Card *card3, Card *card4) :
            flop1(card1),
            flop2(card2),
            flop3(card3),
            turn(card4) {}

    CommunityCards::CommunityCards(Card *card1, Card *card2, Card *card3, Card *card4, Card *card5) :
            flop1(card1),
            flop2(card2),
            flop3(card3),
            turn(card4),
            river(card5) {};

    Hand::Hand(HoleCards holeCards, CommunityCards communityCards) :
                _holeCards(holeCards),
                _communityCards(communityCards) {}

    std::vector<Card> Hand::getCards() {
        std::vector<Card> cards {_holeCards.card1, _holeCards.card2};
        cout << this->_communityCards.turn;
        return cards;
    }

//    PlayerCards::PlayerCards() {}



}




