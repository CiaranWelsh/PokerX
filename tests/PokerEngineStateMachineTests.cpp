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

    /**
     * @brief turns a game of poker by calling the PokerEngine::action
     * method @param times times then checks its State against @param state
     * Test passes if they are equal
     */
    static void checkPokerEngineIsInCorrectState(int times, int state) {
        PokerEngine engine;
        engine.action(times);
        ASSERT_EQ(state, engine.getState()->getType());
    }

};


TEST_F(PokerEngineStateMachineTests, MakeSureTheDefaultStartingStateIsReset) {
    checkPokerEngineIsInCorrectState(0, RESET_STATE);
}


TEST_F(PokerEngineStateMachineTests, CallActionOnceAndChangeStateToButtonMoves) {
    checkPokerEngineIsInCorrectState(1, BUTTON_MOVES_STATE);
}

TEST_F(PokerEngineStateMachineTests, CallAction2TimesAndChangeStateToSmallBlind) {
    checkPokerEngineIsInCorrectState(2, SMALL_BLIND_STATE);
}

TEST_F(PokerEngineStateMachineTests, CallAction3TimesAndChangeStateToBigBlind) {
    checkPokerEngineIsInCorrectState(3, BIG_BLIND_STATE);
}


TEST_F(PokerEngineStateMachineTests, CallAction4TimesAndChangeStateToPreflop) {
    checkPokerEngineIsInCorrectState(4, PREFLOP_STATE);
}

TEST_F(PokerEngineStateMachineTests, CallAction5TimesAndChangeStateToFlop) {
    checkPokerEngineIsInCorrectState(5, FLOP_STATE);
}

TEST_F(PokerEngineStateMachineTests, CallAction6TimesAndChangeStateToTurn) {
    checkPokerEngineIsInCorrectState(6, TURN_STATE);
}

TEST_F(PokerEngineStateMachineTests, CallAction7TimesAndChangeStateToRiver) {
    checkPokerEngineIsInCorrectState(7, RIVER_STATE);
}

TEST_F(PokerEngineStateMachineTests, CallAction8TimesAndChangeStateToShowdown) {
    checkPokerEngineIsInCorrectState(8, SHOWDOWN_STATE);
}

TEST_F(PokerEngineStateMachineTests, CallAction9TimesAndChangeStateBackToReset) {
    checkPokerEngineIsInCorrectState(9, RESET_STATE);
}





























