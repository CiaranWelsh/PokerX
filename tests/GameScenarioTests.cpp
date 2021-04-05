/**
 * end to end tests, recreate full games
 */
#include <PokerX/engine/Policy.h>
#include <PokerX/engine/PolicyPlayer.h>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "PokerX/PokerX.h"


using namespace pokerx;

class GameScenarioTests : public ::testing::Test {

public:

    RaiserPlayer raiserPlayer;
    CallStationPlayer callStationPlayer;
    PolicyPlayer policyPlayer;
    AllInPlayer allInPlayer;
    FolderPlayer folderPlayer;
    CheckerPlayer checkerPlayer;

    GameScenarioTests() {
        // name the players to easily find them in the tests
        raiserPlayer.setName("Raiser");
        callStationPlayer.setName("Caller");
        policyPlayer.setName("PolicyPlayer");
    }

    void assertPlayerAction(PokerEngine *engine, const std::string &playerName, float playerStackAfterAction,
                            float playerAmountContribAfterAction, float potAmountAfterAction, float amountToCall,
                            bool hasBetBeenPlacedAfterAction) {
        EXPECT_NEAR(playerStackAfterAction, engine->getPlayers()->getPlayerByName(playerName)->getStack(), 0.001);
        EXPECT_NEAR(playerAmountContribAfterAction,
                    engine->getPlayers()->getPlayerByName(playerName)->getAmountContrib(), 0.001);
        EXPECT_NEAR(potAmountAfterAction, engine->getGameVariables()->getPot().getValue(), 0.001);
        EXPECT_NEAR(amountToCall, engine->getGameVariables()->getAmountToCall(), 0.001);
        if (hasBetBeenPlacedAfterAction)
            EXPECT_TRUE(engine->getGameVariables()->hasBetBeenPlaced());
        else
            EXPECT_FALSE(engine->getGameVariables()->hasBetBeenPlaced());
    }

    void assertCurrentPlayer(PokerEngine *engine, const std::string &playerName) {
        ASSERT_STREQ(engine->getPlayers()->getCurrentPlayer()->getName().c_str(), playerName.c_str());
    }

    void assertCurrentState(PokerEngine *engine, int state) {
        ASSERT_EQ(engine->getState()->getType(), state);
    }

    void assertPlayerFoldsSingleAction(PokerEngine *engine, const std::string &playerName) {
        assertCurrentPlayer(engine, playerName);
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);
        engine->action(1);
        ASSERT_EQ(true, engine->getPlayers()->getPlayerByName(playerName)->hasFolded());
    }

    void assertPlayerChecksSingleAction(PokerEngine *engine, const std::string &playerName) {
        assertCurrentPlayer(engine, playerName);
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);
        float stackBeforeCheck = engine->getPlayers()->getCurrentPlayer()->getStack();
        float amountContribBeforeCheck = engine->getPlayers()->getCurrentPlayer()->getAmountContrib();
        engine->action(1);
        float stackAfterCheck = engine->getPlayers()->getCurrentPlayer()->getStack();
        float amountContribAfterCheck = engine->getPlayers()->getCurrentPlayer()->getAmountContrib();
        ASSERT_EQ(stackBeforeCheck, stackAfterCheck);
        ASSERT_EQ(amountContribBeforeCheck, amountContribAfterCheck);
    }

    void assertPlayerRaisesSingleAction(PokerEngine *engine, const std::string &playerName, float raiseAmount) {
        assertCurrentPlayer(engine, playerName);
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);
        float playerStackBeforeRaise = engine->getPlayers()->getCurrentPlayer()->getStack();
        float potBeforeRaise = engine->getGameVariables()->getPot().getValue();
        float amountContribBeforeRaise = engine->getPlayers()->getCurrentPlayer()->getAmountContrib();

        engine->action(1);

        float playerStackAfterRaise = engine->getPlayers()->getCurrentPlayer()->getStack();
        float potAfterRaise = engine->getGameVariables()->getPot().getValue();
        float amountContribAfterRaise = engine->getPlayers()->getCurrentPlayer()->getAmountContrib();

        ASSERT_EQ(playerStackAfterRaise, playerStackBeforeRaise - raiseAmount);
        ASSERT_EQ(potAfterRaise, potBeforeRaise + raiseAmount);
        ASSERT_EQ(amountContribAfterRaise, amountContribBeforeRaise + raiseAmount);

        ASSERT_EQ(raiseAmount, engine->getGameVariables()->getAmountToCall());
    }

    void assertPlayerCallsSingleAction(PokerEngine *engine, const std::string &playerName) {
        assertCurrentPlayer(engine, playerName);
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);

        float callAmount = engine->getGameVariables()->getAmountToCall();

        float playerStackBeforeRaise = engine->getPlayers()->getCurrentPlayer()->getStack();
        float potBeforeRaise = engine->getGameVariables()->getPot().getValue();
        float amountContribBeforeRaise = engine->getPlayers()->getCurrentPlayer()->getAmountContrib();

        engine->action(1);

        float playerStackAfterRaise = engine->getPlayers()->getCurrentPlayer()->getStack();
        float potAfterRaise = engine->getGameVariables()->getPot().getValue();
        float amountContribAfterRaise = engine->getPlayers()->getCurrentPlayer()->getAmountContrib();

        ASSERT_EQ(playerStackAfterRaise, playerStackBeforeRaise - callAmount);
        ASSERT_EQ(potAfterRaise, potBeforeRaise + callAmount);
        ASSERT_EQ(amountContribAfterRaise, amountContribBeforeRaise + callAmount);
    }

    void assertBlind(PokerEngine *engine, int blindState, const std::string &playerName) {
        assertCurrentState(engine, blindState);
        assertCurrentPlayer(engine, playerName);

        auto playerReference = engine->getPlayers()->getPlayerByName(playerName);
        float amount;
        if (blindState == SMALL_BLIND_STATE) {
            amount = engine->getGameVariables()->getSmallBlind();
        } else if (blindState == BIG_BLIND_STATE) {
            amount = engine->getGameVariables()->getBigBlind();
        } else {
            throw std::logic_error("bad state");
        }


        float playerStackBefore = playerReference->getStack();
        float potBefore = engine->getGameVariables()->getPot().getValue();
        float amountContribBefore = playerReference->getAmountContrib();

        engine->action(1);

        float playerStackAfter = playerReference->getStack();
        float potAfter = engine->getGameVariables()->getPot().getValue();
        float amountContribAfter = playerReference->getAmountContrib();

        ASSERT_EQ(playerStackAfter, playerStackBefore - amount);
        ASSERT_EQ(potAfter, potBefore + amount);
        ASSERT_EQ(amountContribAfter, amountContribBefore + amount);
    }

    void assertSmallBlind(PokerEngine *engine, const std::string &playerName) {
        assertBlind(engine, SMALL_BLIND_STATE, playerName);
    }

    void assertBigBlind(PokerEngine *engine, const std::string &playerName) {
        assertBlind(engine, BIG_BLIND_STATE, playerName);
    }

    void assertDealCards(PokerEngine *engine, int streetState, std::vector<std::string> cards) {
        assertCurrentState(engine, NEXT_STREET_STATE);
        engine->action(1);
        ASSERT_EQ(streetState, engine->getGameVariables()->getStreet());

        switch (streetState) {
            case FLOP_STREET: {
                assertCurrentState(engine, DEAL_FLOP_STATE);
                break;
            }
            case TURN_STREET: {
                assertCurrentState(engine, DEAL_TURN_STATE);
                break;
            }
            case RIVER_STREET: {
                assertCurrentState(engine, DEAL_RIVER_STATE);
                break;
            }
            default:
                std::logic_error("bad state");
        }
        engine->action(1);
        ASSERT_EQ(engine->getGameVariables()->getCommunityCards(), cards);

        assertCurrentState(engine, START_STREET_STATE);
        engine->action(1);
    }

    void assertDealFlop(PokerEngine *engine, std::vector<std::string> cards) {
        assertDealCards(engine, FLOP_STREET, cards);
    }

    void assertDealTurn(PokerEngine *engine, std::vector<std::string> cards) {
        assertDealCards(engine, TURN_STREET, cards);
    }

    void assertDealRiver(PokerEngine *engine, std::vector<std::string> cards) {
        assertDealCards(engine, RIVER_STREET, cards);
    }

    void assertPotTotal(PokerEngine *engine, float potTotal) {
        ASSERT_NEAR(engine->getGameVariables()->getPot().getValue(), potTotal, 0.001);
    }

    void
    assertPlayerRaises(PokerEngine *engine, const std::string &playerName, float amount, bool checkPlayerStack = true,
                       bool checkAmountContrib = true,
                       bool checkPot = true) {
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);
        assertCurrentPlayer(engine, playerName);

        float callAmount = engine->getGameVariables()->getAmountToCall();
        float amountToRaiseTo = amount;

        auto currentPlayer = engine->getPlayers()->getPlayerByName(playerName);
        float playerStackBefore = currentPlayer->getStack();
        float amountContribBefore = currentPlayer->getAmountContrib();
        float potBefore = engine->getGameVariables()->getPot().getValue();

        engine->action();

        float playerStackAfter = currentPlayer->getStack();
        float amountContribAfter = currentPlayer->getAmountContrib();
        float potAfter = engine->getGameVariables()->getPot().getValue();

        if (checkPlayerStack)
            ASSERT_NEAR(playerStackBefore - amountToRaiseTo, playerStackAfter, 0.001);

        if (checkAmountContrib)
            ASSERT_NEAR(amountContribAfter, amountContribBefore + amountToRaiseTo, 0.001);

        if (checkPot)
            ASSERT_NEAR(potAfter, potBefore + amountToRaiseTo, 0.001);
    }

    void assertPlayerCalls(PokerEngine *engine, const std::string &playerName, bool checkPlayerStack = true,
                           bool checkAmountContrib = true,
                           bool checkPot = true) {
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);
        assertCurrentPlayer(engine, playerName);

        float amountToCall = engine->getGameVariables()->getAmountToCall();
        float amountAlreadyInPot = engine->getPlayers()->getPlayerByName(playerName)->getAmountContrib();

        // the effective amount to call takes into account amount already in tht pot
        float effectiveAmountToCall = amountToCall - amountAlreadyInPot;

        float playerStackBefore = engine->getPlayers()->getPlayerByName(playerName)->getStack();
        float amountContribBefore = engine->getPlayers()->getPlayerByName(playerName)->getAmountContrib();
        float potBefore = engine->getGameVariables()->getPot().getValue();

        engine->action();

        float playerStackAfter = engine->getPlayers()->getPlayerByName(playerName)->getStack();
        float amountContribAfter = engine->getPlayers()->getPlayerByName(playerName)->getAmountContrib();
        float potAfter = engine->getGameVariables()->getPot().getValue();

        if (checkPlayerStack)
            ASSERT_NEAR(playerStackBefore - effectiveAmountToCall, playerStackAfter, 0.001);

        if (checkAmountContrib)
            ASSERT_NEAR(amountContribAfter, amountContribBefore + amountToCall, 0.001);

        if (checkPot)
            ASSERT_NEAR(potAfter, potBefore + effectiveAmountToCall, 0.001);
    }

    void assertPlayerChecks(PokerEngine *engine, const std::string &playerName,
                            bool checkPlayerStack = true,
                            bool checkAmountContrib = true,
                            bool checkPot = true) {
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);
        assertCurrentPlayer(engine, playerName);

        auto currentPlayer = engine->getPlayers()->getCurrentPlayer();
        float playerStackBefore = currentPlayer->getStack();
        float amountContribBefore = currentPlayer->getAmountContrib();
        float potBefore = engine->getGameVariables()->getPot().getValue();

        engine->action();

        float playerStackAfter = currentPlayer->getStack();
        float amountContribAfter = currentPlayer->getAmountContrib();
        float potAfter = engine->getGameVariables()->getPot().getValue();

        if (checkPlayerStack)
            ASSERT_EQ(playerStackBefore, playerStackAfter);
        if (checkAmountContrib)
            ASSERT_EQ(amountContribAfter, amountContribBefore);
        if (checkPot)
            ASSERT_EQ(potAfter, potBefore);
    }

    void assertPlayerFolds(PokerEngine *engine, const std::string &playerName, bool checkPlayerStack = true,
                           bool checkAmountContrib = true,
                           bool checkPot = true) {
        assertCurrentState(engine, PLAYER_TO_ACT_STATE);
        assertCurrentPlayer(engine, playerName);

        auto currentPlayer = engine->getPlayers()->getCurrentPlayer();
        float playerStackBefore = currentPlayer->getStack();
        float amountContribBefore = currentPlayer->getAmountContrib();
        float potBefore = engine->getGameVariables()->getPot().getValue();

        engine->action();

        float playerStackAfter = currentPlayer->getStack();
        float amountContribAfter = currentPlayer->getAmountContrib();
        float potAfter = engine->getGameVariables()->getPot().getValue();

        ASSERT_TRUE(engine->getPlayers()->getPlayerByName(playerName)->hasFolded());

        if (checkPlayerStack)
            ASSERT_EQ(playerStackBefore, playerStackAfter);
        if (checkAmountContrib)
            ASSERT_EQ(amountContribAfter, amountContribBefore);
        if (checkPot)
            ASSERT_EQ(potAfter, potBefore);
    }

    void assertPlayersHaveHoleCards(PokerEngine *engine) {
        for (const auto &player : *engine->getPlayers()) {
            ASSERT_EQ(2, player->getHoleCards().size());
        }
    }

};

/**
 * Start in the situation where caller has called and raiser raises.
 * then the raiser calls
 */
//TEST_F(GameScenarioTests, TestRaiserAfterCall) {
//    playerManager.add(std::make_shared<CallStationPlayer>(callStationPlayer));
//    playerManager.add(std::make_shared<RaiserPlayer>(raiserPlayer));
//    playerManager.setStackSizeTo(100);
//
//    const auto &caller = playerManager.getPlayerByName("Caller");
//    const auto &raiser = playerManager.getPlayerByName("Raiser");
//
//    caller->setAmountContrib(10);
//    caller->setStack(caller->getStack() - 10);
//    ASSERT_EQ(caller->getStack(), 90);
//
//    gameVariables.setAmountToCall(10);
//    gameVariables.getPot() += 10;
//
//    PokerEngine engine(&playerManager, &gameVariables);
//    // why does setState change the current_player_idx to 0?
//    // because reset::exit always gets called.
//    engine.setState(PlayerToAct::getInstance());
//
//    // should set current player after we've set the state
//    playerManager.setCurrentPlayerByName("Raiser");
//    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 1);
//
//    // raiser should raise by to 20
//    engine.action();
//    ASSERT_EQ(raiser->getAmountContrib(), 20);
//    ASSERT_EQ(gameVariables.getPot(), 30);
//    ASSERT_EQ(raiser->getStack(), 80);
//
//    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 0);
//    engine.action(); // so what about when I want to make the player call
//
//}

/**
 * Here we try to reproduce this game:
 *
 *       PokerStars Hand #222947437297:  Hold'em No Limit ($0.05/$0.10 USD) - 2021/01/23 3:08:03 ET
 *       Table 'Aaryn II' 6-max Seat #5 is the button
 *       Seat 1: DrLevty ($10.40 in chips)
 *       Seat 2: Ohhh Jeee ($4.60 in chips) // winning stack
 *       Seat 3: gokudousan ($8.51 in chips)
 *       Seat 4: aka_Kranv1ch ($10 in chips)
 *       Seat 5: Malyar-88 ($4.07 in chips)
 *       Seat 6: Lord_Antoan ($10 in chips)
 *       Lord_Antoan: posts small blind $0.05 // pot amount: 0.05
 *       DrLevty: posts big blind $0.10 // pot amount: 0.15
 *       *** HOLE CARDS ***
 *       Ohhh Jeee: calls $0.10 // // pot amount: 0.25, winning stack: 4.50
 *       gokudousan: folds
 *       aka_Kranv1ch: folds
 *       Malyar-88: folds
 *       Lord_Antoan: folds
 *       DrLevty: checks
 *       *** FLOP *** [Td Jd 2h]
 *       DrLevty: checks
 *       Ohhh Jeee: bets $0.24 // pot amount: 0.49; 4.50 - 0.24 = 4.26
 *       DrLevty: calls $0.24 //// pot amount: 0.73;
 *       *** TURN *** [Td Jd 2h] [7c]
 *       DrLevty: checks
 *       Ohhh Jeee: bets $0.70 // pot amount: 1.43; 4.26 - 0.7 = 3.56
 *       DrLevty: folds
 *       Uncalled bet ($0.70) returned to Ohhh Jeee // 3.56 + 0.7 = 4.26
 *       Ohhh Jeee collected $0.70 from pot // 4.26 + 0.7 = 4.96  --> 4.99 with rake
 *       Ohhh Jeee: doesn't show hand
 *       *** SUMMARY ***
 *       Total pot $0.73 | Rake $0.03 // 4.99
 *       Board [Td Jd 2h 7c]
 *       Seat 1: DrLevty (big blind) folded on the Turn
 *       Seat 2: Ohhh Jeee collected ($0.70)
 *       Seat 3: gokudousan folded before Flop (didn't bet)
 *       Seat 4: aka_Kranv1ch folded before Flop (didn't bet)
 *       Seat 5: Malyar-88 (button) folded before Flop (didn't bet)
 *       Seat 6: Lord_Antoan (small blind) folded before Flop
 */
TEST_F(GameScenarioTests, TestRealGame1) {

    //       PokerStars Hand #222947437297:  Hold'em No Limit ($0.05/$0.10 USD) - 2021/01/23 3:08:03 ET
    //       Table 'Aaryn II' 6-max Seat #5 is the button
    float potTotal = 0.0;
    GameVariables gameVariables;
    gameVariables.setN(1);
    gameVariables.setSmallBlind(0.05);
    gameVariables.setBigBlind(0.10);

    gameVariables.injectCommunityCards({"Td", "Jd", "2h", "7c"});

    //       Seat 1: DrLevty ($10.40 in chips) // utg
    //       Seat 2: Ohhh Jeee ($4.60 in chips)
    //       Seat 3: gokudousan ($8.51 in chips)
    //       Seat 4: aka_Kranv1ch ($10 in chips)
    //       Seat 5: Malyar-88 ($4.07 in chips) // btn
    //       Seat 6: Lord_Antoan ($10 in chips) // sb
    //       Lord_Antoan: posts small blind $0.05 // bb
    //       DrLevty: posts big blind $0.10
    PolicyPlayer DrLevty("DrLevty", 10.40, {CHECK, CHECK, CALL, CHECK, FOLD});
    PolicyPlayer OhJee("Ohhh Jeee", 4.60, {CALL, RAISE, RAISE}, {0.24, 0.70});
    PolicyPlayer goku("gokudousan", 8.51, {FOLD});
    PolicyPlayer aka("aka_Kranv1ch", 10.0, {FOLD});
    PolicyPlayer mal("Malyar-88", 4.07, {FOLD});
    PolicyPlayer lord("Lord_Antoan", 10, {FOLD});

    float winningStack = 4.6;

    PlayerManager players({
                                  std::make_shared<PolicyPlayer>(DrLevty),
                                  std::make_shared<PolicyPlayer>(OhJee),
                                  std::make_shared<PolicyPlayer>(goku),
                                  std::make_shared<PolicyPlayer>(aka),
                                  std::make_shared<PolicyPlayer>(mal),
                                  std::make_shared<PolicyPlayer>(lord)
                          });
    players.setButton("Malyar-88");
    // setting the button and the current player are different things
    ASSERT_STREQ(players.getButton()->getName().c_str(), "Malyar-88");

    PokerEngine engine(&players, &gameVariables);

    // check button
    assertCurrentPlayer(&engine, "Malyar-88");

    assertCurrentState(&engine, RESET_STATE);
    engine.action(1); // reset state

    assertCurrentPlayer(&engine, "Lord_Antoan"); // we're on the sb now
    assertCurrentState(&engine, BUTTON_MOVES_STATE);
    engine.action(1); // button moves state

    /*******************************************************
     * Blinds and Flop
     */

    assertSmallBlind(&engine, "Lord_Antoan");
    potTotal += 0.05;
    assertPotTotal(&engine, potTotal);

    assertBigBlind(&engine, "DrLevty");
    potTotal += 0.1;
    assertPotTotal(&engine, potTotal);

    assertCurrentState(&engine, DEAL_HOLE_CARDS_STATE);
    engine.action(1); // Deal hole cards

    // make sure players have hole cards
    assertPlayersHaveHoleCards(&engine);

    assertCurrentState(&engine, START_STREET_STATE);
    engine.action(1); // start street

    ASSERT_EQ(engine.getGameVariables()->getStreet(), PREFLOP_STREET);

    // current player should now be UTG
    assertCurrentPlayer(&engine, "Ohhh Jeee");

    // Ohhh Jeee: calls $0.10
    assertPlayerCallsSingleAction(&engine, "Ohhh Jeee");
    potTotal += 0.1;
    assertPotTotal(&engine, potTotal);

    winningStack -= 0.1;

    // taking us to  check all players equal
    assertCurrentState(&engine, ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    // gokudousan: folds
    assertPlayerFoldsSingleAction(&engine, "gokudousan");
    assertPotTotal(&engine, potTotal);

    assertCurrentState(&engine, ALL_PLAYERS_EQUAL_STATE);
    engine.action(1); // not equal. Next player to act

    // aka_Kranv1ch: folds
    assertPlayerFoldsSingleAction(&engine, "aka_Kranv1ch");
    assertPotTotal(&engine, potTotal);

    assertCurrentState(&engine, ALL_PLAYERS_EQUAL_STATE);
    engine.action(1); // not equal. Next player to act

    // Malyar-88: folds
    assertPlayerFoldsSingleAction(&engine, "Malyar-88");
    assertPotTotal(&engine, potTotal);

    assertCurrentState(&engine, ALL_PLAYERS_EQUAL_STATE);
    engine.action(1); // not equal. Next player to act

    // Lord_Antoan: folds
    assertPlayerFoldsSingleAction(&engine, "Lord_Antoan");
    assertPotTotal(&engine, potTotal);

    assertCurrentState(&engine, ALL_PLAYERS_EQUAL_STATE);
    engine.action(1); // not equal. Next player to act

    // DrLevty: checks as big blind
    assertCurrentPlayer(&engine, "DrLevty");
    // make sure DrLevty has big blind in place before action
    ASSERT_NEAR(engine.getPlayers()->getCurrentPlayer()->getAmountContrib(), 0.10, 0.001);
    engine.action(1);
    ASSERT_EQ(engine.getPlayers()->getCurrentPlayer()->hasFolded(), false);

    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    /*************************************************************
     * DEAL FLOP
     */

    // this time, we should move on to next street.
    assertDealFlop(&engine, std::vector<std::string>({"2H", "10D", "JD"}));

    assertCurrentState(&engine, PLAYER_TO_ACT_STATE);

    // start of Flop street should be the sb to act
    //  except in this case Lord_Antoan has folded,
    //  in which case we go to DrLevty
    assertCurrentPlayer(&engine, "DrLevty");

    // DrLevty: checks
    assertPlayerChecksSingleAction(&engine, "DrLevty");

    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    // Ohhh Jeee: bets $0.24
    assertPlayerRaisesSingleAction(&engine, "Ohhh Jeee", 0.24);
    potTotal += 0.24;
    assertPotTotal(&engine, potTotal);

    winningStack -= 0.24;

    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    // DrLevty: calls $0.24
    assertPlayerCallsSingleAction(&engine, "DrLevty");
    potTotal += 0.24;
    assertPotTotal(&engine, potTotal);

    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    /***************************************************
     * Deal TURN
     */

    assertDealTurn(&engine, std::vector<std::string>({"2H", "7C", "10D", "JD"}));

    // DrLevty: checks
    assertPlayerChecksSingleAction(&engine, "DrLevty");

    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    // Ohhh Jeee: bets $0.70
    assertPlayerRaisesSingleAction(&engine, "Ohhh Jeee", 0.70);
    potTotal += 0.70;
    assertPotTotal(&engine, potTotal);

    winningStack -= 0.7;

    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    // DrLevty: folds
    assertPlayerFoldsSingleAction(&engine, "DrLevty");
    assertPotTotal(&engine, potTotal);

    ASSERT_EQ(engine.getState()->getType(), ALL_PLAYERS_EQUAL_STATE);
    engine.action(1);

    ASSERT_NEAR(engine.getPlayers()->getPlayerByName("Ohhh Jeee")->getStack(), 3.56, 0.001);
    ASSERT_NEAR(1.43, engine.getGameVariables()->getPot().getValue(), 0.001);

    ASSERT_EQ(engine.getState()->getType(), SHOWDOWN_STATE);

    ASSERT_NEAR(engine.getPlayers()->getPlayerByName("Ohhh Jeee")->getStack(), winningStack, 0.001);

    engine.action(1);

    ASSERT_NEAR(potTotal, 1.43, 0.001);

    // why is pot total 1.43 and
//    tota pot below is 0.73?

    // Total pot $0.73 | Rake $0.03
    // Uncalled bet ($0.70) returned to Ohhh Jeee
    // Ohhh Jeee collected $0.70 from pot
    ASSERT_NEAR(engine.getPlayers()->getPlayerByName("Ohhh Jeee")->getStack(), 4.99, 0.001);

    // so where is amount contrib taken care of?
    // todo still think there is a bug here somewhere.
    // Ohhh Jeee: doesn't show hand
    // *** SUMMARY ***
    // Board [Td Jd 2h 7c]
    // Seat 1: DrLevty (big blind) folded on the Turn
    // Seat 2: Ohhh Jeee collected ($0.70)
    // Seat 3: gokudousan folded before Flop (didn't bet)
    // Seat 4: aka_Kranv1ch folded before Flop (didn't bet)
    // Seat 5: Malyar-88 (button) folded before Flop (didn't bet)
    // Seat 6: Lord_Antoan (small blind) folded before Flop

}



/**
 * PokerStars Hand #222947473830:  Hold'em No Limit ($0.05/$0.10 USD) - 2021/01/23 3:10:40 ET
 * Table 'Atria II' 6-max Seat #4 is the button
 * Seat 1: YuYuYu777 ($10 in chips)             action policy: {FOLD}   raise policy {}
 * Seat 2: Wade 204481 ($5.66 in chips)         action policy: {RAISE, CHECK, CALL, RAISE, CHECK}   raise policy {0.2, 0.45}
 * Seat 3: Janxxx82 ($9.60 in chips)            action policy: {RAISE, RAISE, CALL, CHECK}   raise policy {0.1, 0.1}
 * Seat 4: pernth ($7.95 in chips) - button     action policy: {FOLD}   raise policy {}
 * Seat 5: xxxbohunxxx ($10 in chips)           action policy: {FOLD}   raise policy {}
 * xxxbohunxxx: posts small blind $0.05
 * YuYuYu777: posts big blind $0.10
 * *** HOLE CARDS ***
 * Wade 204481: bets $0.20
 * Janxxx82: raises $0.10 to $0.30
 * pernth: folds
 * CBG69 joins the table at seat #6
 * xxxbohunxxx: folds
 * YuYuYu777: folds
 * Wade 204481: calls $0.10
 * *** FLOP *** [Td Jc 2c]
 * Wade 204481: checks
 * Janxxx82: bets $0.10
 * Wade 204481: calls $0.10
 * *** TURN *** [Td Jc 2c] [Qs]
 * Wade 204481: bets $0.45
 * Janxxx82: calls $0.45
 * *** RIVER *** [Td Jc 2c Qs] [3h]
 * Wade 204481: checks
 * Janxxx82: checks
 * *** SHOW DOWN ***
 * Wade 204481: shows [Ad 9h] (high card Ace)
 * Janxxx82: shows [Kc Kh] (a pair of Kings)
 * Janxxx82 collected $1.77 from pot
 * *** SUMMARY ***
 * Total pot $1.85 | Rake $0.08
 * Board [Td Jc 2c Qs 3h]
 * Seat 1: YuYuYu777 (big blind) folded before Flop
 * Seat 2: Wade 204481 showed [Ad 9h] and lost with high card Ace
 * Seat 3: Janxxx82 showed [Kc Kh] and won ($1.77) with a pair of Kings
 * Seat 4: pernth (button) folded before Flop (didn't bet)
 * Seat 5: xxxbohunxxx (small blind) folded before Flop
 */
TEST_F(GameScenarioTests, TestRealGame2) {

    GameVariables gameVariables;
    gameVariables.setN(1);
    gameVariables.setSmallBlind(0.05);
    gameVariables.setBigBlind(0.10);
    gameVariables.setSeed(4);

    gameVariables.injectCommunityCards(std::vector<std::string>({"Td", "Jc", "2c", "Qs", "3h"}));

    /*
     * Table 'Atria II' 6-max Seat #4 is the button
     * Seat 1: YuYuYu777 ($10 in chips)
     * Seat 2: Wade 204481 ($5.66 in chips)
     * Seat 3: Janxxx82 ($9.60 in chips)
     * Seat 4: pernth ($7.95 in chips) - button
     * Seat 5: xxxbohunxxx ($10 in chips)
     * xxxbohunxxx: posts small blind $0.05
     * YuYuYu777: posts big blind $0.10
     */

    PolicyPlayer YuYuYu777("YuYuYu777", 10.0, {FOLD}, {});
    PolicyPlayer Wade("Wade", 5.66, {RAISE, CALL, CHECK, CALL, RAISE, CHECK}, {0.2, 0.45});
    PolicyPlayer Janxxx82("Janxxx82", 9.6, {RAISE, RAISE, CALL, CHECK}, {0.3, 0.1});
    PolicyPlayer pernth("pernth", 7.95, {FOLD}, {});
    PolicyPlayer xxxbohunxxx("xxxbohunxxx", 10.0, {FOLD}, {});

    PlayerManager players({
                                  std::make_shared<PolicyPlayer>(YuYuYu777),
                                  std::make_shared<PolicyPlayer>(Wade),
                                  std::make_shared<PolicyPlayer>(Janxxx82),
                                  std::make_shared<PolicyPlayer>(pernth),
                                  std::make_shared<PolicyPlayer>(xxxbohunxxx)
                          });
    players.setButton("pernth");
    // setting the button and the current player are different things
    ASSERT_STREQ(players.getButton()->getName().c_str(), "pernth");

    PokerEngine engine(&players, &gameVariables);

    engine.getPlayers()->getPlayerByName("Wade")->injectHoleCards(std::vector<std::string>({"Ad", "9h"}));
    ASSERT_EQ(engine.getPlayers()->getPlayerByName("Wade")->getInjectedHoleCards(),
              std::vector<std::string>({"Ad", "9h"}));

    engine.getPlayers()->getPlayerByName("Janxxx82")->injectHoleCards(std::vector<std::string>({"Kc", "Kh"}));
    ASSERT_EQ(engine.getPlayers()->getPlayerByName("Janxxx82")->getInjectedHoleCards(),
              std::vector<std::string>({"KC", "KH"}));

    engine.action();

    // blinds
    float potTotal = 0.05 + 0.10;
    assertPotTotal(&engine, potTotal);

    /**********************************************************
     * Preflop
     */

    // Wade 204481: bets $0.20
    potTotal += 0.20;
    assertPlayerRaises(&engine, "Wade", 0.2);
    assertPotTotal(&engine, potTotal);
    ASSERT_NEAR(engine.getGameVariables()->getAmountToCall(), 0.2, 0.001);

    // Janxxx82: raises $0.10 to $0.30
    potTotal += 0.3;
    assertPlayerRaises(&engine, "Janxxx82", 0.3);
    assertPotTotal(&engine, potTotal);

    // pernth folds
    assertPlayerFolds(&engine, "pernth");

    // xxxbohunxxx folds
    assertPlayerFolds(&engine, "xxxbohunxxx");

    // YuYuYu777 folds
    assertPlayerFolds(&engine, "YuYuYu777");

    // Wade 204481: calls 0.1
    potTotal += 0.1;
    // this call to action() takes us to next street whereby amountContrib is reset - so we turn off this check.
    assertPlayerCalls(&engine, "Wade", true, false, true);
    assertPotTotal(&engine, potTotal);

    /************************************************
     * FLOP
     */
    // *** FLOP *** [Td Jc 2c]
    ASSERT_EQ(engine.getGameVariables()->getCommunityCards().size(), 3);

    // Wade 204481: checks
    assertPlayerChecks(&engine, "Wade");

    // Janxxx82: bets $0.10
    potTotal += 0.1;
    assertPlayerRaises(&engine, "Janxxx82", 0.1);
    assertPotTotal(&engine, potTotal);

    // Wade 204481: calls $0.10
    potTotal += 0.1;
    assertPlayerCalls(&engine, "Wade", true, false, true);
    assertPotTotal(&engine, potTotal);
    /********************************************************
     * Turn
     */
    // *** TURN *** [Td Jc 2c] [Qs]
    // Wade 204481: bets $0.45
    potTotal += 0.45;
    assertPlayerRaises(&engine, "Wade", 0.45);
    assertPotTotal(&engine, potTotal);

    // Janxxx82: calls $0.45
    potTotal += 0.45;
    // check brings us to next street, so we turn off amount contrib check
    assertPlayerCalls(&engine, "Janxxx82", true, false, true);
    assertPotTotal(&engine, potTotal);

    /********************************************************
     * River
     */
    // *** RIVER *** [Td Jc 2c Qs] [3h]

    // Wade 204481: checks
    assertPlayerChecks(&engine, "Wade");

    // Janxxx82: checks
    assertPlayerChecks(&engine, "Janxxx82", false, false, true);

//    // *** SHOW DOWN ***
//    // Wade 204481: shows [Ad 9h] (high card Ace)
//    // Janxxx82: shows [Kc Kh] (a pair of Kings)
//
//    std::cout << engine.getPlayers()->getPlayerByName("Janxxx82")->getHoleCards() << std::endl;












    //    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//    ASSERT_NEAR(5.36, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);
//
//    // we've now had the flop, started a new street and set amountContrib to 0
//    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
//
//    ASSERT_NEAR(0.75, gameVariables.getPot().getValue(), 0.001);
//    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());
//
//    // *** FLOP ***
//
//    //Wade 204481: checks
//    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//    ASSERT_NEAR(5.36, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);
//    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
//    ASSERT_NEAR(0.75, gameVariables.getPot().getValue(), 0.001);
//    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());
//
//    // Janxxx82: bets $0.10
//    ASSERT_STREQ("Janxxx82", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//    ASSERT_NEAR(9.2, engine.getPlayers()->getPlayerByName("Janxxx82")->getStack(), 0.001);
//    ASSERT_NEAR(0.1, engine.getPlayers()->getPlayerByName("Janxxx82")->getAmountContrib(), 0.001);
//    ASSERT_NEAR(0.85, gameVariables.getPot().getValue(), 0.001);
//    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());
//
//    // Wade 204481: calls $0.10
//    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//    ASSERT_NEAR(5.26, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);
//
//    // ** turn **
//    // amount contrib restarts
//    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
//    ASSERT_NEAR(0.95, gameVariables.getPot().getValue(), 0.001);
//    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());
//
//    //  Wade 204481: bets $0.45
//    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//    ASSERT_NEAR(4.81, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);
//    ASSERT_NEAR(0.45, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
//    ASSERT_NEAR(1.4, gameVariables.getPot().getValue(), 0.001);
//    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());
//
//    // *** turn ***
//
//    //  Janxxx82: calls $0.45
//    ASSERT_STREQ("Janxxx82", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//    ASSERT_NEAR(8.75, engine.getPlayers()->getPlayerByName("Janxxx82")->getStack(), 0.001);
//    // resets because of turn
//    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Janxxx82")->getAmountContrib(), 0.001);
//    ASSERT_NEAR(1.85, gameVariables.getPot().getValue(), 0.001);
//    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());
//
//    //  *** RIVER *** [Td Jc 2c Qs] [3h]
//    //  Wade 204481: checks
//    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//
//    //  Janxxx82: checks
//    ASSERT_STREQ("Janxxx82", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
//    engine.action();
//
//    //  *** SHOW DOWN ***
//    engine.action();
//
//    // how to inject cards into the game to reproduce game without seed which is implementation defined.
//
//    //  Wade 204481: shows [Ad 9h] (high card Ace)
//    //  Janxxx82: shows [Kc Kh] (a pair of Kings)
//    //  Janxxx82 collected $1.77 from pot

}







