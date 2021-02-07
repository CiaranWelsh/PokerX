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


TEST_F(DeckTests, CheckCopyConstructor) {
    Deck deck1;
    Deck deck2(deck1);
    ASSERT_EQ(deck1, deck2);
    ASSERT_NE(&deck1, &deck2);
    auto* card1 = (MockCard*) deck1[0];
    auto* card2 = (MockCard*) deck2[0];
    ASSERT_EQ(*card1, *card2);
    ASSERT_NE(card1, card2);
}

TEST_F(DeckTests, CheckCopyAssignmentOp) {
    Deck deck1;
    Deck deck2 = deck1;
    ASSERT_EQ(deck1, deck2);
    ASSERT_NE(&deck1, &deck2);
    auto* card1 = (MockCard*) deck1[0];
    auto* card2 = (MockCard*) deck2[0];
    ASSERT_EQ(*card1, *card2);
    ASSERT_NE(card1, card2);
}

TEST_F(DeckTests, CheckThatWeHave52Cards) {
    Deck deck;
    int actual = deck.size();
    int expected = 52;
    ASSERT_EQ(expected, actual);
}

TEST_F(DeckTests, TestGetFirstCardInDeck) {
    Deck deck;
    auto* card = new MockCard(4, "S");
    ASSERT_THROW(deck.add(card), std::logic_error);
    delete card;
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





























