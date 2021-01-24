//
// Created by CiaranWelsh on 16/12/2019.
//
#include "gtest/gtest.h"
#include <chrono>
#include "Mockups/MockCard.h"
#include "PokerX/engine/CardCollection.h"

using namespace testing;

using namespace pokerx;

class CardCollectionTests  : public ::testing::Test {
public: 
    CardCollectionTests() = default;
};

TEST_F(CardCollectionTests, AddCardToCollection) {
    // Arrange
    MockCard fourOfHearts(4, "H");
    CardCollection cards;

    // act
    cards.add(&fourOfHearts);

    // assert
    ASSERT_EQ(cards.size(), 1);
}

TEST_F(CardCollectionTests, TestConstructionFromVector) {
    MockCard card1(10, "S");
    MockCard card2(4, "S");
    std::vector<ICard *> cards({&card1, &card2});
    CardCollection cc(cards);
    int expected = 2;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST_F(CardCollectionTests, AddCardsFromVector) {
    MockCard card1(11, "S");
    MockCard card2(5, "S");
    std::vector<ICard *> new_cards({&card1, &card2});
    CardCollection cc;
    cc.add(new_cards);
    int expected = 2;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}


TEST_F(CardCollectionTests, TestEqualityOperatorWorks) {
    CardCollection c1;
    CardCollection c2;
    MockCard card1(5, "H");
    MockCard card2(5, "H");
    c1.add(&card1);
    c2.add(&card2);
    ASSERT_TRUE(c1 == c2);
}

TEST_F(CardCollectionTests, TestPopRemovesTopCardFromCollection) {
    MockCard card1(6, "C");
    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card1, getSuit()).Times(1).WillRepeatedly(Return("C"));

    std::vector<ICard *> cards({&card1});
    CardCollection cc(cards);

    // pop the card off the collection, cast to MockCard
    auto *new_card = (MockCard *) cc.pop();

    ASSERT_EQ(6, new_card->getRank());
    ASSERT_EQ("C", new_card->getSuit());
}

TEST_F(CardCollectionTests, TestPopWithIntArgReturnValueOfNCards) {
    MockCard card1(6, "C");
    MockCard card2(7, "H");
    MockCard card3(8, "C");

    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card1, getSuit()).Times(1).WillRepeatedly(Return("C"));
    EXPECT_CALL(card2, getRank()).Times(1).WillRepeatedly(Return(7));
    EXPECT_CALL(card2, getSuit()).Times(1).WillRepeatedly(Return("H"));

    std::vector<ICard *> cards({&card1, &card2, &card3});
    CardCollection cc(cards);
    CardCollection subset = cc.pop(2);
    ASSERT_EQ(2, subset.size());
    std::vector<int> ranks = {6, 7};
    std::vector<std::string> suits = {"C", "H"};
    ASSERT_TRUE(ranks == subset.getRanks());
    ASSERT_TRUE(suits == subset.getSuits());
}

TEST_F(CardCollectionTests, TestOverloadingPlusOperatorForConcat) {
    MockCard card1(6, "C");
    MockCard card2(7, "C");
    MockCard card3(8, "C");
    MockCard card4(9, "C");
    MockCard card5(10, "C");
    std::vector<ICard *> cards1({&card1, &card2});
    std::vector<ICard *> cards2({&card3, &card4, &card5});
    CardCollection cc(cards1);
    CardCollection cc2(cards2);
    cc = cc + cc2;
    ASSERT_TRUE(cc.size() == 5);
    cc += cc2;
    ASSERT_TRUE(cc.size() == 8);
}


TEST_F(CardCollectionTests, TestSortCorrectlyOrdersCards) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");
    MockCard card3(8, "H");
    MockCard card4(9, "C");
    MockCard card5(10, "S");

    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card2, getRank()).Times(1).WillRepeatedly(Return(7));
    EXPECT_CALL(card3, getRank()).Times(1).WillRepeatedly(Return(8));
    EXPECT_CALL(card4, getRank()).Times(1).WillRepeatedly(Return(9));
    EXPECT_CALL(card5, getRank()).Times(1).WillRepeatedly(Return(10));

    EXPECT_CALL(card1, getSuit()).Times(1).WillRepeatedly(Return("D"));
    EXPECT_CALL(card2, getSuit()).Times(1).WillRepeatedly(Return("C"));
    EXPECT_CALL(card3, getSuit()).Times(1).WillRepeatedly(Return("H"));
    EXPECT_CALL(card4, getSuit()).Times(1).WillRepeatedly(Return("C"));
    EXPECT_CALL(card5, getSuit()).Times(1).WillRepeatedly(Return("S"));

    std::vector<ICard *> cards2({&card5, &card4, &card3, &card2, &card1});

    CardCollection cc(cards2);
    cc.sort();
    std::vector<int> ranks = {6, 7, 8, 9, 10};
    std::vector<std::string> suits = {"D", "C", "H", "C", "S"};
    ASSERT_EQ(ranks, cc.getRanks());
    ASSERT_EQ(suits, cc.getSuits());
}


TEST_F(CardCollectionTests, TestGetSuitsCallsGetSuit) {
    MockCard card1(6, "D");
    std::vector<ICard *> cards1({&card1});
    CardCollection cc(cards1);
    EXPECT_CALL(card1, getSuit()).Times(1);
    cc.getSuits();
}

TEST_F(CardCollectionTests, TestGetSuitsReturnsRightNumberOfCards) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");
    MockCard card3(8, "H");
    MockCard card4(9, "C");
    MockCard card5(10, "S");
    std::vector<ICard *> cards1({&card1, &card2, &card3, &card4, &card5});
    CardCollection cc(cards1);
    ASSERT_EQ(5, cc.size());
}

TEST_F(CardCollectionTests, TestGetRanks) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");

    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card2, getRank()).Times(1).WillRepeatedly(Return(7));

    std::vector<ICard *> cards1({&card1, &card2});
    CardCollection cc(cards1);
    std::vector<int> ranks = cc.getRanks();
    std::vector<int> expected = {6, 7};
    ASSERT_TRUE(expected == ranks);
}


TEST_F(CardCollectionTests, TestGetUniqueRanks) {
    MockCard card1(6, "D");
    MockCard card2(6, "C");
    MockCard card3(6, "H");
    MockCard card4(6, "S");
    MockCard card5(10, "S");

    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card2, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card3, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card4, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card5, getRank()).Times(1).WillRepeatedly(Return(10));

    std::vector<ICard *> cards1({&card1, &card2, &card3, &card4, &card5});
    CardCollection cc(cards1);
    std::vector<int> expected = {6, 10};
    ASSERT_EQ(expected, cc.getUniqueRanks());
}


TEST_F(CardCollectionTests, TestGetUniqueSuits) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");
    MockCard card3(2, "H");
    MockCard card4(12, "S");
    MockCard card5(10, "S");

    EXPECT_CALL(card1, getSuit()).Times(1).WillRepeatedly(Return("D"));
    EXPECT_CALL(card2, getSuit()).Times(1).WillRepeatedly(Return("C"));
    EXPECT_CALL(card3, getSuit()).Times(1).WillRepeatedly(Return("H"));
    EXPECT_CALL(card4, getSuit()).Times(1).WillRepeatedly(Return("S"));
    EXPECT_CALL(card5, getSuit()).Times(1).WillRepeatedly(Return("S"));

    std::vector<ICard *> cards1({&card1, &card2, &card3, &card4, &card5});
    CardCollection cc(cards1);
    std::vector<std::string> unique_ranks = cc.getUniqueSuits();
    std::vector<std::string> expected = {"D", "C", "H", "S"};
    ASSERT_EQ(expected, unique_ranks);
}


TEST_F(CardCollectionTests, TestRemoveCardFromCollection) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");
    std::vector<ICard *> cards1({&card1, &card2});
    CardCollection cc(cards1);
    cc.erase(1);
    int actual = cc.size();
    ASSERT_EQ(actual, 1);
}


TEST_F(CardCollectionTests, TestGetterOperatorReturnsCorrectCard) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");

    EXPECT_CALL(card2, getRank()).Times(1).WillRepeatedly(Return(6));
    EXPECT_CALL(card2, getSuit()).Times(1).WillRepeatedly(Return("C"));

    std::vector<ICard *> cards({&card1, &card2});
    CardCollection cc(cards);
    ASSERT_EQ(6, cc[1]->getRank());
    ASSERT_EQ("C", cc[1]->getSuit());

}


TEST_F(CardCollectionTests, TestGetterOperatorRange) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");
    MockCard card3(2, "H");
    MockCard card4(12, "S");
    MockCard card5(10, "S");

    EXPECT_CALL(card3, getRank()).Times(1).WillRepeatedly(Return(2));
    EXPECT_CALL(card4, getRank()).Times(1).WillRepeatedly(Return(3));

    std::vector<ICard *> cards1({&card1, &card2, &card3, &card4, &card5});
    CardCollection cc(cards1);
    CardCollection subset = cc(2, 4);
    std::vector<int> expected = {2, 3};
    ASSERT_EQ(expected, subset.getRanks());
}

TEST_F(CardCollectionTests, TestContainsWhenCardInCollection) {
    MockCard card1(6, "D");
    MockCard card2(7, "D");
    std::vector<ICard *> cards1({&card1, &card2});
    CardCollection cc1(cards1);
    ASSERT_TRUE(cc1.contains(&card1));
}

TEST_F(CardCollectionTests, TestContainsWhenCardNotInCollection) {
    MockCard card1(6, "D");
    MockCard card2(7, "D");
    std::vector<ICard *> cards1({&card1});
    CardCollection cc1(cards1);
    ASSERT_FALSE(cc1.contains(&card2));
}

TEST_F(CardCollectionTests, TestContainsRankWhenTrue) {
    MockCard card1(6, "D");
    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(6));
    std::vector<ICard *> cards1({&card1});
    CardCollection cc1(cards1);
    ASSERT_TRUE(cc1.containsRank(6));
}

TEST_F(CardCollectionTests, TestContainsRankWhenFalse) {
    MockCard card1(6, "D");
    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(6));
    std::vector<ICard *> cards1({&card1});
    CardCollection cc1(cards1);
    ASSERT_FALSE(cc1.containsRank(7));
}

TEST_F(CardCollectionTests, TestContainsSuitWhenTrue) {
    MockCard card1(6, "D");
    EXPECT_CALL(card1, getSuit()).Times(1).WillRepeatedly(Return("D"));
    std::vector<ICard *> cards1({&card1});
    CardCollection cc1(cards1);
    ASSERT_TRUE(cc1.containsSuit("D"));
}

TEST_F(CardCollectionTests, TestContainsSuitWhenFalse) {
    MockCard card1(6, "D");
    EXPECT_CALL(card1, getSuit()).Times(1).WillRepeatedly(Return("D"));
    std::vector<ICard *> cards1({&card1});
    CardCollection cc1(cards1);
    ASSERT_FALSE(cc1.containsSuit("C"));
}

//TEST_F(CardCollectionTests, TestFindByRank) { method deprecated.
//    MockCard card1(6, "D");
//    MockCard card2(7, "C");
//    MockCard card3(2, "H");
//    MockCard card4(12, "S");
//    MockCard card5(10, "S");
//    std::vector<ICard*> cards1({&card1, &card2, &card3, &card4, &card5});
//    CardCollection cc1(cards1);
//    MockCard card = cc1.findByRank(7);
//    ASSERT_TRUE(card == card2);
//}

TEST_F(CardCollectionTests, TestSetDifference) {

    MockCard card1(2, "D");
    MockCard card2(3, "D");
    MockCard card3(4, "D");

    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(2));
    EXPECT_CALL(card1, getSuit()).Times(1).WillRepeatedly(Return("D"));

    std::vector<ICard *> cards1({&card1, &card2});
    std::vector<ICard *> cards2({&card2, &card3});
    std::vector<ICard *> cards_out;

    CardCollection cc1(cards1);
    CardCollection cc2(cards2);
    CardCollection diff = cc1.setDifference(cc2);

    ASSERT_EQ(2, diff[0]->getRank());
    ASSERT_EQ("D", diff[0]->getSuit());
}

TEST_F(CardCollectionTests, TestSetIntersection) {

    MockCard card1(2, "D");
    MockCard card2(3, "C");
    MockCard card3(4, "D");

    EXPECT_CALL(card2, getRank()).Times(1).WillRepeatedly(Return(3));
    EXPECT_CALL(card2, getSuit()).Times(1).WillRepeatedly(Return("C"));

    std::vector<ICard *> cards1({&card1, &card2});
    std::vector<ICard *> cards2({&card2, &card3});
    std::vector<ICard *> cards_out;

    CardCollection cc1(cards1);
    CardCollection cc2(cards2);
    CardCollection diff = cc1.setIntersection(cc2);

    ASSERT_EQ(3, diff[0]->getRank());
    ASSERT_EQ("C", diff[0]->getSuit());
}


TEST_F(CardCollectionTests, TestCopyWithMethod) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");
    MockCard card3(2, "H");
    MockCard card4(12, "S");
    MockCard card5(10, "S");

    std::vector<ICard *> cards1({&card1, &card2, &card3, &card4, &card5});
    CardCollection cc1(cards1);
    CardCollection cc2 = cc1.copy();
    ASSERT_NE(&cc1, &cc2);
    ASSERT_EQ(cc1, cc2);
}

TEST_F(CardCollectionTests, TestCopyWithCopyAssignmentOp) {
    MockCard card1(6, "D");
    MockCard card2(7, "C");
    MockCard card3(2, "H");
    MockCard card4(12, "S");
    MockCard card5(10, "S");

    std::vector<ICard *> cards1({&card1, &card2, &card3, &card4, &card5});
    CardCollection cc1(cards1);
    CardCollection cc2 = cc1;
    ASSERT_NE(&cc1, &cc2);
    ASSERT_EQ(cc1, cc2);
}


TEST_F(CardCollectionTests, TestIsUniqueWhenTrue) {
    Card card1(6, "D");
    Card card2(7, "C");
    Card card3(2, "H");

    std::vector<ICard *> cards1({&card1, &card2, &card3});
    CardCollection cc1(cards1);
    ASSERT_TRUE(cc1.isUniqueSet());
}


TEST_F(CardCollectionTests, TestIsUniqueWhenFalse) {
    Card card1(6, "D");
    Card card2(2, "H");
    Card card3(2, "H");

    std::vector<ICard *> cards1({&card1, &card2, &card3});
    CardCollection cc1(cards1);
    ASSERT_FALSE(cc1.isUniqueSet());
}


















