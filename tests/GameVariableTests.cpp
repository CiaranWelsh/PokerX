#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/GameVariables.h"

using namespace pokerx;

class GameVariablesTests : public :: testing::Test {
public:
    GameVariablesTests() = default;
};


TEST_F(GameVariablesTests, CheckDeckHas52Cards){
    GameVariables variables;
    const Deck& deck = variables.getDeck();
    ASSERT_EQ(52, deck.size());

}


















