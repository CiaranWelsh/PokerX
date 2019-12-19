//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

using namespace eval;


TEST(HandTests, test1) {
    Deck deck;
    CardCollection cc = deck.pop(5);
    CommunityCards communityCards(cc);

    CardCollection hc = deck.pop(2);
    HoleCards holeCards(hc);

    HighCard hand(holeCards, communityCards);
    cout << hand.getCards() << endl;
    hand.shuffle();
    cout << hand.getCards() << endl;
    hand.best5();
    cout << hand.getCards() << endl;
//    cout << hand << endl;


//    std::string expected = "Hole cards: [Card(3H), Card(3D)]\n"
//               "Community cards: [Card(2S), Card(2H), Card(2D), Card(2C), Card(3S)]";
//    ostringstream  actual;
//    actual << hand;
//    ASSERT_EQ(expected, actual.str());
}















