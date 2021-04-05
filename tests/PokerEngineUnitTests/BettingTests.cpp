//
// Created by Ciaran Welsh on 07/03/2021.
//

#ifndef POKERX_BETTINGTESTS_CPP
#define POKERX_BETTINGTESTS_CPP

#include "PokerEngineTests.h"
#include "PokerX/engine/PlayerToAct.h"

class BettingTests : public PokerEngineTests {
public:
    BettingTests() : PokerEngineTests(){

    }
};

class PreflopUTGBettingTests: public BettingTests {
public:
    PreflopUTGBettingTests() : BettingTests(){

    }

    void setPreflopUTGExpectations (){}
};

TEST_F(PreflopUTGBettingTests, CheckPreflopUTGCanCall) {
    // set street to preflop
    ON_CALL(gameVariables, getStreet)
        .WillByDefault(Return(PREFLOP_STREET));
    EXPECT_CALL(playerManager, getCurrentPlayer)
        .WillRepeatedly(Return(utg));

    EXPECT_CALL(gameVariables, setBetPlaced)
        .Times(1);

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());

    EXPECT_CALL(*utg, selectAction(A<StateMachine*>()))
        .Times(1)
        .WillRepeatedly(Return(CALL));

    EXPECT_CALL(*utg, call())
        .Times(1);

    EXPECT_CALL(*utg, getGameVariables)
        .WillRepeatedly(Return(&gameVariables));

    EXPECT_CALL(gameVariables, getAmountToCall)
        .WillRepeatedly(Return(0.1)); // big blinds


    ASSERT_EQ(PLAYER_TO_ACT_STATE, engine.getState()->getType());

    engine.action(1);

    ASSERT_EQ(ALL_PLAYERS_EQUAL_STATE, engine.getState()->getType());
}

TEST_F(PreflopUTGBettingTests, CheckPreflopUTGCanCHECK) {
    // set street to preflop
    ON_CALL(gameVariables, getStreet)
        .WillByDefault(Return(PREFLOP_STREET));
    EXPECT_CALL(playerManager, getCurrentPlayer)
        .WillRepeatedly(Return(utg));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());

    EXPECT_CALL(*utg, selectAction(A<StateMachine*>()))
        .Times(1)
        .WillRepeatedly(Return(CHECK));

    EXPECT_CALL(*utg, check())
        .Times(1);

    EXPECT_CALL(*utg, getGameVariables)
        .WillRepeatedly(Return(&gameVariables));

    EXPECT_CALL(gameVariables, getAmountToCall)
        .WillRepeatedly(Return(0.1)); // big blinds

    ASSERT_EQ(PLAYER_TO_ACT_STATE, engine.getState()->getType());

    engine.action(1);

    ASSERT_EQ(ALL_PLAYERS_EQUAL_STATE, engine.getState()->getType());
}

TEST_F(PreflopUTGBettingTests, CheckPreflopUTGCanFold) {
    // set street to preflop
    ON_CALL(gameVariables, getStreet)
        .WillByDefault(Return(PREFLOP_STREET));
    EXPECT_CALL(playerManager, getCurrentPlayer)
        .WillRepeatedly(Return(utg));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());

    EXPECT_CALL(*utg, selectAction(A<StateMachine*>()))
        .Times(1)
        .WillRepeatedly(Return(FOLD));

    EXPECT_CALL(*utg, fold())
        .Times(1);

    EXPECT_CALL(*utg, getGameVariables)
        .WillRepeatedly(Return(&gameVariables));

    EXPECT_CALL(gameVariables, getAmountToCall)
        .WillRepeatedly(Return(0.1)); // big blinds

    ASSERT_EQ(PLAYER_TO_ACT_STATE, engine.getState()->getType());

    engine.action(1);

    ASSERT_EQ(ALL_PLAYERS_EQUAL_STATE, engine.getState()->getType());
}

TEST_F(PreflopUTGBettingTests, CheckPreflopUTGCanRaise) {
    // set street to preflop
    ON_CALL(gameVariables, getStreet)
        .WillByDefault(Return(PREFLOP_STREET));
    EXPECT_CALL(playerManager, getCurrentPlayer)
        .WillRepeatedly(Return(utg));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());

    // Nobody has bet yet, so hasBetBeenPlaced is still false.
    EXPECT_CALL(gameVariables, hasBetBeenPlaced)
        .Times(1)
        .WillRepeatedly(Return(false));

    EXPECT_CALL(gameVariables, setAmountToCall)
        .Times(1);

    EXPECT_CALL(gameVariables, setBetPlaced)
        .Times(1);

    EXPECT_CALL(*utg, selectAction(A<StateMachine*>()))
        .Times(1)
        .WillRepeatedly(Return(RAISE));

    EXPECT_CALL(*utg, raise())
        .Times(1);

    // doRaise is called by subclasses implementing the raise method
    // as a way of not needing the amount as argument to raise()
    // therefore in this test it is not called
    //EXPECT_CALL(*utg, doRaise(0.3))
    //    .Times(1);

    EXPECT_CALL(*utg, getGameVariables)
        .WillRepeatedly(Return(&gameVariables));

    EXPECT_CALL(gameVariables, getAmountToCall)
        .WillRepeatedly(Return(0.1)); // big blinds

    ASSERT_EQ(PLAYER_TO_ACT_STATE, engine.getState()->getType());

    engine.action(1);

    ASSERT_EQ(ALL_PLAYERS_EQUAL_STATE, engine.getState()->getType());
}

class StreetTransitionTests : public BettingTests{};

/**
 * Checks the determining of whether to move to next street
 * based on equality between players amounts in play
 */
TEST_F(StreetTransitionTests, TransitionWhenAllPlayersAreEqual) {

    // everyone has called
    ON_CALL(playerManager, allPlayersEqual)
        .WillByDefault(Return(true));

    ON_CALL(gameVariables, getAmountToCall)
        .WillByDefault(Return(0.1));

    Pot pot(0.1*6);
    ON_CALL(gameVariables, getPot)
        .WillByDefault(ReturnRef(pot));

    // who's turn to act? Person after big blind is first to act
    // in Flop. BB is last to act in preflop
    // so big blind checks
    ON_CALL(playerManager, getCurrentPlayer)
        .WillByDefault(Return(bb));

    ON_CALL(*bb, selectAction)
        .WillByDefault(Return(CHECK));

    ON_CALL(playerManager, allPlayersTakenAtLeastOneTurn)
        .WillByDefault(Return(true));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());

    engine.action(1);

    // We've turned state into AllPlayersEqual
    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);

    // another action switches to next street
    engine.action(1);

    // now were in the next street state.
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);

    // The next action actual performs the switch to FLOP. But we cannot test it
    // here because gameVariables is mocked object (and so call to getStreet not fully
    // operational).
}


#endif //POKERX_BETTINGTESTS_CPP
