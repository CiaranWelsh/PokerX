//
// Created by CiaranWelsh on 18/12/2019.
//
#include "gtest/gtest.h"
#include "card/Card.h"
#include "eval/Hand.h"
#include "card/Deck.h"


TEST(CommCardTests, CommCardsTests) {
    Deck deck = Deck();
    deck.sort();

    Card card1 = deck.pop();
    Card card2 = deck.pop();
    Card card3 = deck.pop();
    Card card4 = deck.pop();
    Card card5 = deck.pop();
    CommunityCards comm = CommunityCards(
            card1, card2, card3);
    std::cout << comm << std::endl;
    ASSERT_TRUE(comm[0].rank == 2);
}

TEST(CommCardTests, CommCardsTestsTurn) {
    Deck deck = Deck();
    deck.sort();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    Card card3 = deck.pop();
    Card card4 = deck.pop();
    CommunityCards comm = CommunityCards(
            card1, card2, card3, card4);
    ASSERT_TRUE(card1.rank == 2);
}


