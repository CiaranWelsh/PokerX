/**
 * Integration tests for PokerEngine
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "PokerX/PokerX.h"


using namespace pokerx;


class PokerEngineStatesTest : public ::testing::Test {

public:
    PlayerManager playerManager = PlayerManager::populate<CallStationPlayer>(2, 1000.0);

    GameVariables gameVariables;

    std::unique_ptr<PokerEngine> engine = nullptr;

    RaiserPlayer raiserPlayer;
    AllInPlayer allInPlayer;
    FolderPlayer folderPlayer;
    CheckerPlayer checkerPlayer;

    PokerEngineStatesTest() {
        // name the players to easily find them in the tests
        raiserPlayer.setName("Raiser");
        allInPlayer.setName("AllIner");
        folderPlayer.setName("Folder");
        checkerPlayer.setName("Checker");
        playerManager.getPlayer(0)->setName("Caller");

        // add the players to a total of 6
        playerManager.add(std::make_shared<RaiserPlayer>(raiserPlayer));
        playerManager.add(std::make_shared<AllInPlayer>(allInPlayer));
        playerManager.add(std::make_shared<FolderPlayer>(folderPlayer));
        playerManager.add(std::make_shared<CheckerPlayer>(checkerPlayer));

        engine = std::make_unique<PokerEngine>(&playerManager, &gameVariables);

        // label the players if they do not already have a name
        engine->getPlayers()->enumerateEmptyPlayerNames(); // PLayer1  onl

        // set everybodies stack to 1000.0
        engine->getPlayers()->setStackSizeTo(1000.0);
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


TEST_F(PokerEngineStatesTest, MakeSureTheDefaultStartingStateIsReset) {
    checkPokerEngineIsInCorrectState(0, RESET_STATE);
}


TEST_F(PokerEngineStatesTest, AssertSmallBlindSubtractsFromStack) {
    engine->setState(SmallBlind::getInstance());

    // small blind is idx 1
    engine->getPlayers()->setCurrentPlayerIdx(1);

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), SMALL_BLIND_STATE);

    engine->action();

    ASSERT_EQ(engine->getPlayers()->getPlayer(1)->getStack(), 999);
    ASSERT_EQ(engine->getGameVariables()->getPot(), 1);

}

TEST_F(PokerEngineStatesTest, AssertBigBlindSubtractsFromStack) {
    engine->setState(BigBlind::getInstance());

    // bb is index 2
    engine->getPlayers()->setCurrentPlayerIdx(2);

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), BIG_BLIND_STATE);

    engine->action();

    ASSERT_EQ(engine->getPlayers()->getPlayer(2)->getStack(), 998);
    ASSERT_EQ(engine->getGameVariables()->getPot(), 2);
}

TEST_F(PokerEngineStatesTest, CheckCheckActioinPlayerStillHasStack) {
    engine->setState(PlayerToAct::getInstance());

    // use UTG player
    engine->getPlayers()->setCurrentPlayerByName("Checker");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    // Player still has stack
    ASSERT_EQ(engine->getPlayers()->getPlayer(3)->getStack(), 1000.0);
    // No new money in pot
    // Check option still available for other players
}

TEST_F(PokerEngineStatesTest, CheckCheckActionNoNewMoneyInPot) {
    engine->setState(PlayerToAct::getInstance());

    // use UTG player
    engine->getPlayers()->setCurrentPlayerByName("Checker");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    // No new money in pot
    ASSERT_EQ(engine->getGameVariables()->getPot(), 0.0);

    // Check option still available for other players
}

TEST_F(PokerEngineStatesTest, TestOptionStillAvailableToOtherPlayersAfterCheck) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerByName("Checker");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    /*
     * This isn't working because we're using a callstation player
     * The action chosen should be propagated to the palayer???
     */
    engine->action();

    // Check option still available for other players
    ASSERT_TRUE(engine->getGameVariables()->isCheckAvailable());
}

TEST_F(PokerEngineStatesTest, CheckPlayerCallsAndChipsRemovedFromStack) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerByName("Caller");


    // we manafacture an existing amount to call for test purposes
    engine->getGameVariables()->setAmountToCall(20.0);

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(980, engine->getPlayers()->getPlayerByName("Caller")->getStack());
}

TEST_F(PokerEngineStatesTest, CheckPlayerCallsAndAmountToCallIsCorrect) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerByName("Caller");

    // we manafacture an existing amount to call for test purposes
    engine->getGameVariables()->setAmountToCall(20.0);

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(20, engine->getGameVariables()->getAmountToCall());
}

TEST_F(PokerEngineStatesTest, CheckPlayerCallsAndPotIsCorrect) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerByName("Caller");

    // we manafacture an existing amount to call for test purposes
    engine->getGameVariables()->setAmountToCall(20.0);

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(20, engine->getGameVariables()->getPot().getValue());
}

TEST_F(PokerEngineStatesTest, CheckPlayerCallsAndCheckOptionIsRemoved) {
    engine->setState(PlayerToAct::getInstance());
    engine->getPlayers()->setCurrentPlayerByName("Caller");

    // we manafacture an existing amount to call for test purposes
    engine->getGameVariables()->setAmountToCall(20.0);

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    /*
     * Current impl changes th state path to be Call, so it'll  actually happen on the
     * next call to action!
     */

    ASSERT_FALSE(engine->getGameVariables()->isCheckAvailable());
}

TEST_F(PokerEngineStatesTest, CheckPlayerFolds) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerByName("Folder");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(1000, engine->getPlayers()->getPlayer(3)->getStack());

}

TEST_F(PokerEngineStatesTest, CheckPlayerFoldsPlayerStackStayThSame) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerByName("Folder");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(1000, engine->getPlayers()->getPlayer(3)->getStack());
}

TEST_F(PokerEngineStatesTest, CheckPlayerFoldsAmountToCallIsStill0) {
    engine->setState(PlayerToAct::getInstance());
    engine->getPlayers()->setCurrentPlayerByName("Folder");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(0, engine->getGameVariables()->getAmountToCall());
}

TEST_F(PokerEngineStatesTest, CheckPlayerFoldsPotIsStill0) {
    engine->setState(PlayerToAct::getInstance());
    engine->getPlayers()->setCurrentPlayerByName("Folder");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(0, engine->getGameVariables()->getPot().getValue());
}

TEST_F(PokerEngineStatesTest, CheckPlayerFoldsPlayerHasFolded) {
    engine->setState(PlayerToAct::getInstance());
    engine->getPlayers()->setCurrentPlayerByName("Folder");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_TRUE(engine->getPlayers()->getPlayer(3)->hasFolded());
}


TEST_F(PokerEngineStatesTest, CheckPlayerFoldsAndCheckOptionStillAvailableForOtherPlayers) {
    engine->setState(PlayerToAct::getInstance());
    engine->getPlayers()->setCurrentPlayerByName("Folder");

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_TRUE(engine->getGameVariables()->isCheckAvailable());

}

TEST_F(PokerEngineStatesTest, CheckPlayerRaisePotAmountIsRight) {
    engine->setState(PlayerToAct::getInstance());
    engine->getPlayers()->setCurrentPlayerByName("Raiser");

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(60, engine->getGameVariables()->getPot().getValue());
}

TEST_F(PokerEngineStatesTest, CheckPlayerRaiseStackAmountIsRight) {
    engine->setState(PlayerToAct::getInstance());
    engine->getPlayers()->setCurrentPlayerByName("Raiser");


    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_EQ(960, engine->getPlayers()->getPlayerByName("Raiser")->getStack());
}

TEST_F(PokerEngineStatesTest, CheckPlayerRaiseCheckNotAvailableForOtherPlayers) {
    engine->setState(PlayerToAct::getInstance());

    engine->getPlayers()->setCurrentPlayerByName("Raiser");

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->action();

    ASSERT_FALSE(engine->getGameVariables()->isCheckAvailable());
}


TEST_F(PokerEngineStatesTest, CheckPlayerAllInPotAmount) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->getPlayers()->setCurrentPlayerByName("AllIner");

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    engine->action();

    ASSERT_EQ(1020, engine->getGameVariables()->getPot().getValue());

}

TEST_F(PokerEngineStatesTest, CheckPlayerAllInStackAmount) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);


    engine->getPlayers()->setCurrentPlayerByName("AllIner");

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    engine->action();

    ASSERT_EQ(0, engine->getPlayers()->getPlayerByName("AllIner")->getStack());

}

TEST_F(PokerEngineStatesTest, CheckPlayerToActAllInPotAmountIsCorrect) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->getPlayers()->setCurrentPlayerByName("AllIner");

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    engine->action();

    ASSERT_EQ(1020, engine->getGameVariables()->getPot().getValue());

}

TEST_F(PokerEngineStatesTest, CheckPlayerToActAllStackAmountIsCorrect) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->getPlayers()->setCurrentPlayerByName("AllIner");

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    engine->action();

    ASSERT_EQ(0, engine->getPlayers()->getPlayerByName("AllIner")->getStack());

}

TEST_F(PokerEngineStatesTest, CheckPlayerAllInCheckNotAvailableToNextPlayer) {
    engine->setState(PlayerToAct::getInstance());

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

    engine->getPlayers()->setCurrentPlayerByName("AllIner");

    // we need to set an amount to call before as can raise
    engine->getGameVariables()->setAmountToCall(20.0);
    //and the pot
    engine->getGameVariables()->getPot() += 20.0;

    engine->action();

    ASSERT_FALSE(engine->getGameVariables()->isCheckAvailable());

}


TEST_F(PokerEngineStatesTest, TestAllPlayersEqualWhenTheyAreNot) {
    engine->setState(AllPlayersEqual::getInstance());
    // players need a pivate count of how much they have contributed to the pot

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), ALL_PLAYERS_EQUAL_STATE);

    // make up some bets
    engine->getPlayers()->getPlayer(0)->setAmountContrib(10);
    engine->getPlayers()->getPlayer(1)->setAmountContrib(20);
    engine->getPlayers()->getPlayer(2)->setAmountContrib(30);

    // add 60 to the pot
    engine->getGameVariables()->getPot() += 60;

    //  players left to act
    engine->action();

    // if we are in PlayerToAct State, then we've correctly assessed that
    // all players that have not folded are not equal

    // todo work out how this works when one player is all in
    // we'll handle this edge case later

    ASSERT_EQ(engine->getState()->getType(), PLAYER_TO_ACT_STATE);

}

TEST_F(PokerEngineStatesTest, TestAllPlayersEqualWhenTheyAreEqual) {
    engine->setState(AllPlayersEqual::getInstance());
    // players need a pivate count of how much they have contributed to the pot

    // will always be true if setState works
    ASSERT_EQ(engine->getState()->getType(), ALL_PLAYERS_EQUAL_STATE);

    // make up some bets
    engine->getPlayers()->getPlayer(0)->setAmountContrib(20);
    engine->getPlayers()->getPlayer(1)->setAmountContrib(20);
    engine->getPlayers()->getPlayer(2)->setAmountContrib(20);
    engine->getPlayers()->getPlayer(3)->setAmountContrib(20);
    engine->getPlayers()->getPlayer(4)->setAmountContrib(20);
    engine->getPlayers()->getPlayer(5)->setAmountContrib(20);

    // add 60 to the pot
    engine->getGameVariables()->getPot() += 100;

    //  players left to act
    engine->action();


    ASSERT_EQ(engine->getState()->getType(), END_STREET_STATE);

}

TEST_F(PokerEngineStatesTest, TestNextStreetPreflopToFlop) {

    // need to remember to reset players pot contributions

    engine->setState(NextStreet::getInstance());

    ASSERT_EQ(engine->getState()->getType(), NEXT_STREET_STATE);

    // default street is preflop
    engine->action(); // change to FLOP
    ASSERT_EQ(engine->getGameVariables()->getStreet(), FLOP_STREET);

}

TEST_F(PokerEngineStatesTest, TestNextStreetFlopToTurn) {

    // need to remember to reset players pot contributions

    engine->setState(NextStreet::getInstance());

    engine->getGameVariables()->setStreet(FLOP_STREET);

    ASSERT_EQ(engine->getState()->getType(), NEXT_STREET_STATE);

    // default street is preflop
    engine->action(); // change to FLOP
    ASSERT_EQ(engine->getGameVariables()->getStreet(), TURN_STREET);

}

TEST_F(PokerEngineStatesTest, TestNextStreetTurnToRiver) {

    // need to remember to reset players pot contributions

    engine->setState(NextStreet::getInstance());

    engine->getGameVariables()->setStreet(TURN_STREET);

    ASSERT_EQ(engine->getState()->getType(), NEXT_STREET_STATE);

    // default street is preflop
    engine->action(); // change to FLOP
    ASSERT_EQ(engine->getGameVariables()->getStreet(), RIVER_STREET);

}

TEST_F(PokerEngineStatesTest, TestNextStreetRiverToShowdown) {

    // need to remember to reset players pot contributions

    engine->setState(NextStreet::getInstance());

    engine->getGameVariables()->setStreet(RIVER_STREET);

    ASSERT_EQ(engine->getState()->getType(), NEXT_STREET_STATE);

    // default street is preflop
    engine->action(); // change to FLOP
    ASSERT_EQ(engine->getGameVariables()->getStreet(), SHOWDOWN_STREET);

}






















