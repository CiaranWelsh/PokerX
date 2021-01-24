/**
 * Integration tests for PokerEngine
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "PokerX/PokerX.h"


using namespace pokerx;


class PokerEngineIntegrationTests : public ::testing::Test {

public:
    PlayerManager playerManager = PlayerManager::populate<CallStationPlayer>(6, 1000.0);

    GameVariables gameVariables;

    unique_ptr<PokerEngine> engine = nullptr;

    PokerEngineIntegrationTests(){
        engine = std::make_unique<PokerEngine>(&playerManager, &gameVariables);

    };

    /**
     * @brief turns a game of poker by calling the PokerEngine::action
     * method @param times times then checks its State against @param state
     * Test passes if they are equal
     */
    void checkPokerEngineIsInCorrectState(int times, int state) {
        PokerEngine engine1(&playerManager, &gameVariables);

        engine1.action(times);
        ASSERT_EQ(state, engine1.getState()->getType());
    }

};


TEST_F(PokerEngineIntegrationTests, MakeSureTheDefaultStartingStateIsReset) {
    checkPokerEngineIsInCorrectState(0, RESET_STATE);
}


TEST_F(PokerEngineIntegrationTests, AssertSmallBlindSubtractsFromStack) {
    engine->setState(SmallBlind::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), SMALL_BLIND_STATE);

    engine->action(NONE);

    ASSERT_EQ(engine->getPlayers()->getCurrentPlayer()->getStack(), 999);
    ASSERT_EQ(engine->getGameVariables()->getPot(), 1);

//    ASSERT_EQ(engine->getPlayers()->getCurrentPlayerIdx(), 1);
}

TEST_F(PokerEngineIntegrationTests, AssertBigBlindSubtractsFromStack) {
    engine->setState(BigBlind::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), BIG_BLIND_STATE);

    engine->action(NONE);

    ASSERT_EQ(engine->getPlayers()->getCurrentPlayer()->getStack(), 998);
    ASSERT_EQ(engine->getGameVariables()->getPot(), 2);

}

TEST_F(PokerEngineIntegrationTests, Preflop) {
    engine->setState(PreflopBetting::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PREFLOP_STATE);

    engine->action(NONE);


}




//TEST_F(PokerEngineIntegrationTests, CallActionOnceAndChangeStateToButtonMoves) {
//    checkPokerEngineIsInCorrectState(1, BUTTON_MOVES_STATE);
//}
//
//TEST_F(PokerEngineIntegrationTests, CallAction2TimesAndChangeStateToSmallBlind) {
//    checkPokerEngineIsInCorrectState(2, SMALL_BLIND_STATE);
//}
//
//TEST_F(PokerEngineIntegrationTests, CallAction3TimesAndChangeStateToBigBlind) {
//    checkPokerEngineIsInCorrectState(3, BIG_BLIND_STATE);
//}
//
//
//TEST_F(PokerEngineIntegrationTests, CallAction4TimesAndChangeStateToPreflop) {
//    checkPokerEngineIsInCorrectState(4, PREFLOP_STATE);
//}
//
//TEST_F(PokerEngineIntegrationTests, CallAction5TimesAndChangeStateToFlop) {
//    checkPokerEngineIsInCorrectState(5, FLOP_STATE);
//}
//
//TEST_F(PokerEngineIntegrationTests, CallAction6TimesAndChangeStateToTurn) {
//    checkPokerEngineIsInCorrectState(6, TURN_STATE);
//}
//
//TEST_F(PokerEngineIntegrationTests, CallAction7TimesAndChangeStateToRiver) {
//    checkPokerEngineIsInCorrectState(7, RIVER_STATE);
//}
//
//TEST_F(PokerEngineIntegrationTests, CallAction8TimesAndChangeStateToShowdown) {
//    checkPokerEngineIsInCorrectState(8, SHOWDOWN_STATE);
//}
//
//TEST_F(PokerEngineIntegrationTests, CallAction9TimesAndChangeStateBackToReset) {
//    checkPokerEngineIsInCorrectState(9, RESET_STATE);
//}
//
//
//TEST_F(PokerEngineIntegrationTests, CheckThatWeCanUseSetStateProperly) {
//    engine->setState(SmallBlind::getInstance());
//    ASSERT_EQ(engine->getState(), SMALL_BLIND_STATE);
//}


























