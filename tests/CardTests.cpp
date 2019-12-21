//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "cards/Card.h"
#include "cards/Deck.h"
#include "cards/CardCollection.h"

using namespace cards;

TEST(CardTests, SuitAttribute) {
    Card fourOfHearts = Card(4, "H");
    ASSERT_EQ(fourOfHearts.suit, "H");
}

TEST(CardTests, CopyConstructor) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfSpades = Card(5, "S");
    fourOfHearts = fiveOfSpades;
    ASSERT_EQ(fourOfHearts.suit, "S");
}

TEST(CardTests, AssignmentOperator) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfSpades = Card(5, "S");
    fourOfHearts = fiveOfSpades;
    ASSERT_EQ(fourOfHearts.suit, "S");
}

TEST(CardTests, PutToOperator) {
    Card fourOfHearts = Card(4, "H");
    cout << "\n" << fourOfHearts << endl;
}

TEST(CardTests, EqualsOperator) {
    Card fourOfHearts1 = Card(4, "H");
    Card fourOfHearts2 = Card(4, "H");
    ASSERT_TRUE(fourOfHearts1 == fourOfHearts2);
}

TEST(CardTests, NotEqualsOperator) {
    Card fourOfHearts = Card(4, "H");
    Card twoOfDiamonds = Card(2, "D");
    ASSERT_TRUE(fourOfHearts != twoOfDiamonds);
}

TEST(CardTests, GreaterThan) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfHearts = Card(5, "H");
    ASSERT_TRUE(fiveOfHearts > fourOfHearts);
}

TEST(CardTests, LessThan) {
    Card fourOfHearts = Card(4, "H");
    Card fiveOfHearts = Card(5, "H");
    ASSERT_TRUE(fourOfHearts < fiveOfHearts);
}

TEST(CardTests, GreaterThanOrEquals) {
    Card fourOfHearts1 = Card(4, "H");
    Card fourOfHearts2 = Card(4, "H");
    Card fourOfDiamonds = Card(4, "D");
    Card fiveOfHearts = Card(5, "H");
    ASSERT_TRUE(fourOfHearts2 >= fourOfHearts1);
    ASSERT_TRUE(fiveOfHearts >= fourOfHearts1);
    ASSERT_TRUE(fiveOfHearts >= fourOfDiamonds);
}

TEST(CardTests, LessrThanOrEquals) {
    Card fourOfHearts1 = Card(4, "H");
    Card fourOfHearts2 = Card(4, "H");
    Card fourOfDiamonds = Card(4, "D");
    Card threeOfHearts = Card(3, "H");
    ASSERT_TRUE(fourOfHearts2 <= fourOfHearts1);
    ASSERT_TRUE(threeOfHearts <= fourOfHearts1);
    ASSERT_FALSE(fourOfHearts1 <= fourOfDiamonds);
}

TEST(CardTests, TestCout) {
    Card fourOfHearts1 = Card(4, "H");
//    cout << "\n" << fourOfHearts1 << endl;
//    Deck deck = Deck();
//    for (int i=0; i<deck.size(); i++){
//        cout << deck[i] << endl;
//    }

}














