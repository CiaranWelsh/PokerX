//
// Created by CiaranWelsh on 16/12/2019.
//
#include "gtest/gtest.h"
#include <chrono>
#include "Mockups/MockCard.h"
#include "PokerX/engine/CardCollection.h"
#include <set>

using namespace testing;
using namespace pokerx;

class CardCollectionTests : public ::testing::Test {
public:
    MockCards mockCards;
    Cards cards;

    CardCollectionTests() = default;
};

TEST_F(CardCollectionTests, CreateCardCollectionWithStringVector) {
    CardCollection cards({"4H"});
    ASSERT_EQ(cards[0]->getRank(), 4);
    ASSERT_EQ(cards[0]->getSuit(), "H");
    ASSERT_EQ(1, cards.size());
}

TEST_F(CardCollectionTests, TestConstructionFromVector) {
    CardCollection cc({"10S", "4S"});
    int expected = 2;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}

TEST_F(CardCollectionTests, AddCardToCollection) {
    CardCollection cards;

    cards.add({"4h"});

    ASSERT_EQ(cards[0]->getRank(), 4);
    ASSERT_EQ(cards[0]->getSuit(), "H");
    ASSERT_EQ(1, cards.size());
}


TEST_F(CardCollectionTests, TestStillSortedAfterAddCardInMiddle) {
    CardCollection cc({"TS", "4S"});
    cc.add({"5s"});
    std::vector<int> expected = {4, 5, 10};
    std::vector<int> actual = cc.getRanks();
    ASSERT_EQ(expected, actual);
}

TEST_F(CardCollectionTests, TestStillSortedAfterAddCardToEnd) {
    CardCollection cc({"TS", "4S"});
    cc.add({"11S"});
    std::vector<int> expected = {4, 10, 11};
    std::vector<int> actual = cc.getRanks();
    ASSERT_EQ(expected, actual);
}

TEST_F(CardCollectionTests, TestStillSortedAfterAddCardToBegin) {
    CardCollection cc({"10S", "4S"});
    cc.add({"2S"});
    std::vector<int> expected = {2, 4, 10};
    std::vector<int> actual = cc.getRanks();
    ASSERT_EQ(expected, actual);
}

TEST_F(CardCollectionTests, AddCardsFromVector) {
    CardCollection cc;
    cc.add({"11S", "5S"});
    int expected = 2;
    int actual = cc.size();
    ASSERT_EQ(expected, actual);
}


TEST_F(CardCollectionTests, TestEqualityOperatorWorks) {
    CardCollection c1({"5h"});
    CardCollection c2({"5H"});
    ASSERT_TRUE(c1 == c2);
}

TEST_F(CardCollectionTests, TestEqualityOperatorWorksStr) {
    CardCollection c1({"5H", "6D", "AH"});
    std::vector<std::string> exp({"5h", "6d", "AH"});
    ASSERT_TRUE(c1 == exp);
}

TEST_F(CardCollectionTests, TestPopRemovesTopCardFromCollection) {
    CardCollection cc({"6C"});

    // pop_back the card off the collection, cast to MockCard
    auto new_card = cc.pop();

    ASSERT_EQ(6, new_card->getRank());
    ASSERT_EQ("C", new_card->getSuit());
}

TEST_F(CardCollectionTests, TestPopWithIntArgReturnValueOfNCards) {
    CardCollection cc({"6C", "7H", "8C"});
    CardCollection subset = cc.pop(2);
    std::vector<std::string> expected = {"7H", "8C"};
    ASSERT_EQ(subset, expected);
}

TEST_F(CardCollectionTests, TestOverloadingPlusOperatorForConcat) {
    CardCollection cc({"6C", "7C"});
    CardCollection cc2({"8C", "9C", "TC"});
    cc = cc + cc2;
    ASSERT_TRUE(cc.size() == 5);
    cc += cc2;
    ASSERT_TRUE(cc.size() == 8);
}


TEST_F(CardCollectionTests, TestSortCorrectlyOrdersCards) {

    std::vector<std::string> strVec({"TS", "9C", "8H", "7C", "6D"});
    CardCollection cc(strVec);
    ASSERT_EQ(cc, std::vector<std::string>({"6D", "7C", "8H", "9C", "TS"}));
}

TEST_F(CardCollectionTests, TestGetRanks) {
    CardCollection cc({"6d", "7c"});
    std::vector<int> ranks = cc.getRanks();
    std::vector<int> expected = {6, 7};
    ASSERT_TRUE(expected == ranks);
}

TEST_F(CardCollectionTests, TestGetSuit) {
    CardCollection cc({"6d", "7c"});
    std::vector<std::string> ranks = cc.getSuits();
    std::vector<std::string> expected({"D", "C"});
    ASSERT_EQ(expected, ranks);
}


TEST_F(CardCollectionTests, TestGetUniqueRanks) {
    CardCollection cc({"6D", "6H", "6C", "6S", "10S"});
    std::vector<int> expected = {6, 10};
    ASSERT_EQ(expected, cc.getUniqueRanks());
}


TEST_F(CardCollectionTests, TestGetUniqueSuits) {
    CardCollection cc({"6D", "7D", "2S", "12S", "10S"});
    std::set<std::string> unique_suits = cc.getUniqueSuits();
    std::set<std::string> expected = {"D", "S"};
    ASSERT_EQ(expected, unique_suits);
}


TEST_F(CardCollectionTests, TestRemoveCardFromCollection) {
    CardCollection cc({"6D", "7C"});
    cc.erase(1);
    int actual = cc.size();
    ASSERT_EQ(actual, 1);
    ASSERT_EQ(*cc[0], "6D");
}


TEST_F(CardCollectionTests, TestGetterOperatorReturnsCorrectCard) {
    CardCollection cc({"6D", "7C"});
    ASSERT_EQ(*cc[1], "7c");
}

TEST_F(CardCollectionTests, TestGetterOperatorRange) {
    CardCollection cc({"6D", "7C", "2H", "QS", "TS"});
    CardCollection subset = cc(0, 4);
    ASSERT_EQ(subset, std::vector<std::string>({"2H", "6D", "7C", "TS"}));
}

TEST_F(CardCollectionTests, TestContainsWhenCardInCollection) {
    CardCollection cc1({"6D", "7D"});
    ASSERT_TRUE(cc1.contains("6D"));
}

TEST_F(CardCollectionTests, TestContainsWhenCardNotInCollection) {
    CardCollection cc1({"6D"});
    ASSERT_FALSE(cc1.contains("7D"));
}

TEST_F(CardCollectionTests, TestContainsRankWhenTrue) {
    CardCollection cc1({"6D"});
    ASSERT_TRUE(cc1.containsRank(6));
}

TEST_F(CardCollectionTests, TestContainsRankWhenFalse) {
    CardCollection cc1({"6D"});
    ASSERT_FALSE(cc1.containsRank(7));
}

TEST_F(CardCollectionTests, TestContainsSuitWhenTrue) {
    CardCollection cc1({"6D"});
    ASSERT_TRUE(cc1.containsSuit("D"));
}

TEST_F(CardCollectionTests, TestContainsSuitWhenFalse) {
    CardCollection cc1({"6D"});
    ASSERT_FALSE(cc1.containsSuit("C"));
}


TEST_F(CardCollectionTests, TestSetDifference) {

    CardCollection cc1({"2D", "3D"});
    CardCollection cc2({"3D", "4D"});
    CardCollection diff = cc1.setDifference(cc2);

    ASSERT_EQ(diff, std::vector<std::string>({"2D"}));
}

TEST_F(CardCollectionTests, TestSetIntersection) {

    CardCollection cc1({"2D", "3C"});
    CardCollection cc2({"3C", "4D"});
    CardCollection diff = cc1.setIntersection(cc2);

    ASSERT_EQ(diff, std::vector<std::string>({"3C"}));

}


TEST_F(CardCollectionTests, TestCopyWithMethod) {

    CardCollection cc1({"6D", "7C", "2H", "12S", "10S"});
    CardCollection cc2 = cc1.copy();
    ASSERT_NE(&cc1, &cc2);
    ASSERT_EQ(cc1, cc2);
}

TEST_F(CardCollectionTests, TestCopyWithCopyAssignmentOp) {
    CardCollection cc1({"6D", "7C", "2H", "12S", "10S"});
    CardCollection cc2 = cc1;
    ASSERT_NE(&cc1, &cc2);
    ASSERT_EQ(cc1, cc2);
}


TEST_F(CardCollectionTests, TestIsUniqueWhenTrue) {
    CardCollection cc1({"6D", "7C", "2H"});
    ASSERT_TRUE(cc1.isUniqueSet());
}


TEST_F(CardCollectionTests, TestIsUniqueWhenFalse) {
    CardCollection cc1({"6D", "2H", "2H"});
    ASSERT_FALSE(cc1.isUniqueSet());
}


TEST_F(CardCollectionTests, TestInsertACardAtBegining) {
    CardCollection cc1({"6D", "4H", "4C", "8C"});
    cc1.insert(cc1.begin(), "2D");
    ASSERT_EQ(*cc1[0], "2D");
}


TEST_F(CardCollectionTests, CheckThatWeCanFindACard) {

    CardCollection cc1({"6D", "2H", "2H"});

    bool found = false;
    for (auto &card: cc1) {
        if (std::find(cc1.begin(), cc1.end(), card) != cc1.end()) {
            found = true;
        }
    }
    ASSERT_TRUE(found);
}

TEST_F(CardCollectionTests, CheckThatWeCanFindACardDifferentPointer) {
    CardCollection cc1({"6D", "2H", "2D"});
    int idx = cc1.findCard("6D");
    ASSERT_EQ(idx, 2);
}

TEST_F(CardCollectionTests, CheckThatWeCanFindACardAceOfSpades) {
    CardCollection cc({"6D", "14S", "14S"});

    int idx = cc.findCard("14S");

    ASSERT_EQ(idx, 1); // remember cardcollection is auto sorted.
}


















