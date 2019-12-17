//
// Created by CiaranWelsh on 16/12/2019.
//
#include "gtest/gtest.h"
#include "Card.h"
#include "Deck.h"
#include "CardCollection.h"

#include <boost/random/uniform_int.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <chrono>

using namespace Game;
TEST(CardCollectionTests, NoArgConstructor) {
    Card fourOfHearts1 = Card(4, "H");
    CardCollection cards;
    cards.add(fourOfHearts1);
    ostringstream actual;
    actual << cards;
    string expected = "[Card(4H)]";
    ASSERT_EQ(expected, actual.str());
}

TEST(CardCollectionTests, VectorArgConstructor) {
    Deck deck = Deck();
    std::vector<Card> cards;
    for (int i = 0; i < 4; i++)
        cards.push_back(deck.pop());
    CardCollection cc(cards);
    int expected = 4;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST(CardCollectionTests, AddCard) {
    Deck deck = Deck();
    std::vector<Card> cards;
    for (int i = 0; i < 4; i++)
        cards.push_back(deck.pop());
    CardCollection cc(cards);
    Card card(5, "D");
    cc.add(card);
    int expected = 5;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST(CardCollectionTests, AddCardsFromVector) {
    Deck deck = Deck();
    std::vector<Card> cards;
    for (int i = 0; i < 4; i++)
        cards.push_back(deck.pop());
    CardCollection cc(cards);

    std::vector<Card> new_cards;
    for (int i = 0; i < 4; i++)
        new_cards.push_back(deck.pop());
    cc.add(new_cards);
    int expected = 8;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST(CardCollectionTests, EqualityTest){
    CardCollection c1;
    CardCollection c2;
    Card card1(5, "H");
    Card card2(5, "H");
    c1.add(card1);
    c2.add(card1);
    ASSERT_TRUE(c1 == c2);
}


TEST(CardCollectionTests, IterationTests2) {
    // For any random operations you need to
    //  set the seed in a main block.
    nc::random::seed(time(NULL));

    CardCollection cards1(4);
    CardCollection cards2(4);

    bool ans = cards1 == cards2;
    ASSERT_FALSE(cards1 == cards2);
}
