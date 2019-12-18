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
    Card card1(10, "S");
    Card card2(4, "S");
    std::vector<Card> cards{card1, card2};
    CardCollection cc(cards);
    int expected = 2;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST(CardCollectionTests, AddCard) {
    Card card1(10, "S");
    Card card2(4, "S");
    std::vector<Card> cards{card1, card2};
    CardCollection cc(cards);
    Card card(5, "D");
    cc.add(card);
    int expected = 3;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST(CardCollectionTests, AddCardsFromVector) {
    Card card1(10, "S");
    Card card2(4, "S");
    std::vector<Card> cards{card1, card2};
    CardCollection cc(cards);
    Card card3(11, "S");
    Card card4(5, "S");
    std::vector<Card> new_cards{card3, card4};
    cc.add(new_cards);
    int expected = 4;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST(CardCollectionTests, EqualityTest) {
    CardCollection c1;
    CardCollection c2;
    Card card1(5, "H");
    Card card2(5, "H");
    c1.add(card1);
    c2.add(card1);
    ASSERT_TRUE(c1 == c2);
}


TEST(CardCollectionTests, ConsstructorFromInt) {
    // For any random operations you need to
    //  set the seed in a main block.
    nc::random::seed(time(NULL));
    CardCollection cards1(4);
    CardCollection cards2(4);
    ASSERT_FALSE(cards1 == cards2);
}


TEST(CardCollectionTests, TestPop) {
    Card card1(6, "C");
    Card card2(7, "C");
    std::vector<Card> cards {card1, card2};
    CardCollection cc(cards);
    Card new_card = cc.pop();
    ASSERT_TRUE(new_card == card1);
}

TEST(CardCollectionTests, TestPopWithIntArg) {
    Card card1(6, "C");
    Card card2(7, "C");
    Card card3(8, "C");
    std::vector<Card> cards {card1, card2, card3};
    CardCollection cc(cards);
    CardCollection new_card = cc.pop(2);
    ASSERT_TRUE(new_card[1] == card2);
}


TEST(CardCollectionTests, TestCardCollectionFromAnotherCardCollection) {
    Card card1(6, "C");
    Card card2(7, "C");
    Card card3(8, "C");
    Card card4(9, "C");
    Card card5(10, "C");
    std::vector<Card> cards {card1, card2, card3, card4, card5};
    CardCollection cc(cards);
    CardCollection cc2(cc, 2);
    ASSERT_TRUE(cc.size() == 3);
    ASSERT_TRUE(cc2.size() == 2);
}


















