//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PokerX/engine/Deck.h"
#include "Mockups/MockCard.h"

class DeckTests : public ::testing::Test {
public:

    DeckTests() = default;
};


TEST_F(DeckTests, CheckThatWeHave52Cards) {
    Deck deck;
    int actual = deck.size();
    int expected = 52;
    ASSERT_EQ(expected, actual);
}

TEST_F(DeckTests, TestGetFirstCardInDeck) {
    Deck deck;
    ASSERT_THROW(deck.add({"4S"}), std::logic_error);
}

TEST_F(DeckTests, TestCreateNewDeck) {
    Deck deck;
    ASSERT_EQ(52, deck.size());
    Deck deck2;
    deck = deck2;
    ASSERT_EQ(52, deck2.size());
}

TEST_F(DeckTests, TestResetCards) {
    Deck deck;
    ASSERT_EQ(52, deck.size());
    deck.pop(5);
    ASSERT_EQ(47, deck.size());
    deck.reset();
    ASSERT_EQ(52, deck.size());
}





























