#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Mockups/MockCard.h"

#include "PokerX/engine/GameVariables.h"

using namespace pokerx;

class GameVariablesTests : public ::testing::Test {
public:
    MockCards mockCards;

    GameVariablesTests() = default;
};


TEST_F(GameVariablesTests, CheckDeckHas52Cards) {
    GameVariables variables;
    const Deck &deck = variables.getDeck();
    ASSERT_EQ(52, deck.size());

}



















