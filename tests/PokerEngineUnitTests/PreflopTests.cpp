#include <PokerX/engine/ButtonMoves.h>
#include <PokerX/engine/SmallBlind.h>
#include <PokerX/engine/BigBlind.h>
#include <PokerX/engine/DealHoleCards.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerEngineTests.h"
#include "PokerX/engine/PokerEngine.h"


class PreflopTests : public PokerEngineTests {
public:
    using PokerEngineTests::PokerEngineTests;
};

/**
 * PokerStars Hand #222947450188:  Hold'em No Limit ($0.05/$0.10 USD) - 2021/01/23 3:08:58 ET
 * Table 'Aaryn II' 6-max Seat #1 is the button
 * Seat 1: DrLevty ($10.01 in chips)
 * Seat 2: Ohhh Jeee ($4.86 in chips)
 * Seat 3: gokudousan ($8.51 in chips)
 * Seat 4: aka_Kranv1ch ($10 in chips)
 * Seat 5: Malyar-88 ($3.97 in chips)
 * Seat 6: Lord_Antoan ($10.25 in chips)
 * Ohhh Jeee: posts small blind $0.05
 * gokudousan: posts big blind $0.10
 */
TEST_F(PreflopTests, CheckEngineCallsReset) {

    // first call to action resets the game, calls watch for initialize observer
    // and gets the next player ready.
    EXPECT_CALL(gameVariables, reset).Times(1);
    EXPECT_CALL(playerManager, reset).Times(1);
    // (remember that reset is tested in the units for
    // gamevariables and playerManager separetly, they are
    // not under test here so assume they work correctly)

    PokerEngine engine(&playerManager, &gameVariables);

    EXPECT_CALL(playerManager, nextPlayer);

    engine.action(1);
    // note: the actual consequences of calling reset are tested elsewhere
    // here we onnly ensure the interconnectively between engine and
    // the reset state is what we expect.

    ASSERT_EQ(engine.getState()->getType(), BUTTON_MOVES_STATE);

}

/**
 * @brief the first time button moves is called, it is assumed
 * that we are on game 0, and we have just started so the player
 * who is currently the button, should stay the button.
 * When numGamesPlayer > 0, move button will actually move the button,
 * and this is the subject of CheckEngineCallsButtonMovesSecondTime
 */
TEST_F(PreflopTests, CheckEngineCallsButtonMovesFirstTime) {
    Deck deck;
    EXPECT_CALL(playerManager, getCurrentPlayer)
            .WillRepeatedly(Return(btn));

    EXPECT_CALL(gameVariables, numGamesPlayed)
            .WillRepeatedly(Return(0));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(ButtonMoves::getInstance());

    ASSERT_EQ(engine.getState()->getType(), BUTTON_MOVES_STATE);

    engine.action(1);

    ASSERT_EQ(SMALL_BLIND_STATE, engine.getState()->getType());

}

TEST_F(PreflopTests, CheckEngineCallsButtonMovesSecondTime) {
    ON_CALL(playerManager, getCurrentPlayer)
            .WillByDefault(Return(btn));

    ON_CALL(gameVariables, numGamesPlayed)
            .WillByDefault(Return(1));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(ButtonMoves::getInstance());

    ASSERT_EQ(engine.getState()->getType(), BUTTON_MOVES_STATE);

    EXPECT_CALL(playerManager, moveButton).Times(1);

    engine.action(1);

    ASSERT_EQ(SMALL_BLIND_STATE, engine.getState()->getType());
}

TEST_F(PreflopTests, CheckEngineCallsSmallBlind) {
    EXPECT_CALL(playerManager, getCurrentPlayer)
            .WillRepeatedly(Return(sb));

    EXPECT_CALL(*sb, postSmallBlind)
            .Times(1);

    EXPECT_CALL(gameVariables, getSmallBlind)
            .WillRepeatedly(Return(0.05));

    EXPECT_CALL(gameVariables, getCurrencySymbol)
            .WillRepeatedly(Return("$"));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(SmallBlind::getInstance());

    ASSERT_EQ(engine.getState()->getType(), SMALL_BLIND_STATE);

    engine.action(1);

    ASSERT_EQ(BIG_BLIND_STATE, engine.getState()->getType());

}

TEST_F(PreflopTests, CheckEngineCallsBigBlind) {
    EXPECT_CALL(playerManager, getCurrentPlayer)
            .WillRepeatedly(Return(bb));

    EXPECT_CALL(*bb, postBigBlind)
            .Times(1);

    EXPECT_CALL(gameVariables, getBigBlind)
            .WillRepeatedly(Return(0.1));

    EXPECT_CALL(gameVariables, getCurrencySymbol)
            .WillRepeatedly(Return("$"));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(BigBlind::getInstance());

    ASSERT_EQ(engine.getState()->getType(), BIG_BLIND_STATE);

    engine.action(1);

    ASSERT_EQ(DEAL_HOLE_CARDS_STATE, engine.getState()->getType());
}

TEST_F(PreflopTests, CheckDealHoleCards) {
    EXPECT_CALL(playerManager, getCurrentPlayer)
            .WillRepeatedly(Return(utg)); // UTG player

    Deck deck;
    EXPECT_CALL(gameVariables, getDeck)
        .Times(1)
        .WillRepeatedly(ReturnRef(deck));

    HoleCards hc1;
    EXPECT_CALL(*btn, getHoleCards)
        .WillRepeatedly(ReturnRef(hc1));
    HoleCards hc2;
    EXPECT_CALL(*sb, getHoleCards)
        .WillRepeatedly(ReturnRef(hc2));
    HoleCards hc3;
    EXPECT_CALL(*bb, getHoleCards)
        .WillRepeatedly(ReturnRef(hc3));
    HoleCards hc4;
    EXPECT_CALL(*utg, getHoleCards)
        .WillRepeatedly(ReturnRef(hc4));
    HoleCards hc5;
    EXPECT_CALL(*hj, getHoleCards)
        .WillRepeatedly(ReturnRef(hc5));
    HoleCards hc6;
    EXPECT_CALL(*co, getHoleCards)
        .WillRepeatedly(ReturnRef(hc6));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(DealHoleCards::getInstance());

    engine.action(1);

    ASSERT_EQ(engine.getState()->getType(), START_STREET_STATE);

}
























