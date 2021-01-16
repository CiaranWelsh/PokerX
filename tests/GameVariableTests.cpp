#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/GameVariables.h"

using namespace pokerx;

class GameVariablesTests : public :: testing::Test {
public:
    GameVariablesTests() = default;
};


TEST_F(GameVariablesTests, test){
    GameVariables variables;
    variables.getPot();

}


















