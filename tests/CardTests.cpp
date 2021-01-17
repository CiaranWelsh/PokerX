//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "PokerX/engine/Card.h"
#include "PokerX/engine/Deck.h"
#include "PokerX/engine/CardCollection.h"

using namespace pokerx;

class CardTests : public ::testing::Test {
public:
    CardTests() = default;
};

TEST_F(CardTests, SuitAttribute) {
    Card fourOfHearts = Card(4, "H");
    ASSERT_EQ(fourOfHearts.getSuit(), "H");
}

TEST_F(CardTests, CopyConstructor) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfSpades = Card(5, "S");
    fourOfHearts = fiveOfSpades;
    ASSERT_EQ(fourOfHearts.getSuit(), "S");
}

TEST_F(CardTests, AssignmentOperator) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfSpades = Card(5, "S");
    fourOfHearts = fiveOfSpades;
    ASSERT_EQ(fourOfHearts.getSuit(), "S");
}

TEST_F(CardTests, PutToOperator) {
    Card fourOfHearts = Card(4, "H");
    cout << "\n" << fourOfHearts << endl;
}

TEST_F(CardTests, EqualsOperator) {
    Card fourOfHearts1 = Card(4, "H");
    Card fourOfHearts2 = Card(4, "H");
    ASSERT_TRUE(fourOfHearts1 == fourOfHearts2);
}

TEST_F(CardTests, NotEqualsOperator) {
    Card fourOfHearts = Card(4, "H");
    Card twoOfDiamonds = Card(2, "D");
    ASSERT_TRUE(fourOfHearts != twoOfDiamonds);
}

TEST_F(CardTests, GreaterThan) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfHearts = Card(5, "H");
    ASSERT_TRUE(fiveOfHearts > fourOfHearts);
}

TEST_F(CardTests, LessThan) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfHearts = Card(5, "H");
    ASSERT_TRUE(fourOfHearts < fiveOfHearts);
}

TEST_F(CardTests, GreaterThanOrEquals) {
    Card fourOfHearts1 = Card(4, "H");
    Card fourOfHearts2 = Card(4, "H");
    Card fourOfDiamonds = Card(4, "D");
    Card fiveOfHearts = Card(5, "H");
    ASSERT_TRUE(fourOfHearts2 >= fourOfHearts1);
    ASSERT_TRUE(fiveOfHearts >= fourOfHearts1);
    ASSERT_TRUE(fiveOfHearts >= fourOfDiamonds);
}

TEST_F(CardTests, LessrThanOrEquals) {
    Card fourOfHearts1 = Card(4, "H");
    Card fourOfHearts2 = Card(4, "H");
    Card fourOfDiamonds = Card(4, "D");
    Card threeOfHearts = Card(3, "H");
    ASSERT_TRUE(fourOfHearts2 <= fourOfHearts1);
    ASSERT_TRUE(threeOfHearts <= fourOfHearts1);
    ASSERT_TRUE(fourOfHearts1 <= fourOfDiamonds);
}

TEST_F(CardTests, StreamTest){
    Card fourOfHearts = Card(4, "H");
    std::ostringstream os;
    os << fourOfHearts;
    std::string expected = "Card(4H)";
    ASSERT_STREQ(os.str().c_str(), expected.c_str());
}














