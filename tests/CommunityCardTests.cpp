//
// Created by CiaranWelsh on 18/12/2019.
//
#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"


TEST(CommCardTests, CommCardsTests) {
    Deck deck = Deck();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    Card card3 = deck.pop();
    Card card4 = deck.pop();
    Card card5 = deck.pop();
    CommunityCards comm = CommunityCards(
            card1, card2, card3);
    Card expected = Card(2, "S");
    ASSERT_TRUE(comm[0] == expected);
}

TEST(CommCardTests, CommCardsTestsTurn) {
    Deck deck = Deck();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    Card card3 = deck.pop();
    Card card4 = deck.pop();
    CommunityCards comm = CommunityCards(
            card1, card2, card3, card4 );
    Card expected = Card(2, "S");
    cout << card1 << endl;
    ASSERT_TRUE(card1 == expected);
}


