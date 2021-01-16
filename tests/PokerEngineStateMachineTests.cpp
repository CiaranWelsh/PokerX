//
// Created by Ciaran on 16/01/2021.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "PokerX/engine/PokerEngine.h"

using namespace pokerx;
/**
 * Start state is a reset state.
 */


class PokerEngineStateMachineTests : public ::testing::Test {

public:
    PokerEngineStateMachineTests() = default;

};


TEST_F(PokerEngineStateMachineTests, MakeSureTheDefaultStartingStateIsReset) {
    PokerEngine engine;
    ASSERT_EQ(RESET, engine.getState()->getType());
}


TEST_F(PokerEngineStateMachineTests, CallActionOnceAndChangeStateToButtonMoves) {
    PokerEngine engine;
    engine.action();
    ASSERT_EQ(BUTTON_MOVES, engine.getState()->getType());
}

TEST_F(PokerEngineStateMachineTests, CallAction2TimesAndChangeStateToSmallBlind) {
    PokerEngine engine;
    engine.action();
    engine.action();
    ASSERT_EQ(SMALL_BLIND, engine.getState()->getType());
}

TEST_F(PokerEngineStateMachineTests, CallAction3TimesAndChangeStateToBigBlind) {
    PokerEngine engine;
    engine.action();
    engine.action();
    engine.action();
    ASSERT_EQ(BIG_BLIND, engine.getState()->getType());
}



























