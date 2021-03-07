#include <utility>
#include <PokerX/engine/SmallBlind.h>
#include <PokerX/engine/BigBlind.h>
#include <PokerX/engine/DealHoleCards.h>
#include <PokerX/engine/Deck.h>
#include <PokerX/engine/HoleCards.h>

#include "gtest/gtest.h"
#include "Mockups/MockGameVariables.h"
#include "Mockups/MockPlayerManager.h"
#include "Mockups/MockPlayer.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/Pot.h" // not mocked. Too simple.

// state includes
#include "PokerX/engine/Reset.h"
#include "PokerX/engine/ButtonMoves.h"

/**
 * This set of tests focuses on
 * testing the poker engine up to preflop
 * stage of the game. We use mocked versions
 * of the GameVariables, PlayerManager and Player
 * types but the real version of poker engine States.
 * I.e. the States are considered a part of this test
 * as they need to be doing the right thing
 */


class PreflopTests : public ::testing::Test {
public:
    MockGameVariables gameVariables;
    MockPlayerManager playerManager;
    std::shared_ptr<MockPlayer> p1;
    std::shared_ptr<MockPlayer> p2;
    std::shared_ptr<MockPlayer> p3;
    std::shared_ptr<MockPlayer> p4;
    std::shared_ptr<MockPlayer> p5;
    std::shared_ptr<MockPlayer> p6;

    PreflopTests() {
        p1 = makePlayer("DrLevty", 10.01);
        p2 = makePlayer("OhhhJeee", 4.86);
        p3 = makePlayer("gokudousan", 5.81);
        p4 = makePlayer("aka_Kranv1ch", 10);
        p5 = makePlayer("Malyar-88", 3.97);
        p6 = makePlayer("Lorn_Antoan", 10.25);

        // set the button
        ON_CALL(playerManager, getButton)
                .WillByDefault(Return(p1));
        ON_CALL(playerManager, getSmallBlind)
                .WillByDefault(Return(p2));
        ON_CALL(playerManager, getBigBlind)
                .WillByDefault(Return(p3));

        // define what playerManager returns when call to getPlayer
        ON_CALL(playerManager, getPlayer(1))
            .WillByDefault(Return(p1));
        ON_CALL(playerManager, getPlayer(2))
            .WillByDefault(Return(p2));
        ON_CALL(playerManager, getPlayer(3))
            .WillByDefault(Return(p3));
        ON_CALL(playerManager, getPlayer(4))
            .WillByDefault(Return(p4));
        ON_CALL(playerManager, getPlayer(5))
            .WillByDefault(Return(p5));
        ON_CALL(playerManager, getPlayer(6))
            .WillByDefault(Return(p6));

        EXPECT_CALL(playerManager, watch)
                .Times(1); // always gets called once
        EXPECT_CALL(playerManager, nextPlayer)
            .Times(AnyNumber());
    };

    std::shared_ptr<MockPlayer> makePlayer(const std::string &name, float stack) {
        std::shared_ptr<MockPlayer> p = std::make_shared<MockPlayer>();
        ON_CALL(*p, getName)
                .WillByDefault(ReturnRef(name));
        ON_CALL(*p, getStack)
                .WillByDefault(Return(stack));
        return p;
    }
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
    EXPECT_CALL(playerManager, watch).Times(1);
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
    ON_CALL(playerManager, getCurrentPlayer)
            .WillByDefault(Return(p1));

    ON_CALL(gameVariables, numGamesPlayed)
            .WillByDefault(Return(0));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(ButtonMoves::getInstance());

    ASSERT_EQ(engine.getState()->getType(), BUTTON_MOVES_STATE);

    engine.action(1);

    ASSERT_EQ(SMALL_BLIND_STATE, engine.getState()->getType());

}

TEST_F(PreflopTests, CheckEngineCallsButtonMovesSecondTime) {
    ON_CALL(playerManager, getCurrentPlayer)
            .WillByDefault(Return(p1));

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
            .WillRepeatedly(Return(p2));

    EXPECT_CALL(*p2, postSmallBlind)
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
            .WillRepeatedly(Return(p3));

    EXPECT_CALL(*p3, postBigBlind)
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
            .WillRepeatedly(Return(p4)); // UTG player

    Deck deck;
    EXPECT_CALL(gameVariables, getDeck)
        .Times(1)
        .WillRepeatedly(ReturnRef(deck));

    HoleCards hc1;
    EXPECT_CALL(*p1, getHoleCards)
        .WillRepeatedly(ReturnRef(hc1));
    HoleCards hc2;
    EXPECT_CALL(*p2, getHoleCards)
        .WillRepeatedly(ReturnRef(hc2));
    HoleCards hc3;
    EXPECT_CALL(*p3, getHoleCards)
        .WillRepeatedly(ReturnRef(hc3));
    HoleCards hc4;
    EXPECT_CALL(*p4, getHoleCards)
        .WillRepeatedly(ReturnRef(hc4));
    HoleCards hc5;
    EXPECT_CALL(*p5, getHoleCards)
        .WillRepeatedly(ReturnRef(hc5));
    HoleCards hc6;
    EXPECT_CALL(*p6, getHoleCards)
        .WillRepeatedly(ReturnRef(hc6));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(DealHoleCards::getInstance());

    engine.action(1);

    ASSERT_EQ(engine.getState()->getType(), START_STREET_STATE);

}
























