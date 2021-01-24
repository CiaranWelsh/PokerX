/**
 * Integration tests for PokerEngine
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "PokerX/PokerX.h"


using namespace pokerx;


class PokerEngineIntegrationTests : public ::testing::Test {

public:
    PlayerManager playerManager = PlayerManager::populate<CallStationPlayer>(5, 1000.0);

    GameVariables gameVariables;

    unique_ptr<PokerEngine> engine = nullptr;

    RaiserPlayer raiser;

    PokerEngineIntegrationTests(){
        playerManager.add(std::make_shared<RaiserPlayer>(raiser));
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

TEST_F(PokerEngineIntegrationTests, CheckPlayerToActErrorsWhenUserPicksNONEAction) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    ASSERT_THROW(
            engine->action(NONE),
            std::logic_error
    );
}

TEST_F(PokerEngineIntegrationTests, CheckPlayerToAct) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action(CHECK);
}

TEST_F(PokerEngineIntegrationTests, CheckPlayerToActCheck) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action(CHECK);
}

TEST_F(PokerEngineIntegrationTests, CheckPlayerToActCall) {
    engine->setState(PlayerToAct::getInstance());

    // we manafacture an existing amount to call for test purposes
    engine->getGameVariables()->setAmountToCall(20.0);

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action(CALL);

    ASSERT_EQ(980, engine->getPlayers()->getCurrentPlayer()->getStack());
    ASSERT_EQ(20, engine->getGameVariables()->getAmountToCall());
    ASSERT_EQ(20, engine->getGameVariables()->getPot());
}

TEST_F(PokerEngineIntegrationTests, CheckPlayerToActFold) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action(FOLD);

    ASSERT_EQ(1000, engine->getPlayers()->getCurrentPlayer()->getStack());
    ASSERT_EQ(0, engine->getGameVariables()->getAmountToCall());
    ASSERT_EQ(0, engine->getGameVariables()->getPot());
    ASSERT_TRUE(engine->getPlayers()->getCurrentPlayer()->hasFolded());
}

TEST_F(PokerEngineIntegrationTests, CheckPlayerToActRaise) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerIdx(5);

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action(RAISE);

    ASSERT_EQ(20, engine->getGameVariables()->getAmountToCall());
    ASSERT_EQ(60, engine->getGameVariables()->getPot());
    ASSERT_EQ(960, engine->getPlayers()->getCurrentPlayer()->getStack());
//    ASSERT_TRUE(engine->getPlayers()->getCurrentPlayer()->hasFolded());
}


TEST_F(PokerEngineIntegrationTests, CheckPlayerToActAllIn) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action(ALL_IN);
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


























