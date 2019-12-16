//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "Card.h"


TEST(CardTests, SuitAttribute) {
    Game::Card fourOfHearts = Game::Card(4, 'H');
    ASSERT_EQ(fourOfHearts.suit, 'H');
}

TEST(CardTests, CopyConstructor) {
    Game::Card fourOfHearts = Game::Card(4, 'H');
    Game::Card fiveOfSpades = Game::Card(5, 'S');
    fourOfHearts = fiveOfSpades;
    ASSERT_EQ(fourOfHearts.suit, 'S');
}

TEST(CardTests, AssignmentOperator) {
    Game::Card fourOfHearts = Game::Card(4, 'H');
    Game::Card fiveOfSpades = Game::Card(5, 'S');
    fourOfHearts = fiveOfSpades;
    ASSERT_EQ(fourOfHearts.suit, 'S');
}

TEST(CardTests, PutToOperator) {
    Game::Card fourOfHearts = Game::Card(4, 'H');
    cout << "\n" << fourOfHearts << endl;
}

TEST(CardTests, EqualsOperator) {
    Game::Card fourOfHearts1 = Game::Card(4, 'H');
    Game::Card fourOfHearts2 = Game::Card(4, 'H');
    ASSERT_TRUE(fourOfHearts1 == fourOfHearts2);
}

TEST(CardTests, NotEqualsOperator) {
    Game::Card fourOfHearts = Game::Card(4, 'H');
    Game::Card twoOfDiamonds = Game::Card(2, 'D');
    ASSERT_TRUE(fourOfHearts != twoOfDiamonds);
}

TEST(CardTests, GreaterThan) {
    Game::Card fourOfHearts = Game::Card(4, 'H');
    Game::Card fiveOfHearts = Game::Card(5, 'H');
    ASSERT_TRUE(fiveOfHearts > fourOfHearts);
}

TEST(CardTests, LessThan) {
    Game::Card fourOfHearts = Game::Card(4, 'H');
    Game::Card fiveOfHearts = Game::Card(5, 'H');
    ASSERT_TRUE(fourOfHearts < fiveOfHearts);
}

TEST(CardTests, GreaterThanOrEquals) {
    Game::Card fourOfHearts1 = Game::Card(4, 'H');
    Game::Card fourOfHearts2 = Game::Card(4, 'H');
    Game::Card fourOfDiamonds = Game::Card(4, 'D');
    Game::Card fiveOfHearts = Game::Card(5, 'H');
    ASSERT_TRUE(fourOfHearts2 >= fourOfHearts1);
    ASSERT_TRUE(fiveOfHearts >= fourOfHearts1);
    ASSERT_TRUE(fiveOfHearts >= fourOfDiamonds);
}
TEST(CardTests, LessrThanOrEquals) {
    Game::Card fourOfHearts1 = Game::Card(4, 'H');
    Game::Card fourOfHearts2 = Game::Card(4, 'H');
    Game::Card fourOfDiamonds = Game::Card(4, 'D');
    Game::Card threeOfHearts = Game::Card(3, 'H');
    ASSERT_TRUE(fourOfHearts2 <= fourOfHearts1);
    ASSERT_TRUE(threeOfHearts <= fourOfHearts1);
    ASSERT_FALSE(fourOfHearts1 <= fourOfDiamonds);
}

TEST(CardCollectionTests, CardCollection) {
    Game::Card fourOfHearts1 = Game::Card(4, 'H');
    Game::Card fourOfHearts2 = Game::Card(4, 'H');
    Game::CardCollection();


}














