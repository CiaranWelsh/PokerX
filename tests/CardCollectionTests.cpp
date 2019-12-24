//
// Created by CiaranWelsh on 16/12/2019.
//
#include "gtest/gtest.h"
#include "cards/Card.h"
#include "cards/Deck.h"
#include "cards/CardCollection.h"

#include <boost/random/uniform_int.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <chrono>

using namespace cards;
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
    std::vector<Card> cards{card1, card2};
    CardCollection cc(cards);
    Card new_card = cc.pop();
    ASSERT_TRUE(new_card == card1);
}

TEST(CardCollectionTests, TestPopWithIntArg) {
    Card card1(6, "C");
    Card card2(7, "C");
    Card card3(8, "C");
    std::vector<Card> cards{card1, card2, card3};
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
    std::vector<Card> cards{card1, card2, card3, card4, card5};
    CardCollection cc(cards);
    CardCollection cc2(cc, 2);
    ASSERT_TRUE(cc.size() == 3);
    ASSERT_TRUE(cc2.size() == 2);
}


TEST(CardCollectionTests, TestOverloadingPlus) {
    Card card1(6, "C");
    Card card2(7, "C");
    Card card3(8, "C");
    Card card4(9, "C");
    Card card5(10, "C");
    std::vector<Card> cards1{card1, card2};
    std::vector<Card> cards2{card3, card4, card5};
    CardCollection cc(cards1);
    CardCollection cc2(cards2);
    cc = cc + cc2;
    ASSERT_TRUE(cc.size() == 5);
    cc += cc2;
    ASSERT_TRUE(cc.size() == 8);
}


TEST(CardCollectionTests, TestSort) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(8, "H");
    Card card4(9, "C");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    std::vector<Card> cards2{card5, card4, card3, card2, card1};
    CardCollection cc(cards2);
    cc.sort();
    CardCollection cc2(cards1);
    ASSERT_TRUE(cc2 == cc);
}


TEST(CardCollectionTests, TestGetSuits) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(8, "H");
    Card card4(9, "C");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc(cards1);
    std::vector<std::string> ranks = cc.getSuits();
    std::vector<std::string> expected = {"D", "C", "H", "C", "S"};
    ASSERT_TRUE(expected == ranks);
}

TEST(CardCollectionTests, TestGetRanks) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(8, "H");
    Card card4(9, "C");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc(cards1);
    std::vector<int> ranks = cc.getRanks();
    std::vector<int> expected = {6, 7, 8, 9, 10};
    ASSERT_TRUE(expected == ranks);
}


TEST(CardCollectionTests, TestGetUniqueRanks) {
    Card card1(6, "D");
    Card card2(6, "C");
    Card card3(6, "H");
    Card card4(6, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc(cards1);
    std::vector<int> unique_ranks = cc.getUniqueRanks();
    std::vector<int> expected = {6, 10};
    ASSERT_TRUE(expected == unique_ranks);
}


TEST(CardCollectionTests, TestGetUniqueSuits) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc(cards1);
    std::vector<std::string> unique_ranks = cc.getUniqueSuits();
    std::vector<std::string> expected = {"D", "C", "H", "S"};
    ASSERT_TRUE(expected == unique_ranks);
}


TEST(CardCollectionTests, TestRemove) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc(cards1);
    cc.erase(3);
    int actual = cc.size();
    ASSERT_EQ(actual, 4);
}


TEST(CardCollectionTests, TestGetterOperator) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc(cards1);
    Card card6 = cc[4];
    ASSERT_TRUE(card5 == card6);
}


TEST(CardCollectionTests, TestGetterOperatorRange) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc1(cards1);
    CardCollection actual = cc1(2, 4);
    std::vector<Card> cc2{card3, card4};
    CardCollection expected(cc2);
    ASSERT_TRUE(expected == actual);
}

TEST(CardCollectionTests, TestContains) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc1(cards1);
    ASSERT_TRUE(cc1.contains(card4));
}

TEST(CardCollectionTests, TestContainsRank) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc1(cards1);
    ASSERT_TRUE(cc1.containsRank(6));
}

TEST(CardCollectionTests, TestContainsSuit) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc1(cards1);
    ASSERT_TRUE(cc1.containsSuit("C"));
}

TEST(CardCollectionTests, TestFindByRank) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    CardCollection cc1(cards1);
    Card card = cc1.findByRank(7);
    ASSERT_TRUE(card == card2);
}

TEST(CardCollectionTests, TestSetDifference) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");

    Card card6(7, "H");
    Card card7(13, "D");
    Card card8(10, "D");
    Card card9(9, "C");
    Card card10(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    std::vector<Card> cards2{card6, card7, card8, card9, card10};
    CardCollection cc1(cards1);
    CardCollection cc2(cards2);
    CardCollection diff = cc1.set_difference(cc2);
    ASSERT_EQ(diff.size(), 4);
}

TEST(CardCollectionTests, TestSetIntersection) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");
    Card card4(12, "S");
    Card card5(10, "S");

    Card card6(7, "H");
    Card card7(13, "D");
    Card card8(10, "D");
    Card card9(9, "C");
    Card card10(10, "S");
    std::vector<Card> cards1{card1, card2, card3, card4, card5};
    std::vector<Card> cards2{card6, card7, card8, card9, card10};
    CardCollection cc1(cards1);
    CardCollection cc2(cards2);
    CardCollection diff = cc1.set_intersection(cc2);
    ASSERT_EQ(diff.size(), 1);
}


















