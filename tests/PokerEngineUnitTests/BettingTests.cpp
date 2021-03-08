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

TEST_F(BettingTests, CheckPreflopUTGCanCall) {
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

TEST_F(BettingTests, CheckPreflopUTGCanCHECK) {
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

TEST_F(BettingTests, CheckPreflopUTGCanFold) {
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

TEST_F(BettingTests, CheckPreflopUTGCanRaise) {
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


TEST_F(BettingTests, CheckErrorIfCheckAfterCall){
    // set street to preflop
    ON_CALL(gameVariables, getStreet)
            .WillByDefault(Return(PREFLOP_STREET));
    // UTG has called the BB
    Pot pot(0.05 + 0.1 + 0.1);
    ON_CALL(gameVariables, getPot)
        .WillByDefault(ReturnRef(pot));
    ON_CALL(gameVariables, getAmountToCall)
        .WillByDefault(Return(0.1));
    ON_CALL(gameVariables, isDone)
        .WillByDefault(Return(false));
    ON_CALL(gameVariables, hasBetBeenPlaced)
        .WillByDefault(Return(true));
    ON_CALL(playerManager, getNumPlayersStillInPot)
        .WillByDefault(Return(6));
    EXPECT_CALL(playerManager, getCurrentPlayer)
            .WillRepeatedly(Return(hj));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());
    ASSERT_EQ(engine.getState()->getType(), PLAYER_TO_ACT_STATE);

    EXPECT_CALL(*hj, selectAction)
        .WillRepeatedly(Return(CHECK));

    EXPECT_CALL(*hj, check)
        .Times(1);
    engine.action(1);

    //ASSERT_THROW(engine.action(1), std::logic_error);


}




#endif //POKERX_BETTINGTESTS_CPP
