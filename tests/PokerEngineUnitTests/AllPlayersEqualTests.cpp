#include <PokerX/engine/PlayerToAct.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/AllPlayersEqual.h"


#include "PokerEngineTests.h"

class AllPlayersEqualTests : public PokerEngineTests {
public:

    AllPlayersEqualTests() = default;
};


TEST_F(AllPlayersEqualTests, PlayersAreEqualAndAllPlayersHaveActed) {
    ON_CALL(*utg, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*hj, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*co, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(playerManager, getNumPlayersStillInPot)
            .WillByDefault(Return(3));

    ON_CALL(playerManager, allPlayersEqual)
            .WillByDefault(Return(true));

    ON_CALL(playerManager, allPlayersTakenAtLeastOneTurn)
            .WillByDefault(Return(true));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(AllPlayersEqual::getInstance());

    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);

}

TEST_F(AllPlayersEqualTests, PlayersAreEqualButBBStillToAct) {
    ON_CALL(*btn, getAmountContrib)
            .WillByDefault(Return(0.1));

    ON_CALL(*sb, getAmountContrib)
            .WillByDefault(Return(0.1));

    ON_CALL(*bb, getAmountContrib)
            .WillByDefault(Return(0.01));

    // bb is yet to check.
    ON_CALL(*bb, getNumActionsThisStreet)
            .WillByDefault(Return(0));

    ON_CALL(*utg, getAmountContrib)
            .WillByDefault(Return(0.1));

    ON_CALL(*hj, getAmountContrib)
            .WillByDefault(Return(0.1));

    ON_CALL(*co, getAmountContrib)
            .WillByDefault(Return(0.1));

    ON_CALL(playerManager, getNumPlayersStillInPot)
            .WillByDefault(Return(6));

    ON_CALL(playerManager, allPlayersEqual)
            .WillByDefault(Return(true));

    ON_CALL(playerManager, allPlayersTakenAtLeastOneTurn)
            .WillByDefault(Return(false));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(AllPlayersEqual::getInstance());

    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), PLAYER_TO_ACT_STATE);

}

TEST_F(AllPlayersEqualTests, PlayersAreNotEqual) {
    ON_CALL(*btn, getAmountContrib)
            .WillByDefault(Return(0.1));
    ON_CALL(*sb, getAmountContrib)
            .WillByDefault(Return(0.2));
    ON_CALL(*bb, getAmountContrib)
            .WillByDefault(Return(0.3));
    ON_CALL(*bb, getAmountContrib)
            .WillByDefault(Return(0.4));
    ON_CALL(*bb, getAmountContrib)
            .WillByDefault(Return(0.5));
    ON_CALL(*bb, getAmountContrib)
            .WillByDefault(Return(0.6));

    ON_CALL(playerManager, getNumPlayersStillInPot)
            .WillByDefault(Return(6));

    ON_CALL(playerManager, allPlayersEqual)
            .WillByDefault(Return(false));

    ON_CALL(playerManager, allPlayersTakenAtLeastOneTurn)
            .WillByDefault(Return(false));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(AllPlayersEqual::getInstance());

    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), PLAYER_TO_ACT_STATE);
}


TEST_F(AllPlayersEqualTests, AllButOnePlayerHasFolded) {
    ON_CALL(*btn, hasFolded)
            .WillByDefault(Return(false));

    ON_CALL(*sb, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*bb, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*utg, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*hj, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*co, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(playerManager, getNumPlayersStillInPot)
            .WillByDefault(Return(1));

    ON_CALL(playerManager, allPlayersEqual)
            .WillByDefault(Return(false));

    ON_CALL(playerManager, allPlayersTakenAtLeastOneTurn)
            .WillByDefault(Return(false));

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(AllPlayersEqual::getInstance());

    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), SHOWDOWN_STATE);
}

TEST_F(AllPlayersEqualTests, AllInAllPlayers) {
    ON_CALL(*btn, isAllIn)
            .WillByDefault(Return(true));

    ON_CALL(*sb, isAllIn)
            .WillByDefault(Return(true));

    ON_CALL(*bb, isAllIn)
            .WillByDefault(Return(true));

    ON_CALL(*utg, isAllIn)
            .WillByDefault(Return(true));

    ON_CALL(*hj, isAllIn)
            .WillByDefault(Return(true));

    ON_CALL(*co, isAllIn)
            .WillByDefault(Return(true));

    EXPECT_CALL(playerManager, allPlayersEqual)
            .WillRepeatedly(Return(false));

    EXPECT_CALL(playerManager, allPlayersTakenAtLeastOneTurn)
            .WillRepeatedly(Return(false));

    EXPECT_CALL(playerManager, numPlayersAllIn)
            .WillRepeatedly(Return(2));

    EXPECT_CALL(playerManager, getNumPlayersStillInPot)
            .WillRepeatedly(Return(2));

    EXPECT_CALL(gameVariables, getStreet)
            .WillOnce(Return(PREFLOP_STREET))
            .WillOnce(Return(FLOP_STREET))
            .WillOnce(Return(FLOP_STREET))
            .WillOnce(Return(TURN_STREET))
            .WillOnce(Return(TURN_STREET))
            .WillOnce(Return(RIVER_STREET))
            .WillOnce(Return(RIVER_STREET));

    EXPECT_CALL(gameVariables, allInMode)
            .WillRepeatedly(Return(true));
    EXPECT_CALL(gameVariables, setAllInMode(true));
//
//    std::vector<ICardPtr> inj(5);
//    inj[0] = CardFactory("5d");
//    inj[1] = CardFactory("9c");
//    inj[2] = CardFactory("Ah");
//    inj[3] = CardFactory("3s");
//    inj[4] = CardFactory("4s");
//    EXPECT_CALL(gameVariables, getInjectedCommunityCards)
//            .WillRepeatedly(ReturnRef(inj));

    std::unordered_map<std::string, Hand> remainingHands{
            {"btn", Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "As", "3D"}))},
            {"sb",  Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "5h", "6h"}))},
            {"bb",  Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "9h", "6d"}))},
            {"utg", Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "TH", "Td"}))},
            {"hj", Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "Jc", "2C"}))},
            {"co", Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "3C", "5C"}))},
    };

    EXPECT_CALL(playerManager, getRemainingPlayerHands)
        .WillRepeatedly(Return(remainingHands));

    Pot pot(6*100);
    EXPECT_CALL(gameVariables, getPot)
        .WillRepeatedly(ReturnRef(pot));

    EXPECT_CALL(playerManager, getPlayerByName)
        .WillRepeatedly(Return(btn));

    EXPECT_CALL(gameVariables, getN)
        .WillRepeatedly(Return(1));
    EXPECT_CALL(gameVariables, numGamesPlayed)
        .WillRepeatedly(Return(0));

    EXPECT_CALL(*btn, setStack)
        .Times(1);

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(AllPlayersEqual::getInstance());



    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), DEAL_FLOP_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), START_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), DEAL_TURN_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), START_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), DEAL_RIVER_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), START_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), SHOWDOWN_STATE);
    engine.action(1);




}

/**
 * Hand starts in turn, sb to call an all in from the btn.
 * The sb calls, theother players have folded so the game
 * continues through to showdown where the btn wins with aces.
 */
TEST_F(AllPlayersEqualTests, OnePlayerAllInOnePlayerCall) {
    ON_CALL(*btn, isAllIn)
            .WillByDefault(Return(true));

    ON_CALL(*sb, isAllIn)
            .WillByDefault(Return(false));

    ON_CALL(*btn, getStack)
            .WillByDefault(Return(10));

    ON_CALL(*sb, getStack)
            .WillByDefault(Return(15));

    ON_CALL(*bb, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*utg, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*hj, hasFolded)
            .WillByDefault(Return(true));

    ON_CALL(*co, hasFolded)
            .WillByDefault(Return(true));

    EXPECT_CALL(playerManager, allPlayersEqual)
            .WillRepeatedly(Return(false));

    EXPECT_CALL(playerManager, allPlayersTakenAtLeastOneTurn)
            .WillRepeatedly(Return(false));

    EXPECT_CALL(playerManager, numPlayersAllIn)
            .WillRepeatedly(Return(2));

    EXPECT_CALL(playerManager, getNumPlayersStillInPot)
            .WillRepeatedly(Return(2));

    EXPECT_CALL(playerManager, getButton)
            .WillRepeatedly(Return(btn));

    EXPECT_CALL(gameVariables, getStreet)
        .WillOnce(Return(TURN_STREET))
        .WillOnce(Return(TURN_STREET))
        .WillOnce(Return(RIVER_STREET));

    ON_CALL(playerManager, getCurrentPlayerIdx)
        .WillByDefault(Return(1));

    ON_CALL(playerManager, getCurrentPlayer)
        .WillByDefault(Return(sb));

    std::unordered_map<std::string, Hand> remainingHands{
            {"btn", Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "As", "3D"}))},
            {"sb",  Hand(std::vector<std::string>({"5d", "9c", "Ah", "3s", "4s", "5h", "6h"}))},
    };

    EXPECT_CALL(playerManager, getRemainingPlayerHands)
            .WillRepeatedly(Return(remainingHands));

    EXPECT_CALL(*sb, selectAction)
        .WillOnce(Return(CALL));

    ON_CALL(*sb, getNumActionsThisStreet)
        .WillByDefault(Return(1));

    ON_CALL(*btn, getNumActionsThisStreet)
        .WillByDefault(Return(2));

    EXPECT_CALL(gameVariables, setAllInMode(true))
        .Times(1);

    ON_CALL(gameVariables, allInMode)
        .WillByDefault(Return(true));

    Pot pot(25); // value does not matter
    EXPECT_CALL(gameVariables, getPot)
        .WillRepeatedly(ReturnRef(pot));

    EXPECT_CALL(playerManager, getPlayerByName)
        .WillRepeatedly(Return(btn));
    EXPECT_CALL(*btn, setStack)
        .Times(1);


    PokerEngine engine(&playerManager, &gameVariables);

    engine.setState(PlayerToAct::getInstance());
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), DEAL_RIVER_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), START_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), NEXT_STREET_STATE);
    engine.action(1);
    ASSERT_EQ(engine.getState()->getType(), SHOWDOWN_STATE);
    engine.action(1);

}

/**
 * A simple split pot game:
 *
 * If there are four players in the hand and Player 1 is all-in with his
 * last INR 100, the most he could win is 4 X INR 100. So at the end of
 * the betting round, take INR 400 and put it aside as "Player 1's Pot".
 * He can win that pot, and that pot alone. Then play continues as usual
 * with everyone else competing for both pots. Suppose later in that hand
 * Player 2 is faced with a INR 600 bet, and puts in his last INR 200,
 * going all-in. At the end of the betting round, Player 2 and everyone
 * else puts INR 200 into their pot. Now that pot is "Player 2's Pot".
 * The change goes into a third pot, and play proceeds as usual. After
 * all the cards are dealt and the showdown takes place, the pots are
 * awarded in reverse order. The last two players who stayed in till the
 * end show their cards and the winner takes the third pot. Then Player 2
 * gets to show his hand against those two, and the winner takes "Player
 * 2's pot" then Player 1 gets to show his hand against all three opponents,
 * and the winner gets "Player 1's pot".
 */
TEST_F(AllPlayersEqualTests, OnePlayerAllInTwoPlayersCall) {

}






















