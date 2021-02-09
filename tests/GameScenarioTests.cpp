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
    PlayerManager playerManager;

    GameVariables gameVariables;

    std::unique_ptr<PokerEngine> engine = nullptr;

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
};

/**
 * Start in the situation where caller has called and raiser raises.
 * then the raiser calls
 */
TEST_F(GameScenarioTests, TestRaiserAfterCall) {
    playerManager.add(std::make_shared<CallStationPlayer>(callStationPlayer));
    playerManager.add(std::make_shared<RaiserPlayer>(raiserPlayer));
    playerManager.setStackSizeTo(100);
    playerManager.setCurrentPlayerByName("Raiser");
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 1);

    // so when does current player go back to call station?

    const auto &caller = playerManager.getPlayerByName("Caller");
    const auto &raiser = playerManager.getPlayerByName("Raiser");

    caller->setAmountContrib(10);
    caller->setStack(caller->getStack() - 10);
    ASSERT_EQ(caller->getStack(), 90);

    gameVariables.setAmountToCall(10);
    gameVariables.getPot() += 10;

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());
    // raiser should raise by to 20
    engine.action();
    ASSERT_EQ(raiser->getAmountContrib(), 20);
    ASSERT_EQ(gameVariables.getPot(), 30);
    ASSERT_EQ(raiser->getStack(), 80);

    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 0);
    engine.action(); // so what about when I want to make the player call

}

/**
 * Here we try to reproduce this game:
 *
 *       PokerStars Hand #222947437297:  Hold'em No Limit ($0.05/$0.10 USD) - 2021/01/23 3:08:03 ET
 *       Table 'Aaryn II' 6-max Seat #5 is the button
 *       Seat 1: DrLevty ($10.40 in chips)
 *       Seat 2: Ohhh Jeee ($4.60 in chips)
 *       Seat 3: gokudousan ($8.51 in chips)
 *       Seat 4: aka_Kranv1ch ($10 in chips)
 *       Seat 5: Malyar-88 ($4.07 in chips)
 *       Seat 6: Lord_Antoan ($10 in chips)
 *       Lord_Antoan: posts small blind $0.05
 *       DrLevty: posts big blind $0.10
 *       *** HOLE CARDS ***
 *       Ohhh Jeee: calls $0.10
 *       gokudousan: folds
 *       aka_Kranv1ch: folds
 *       Malyar-88: folds
 *       Lord_Antoan: folds
 *       DrLevty: checks
 *       *** FLOP *** [Td Jd 2h]
 *          DrLevty: checks
 *       Ohhh Jeee: bets $0.24
 *       DrLevty: calls $0.24
 *       *** TURN *** [Td Jd 2h] [7c]
 *       DrLevty: checks
 *       Ohhh Jeee: bets $0.70
 *       DrLevty: folds
 *       Uncalled bet ($0.70) returned to Ohhh Jeee
 *       Ohhh Jeee collected $0.70 from pot
 *       Ohhh Jeee: doesn't show hand
 *       *** SUMMARY ***
 *       Total pot $0.73 | Rake $0.03
 *       Board [Td Jd 2h 7c]
 *       Seat 1: DrLevty (big blind) folded on the Turn
 *       Seat 2: Ohhh Jeee collected ($0.70)
 *       Seat 3: gokudousan folded before Flop (didn't bet)
 *       Seat 4: aka_Kranv1ch folded before Flop (didn't bet)
 *       Seat 5: Malyar-88 (button) folded before Flop (didn't bet)
 *       Seat 6: Lord_Antoan (small blind) folded before Flop
 */
TEST_F(GameScenarioTests, TestRealGame1) {

    GameVariables gameVariables;
    gameVariables.setN(1);
    gameVariables.setSmallBlind(0.05);
    gameVariables.setBigBlind(0.10);

    PolicyPlayer DrLevty("DrLevty", 10.40, {CHECK, CHECK, CALL, CHECK, FOLD});
    PolicyPlayer OhJee("Ohhh Jeee", 4.60, {CALL, RAISE, RAISE}, {0.24, 0.70});
    PolicyPlayer goku("gokudousan", 8.51, {FOLD});
    PolicyPlayer aka("aka_Kranv1ch", 10.0, {FOLD});
    PolicyPlayer mal("Malyar-88", 4.07, {FOLD});
    PolicyPlayer lord("Lord_Antoan", 10, {FOLD});

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

    // skip past big blind action
    // next player and button moves are two different things!
    // current player idx points to who's turn it is
    // button is always player 0, but the table rotates when game starts
    // so current player index should always start at 1 for the sb.
//    ASSERT_EQ(1, players.getCurrentPlayerIdx());
//    while(engine.getState()->getType() != TURN_STATE ){
//        engine.action();
//    }

    // next player needs to ignore folded or sitting out individuals
    while (!gameVariables.isDone()) {
        engine.action();
    }


}



/**
 * PokerStars Hand #222947473830:  Hold'em No Limit ($0.05/$0.10 USD) - 2021/01/23 3:10:40 ET
 * Table 'Atria II' 6-max Seat #4 is the button
 * Seat 1: YuYuYu777 ($10 in chips)
 * Seat 2: Wade 204481 ($5.66 in chips)
 * Seat 3: Janxxx82 ($9.60 in chips)
 * Seat 4: pernth ($7.95 in chips) - button
 * Seat 5: xxxbohunxxx ($10 in chips)
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


    PlayerManager players(
            {
                    std::make_shared<PolicyPlayer>(
                            PolicyPlayer("YuYuYu777", 10,
                                         {FOLD})),
                    std::make_shared<PolicyPlayer>(
                            PolicyPlayer("Wade", 5.66,
                                         {RAISE, CALL, CHECK, CALL, RAISE, CHECK},
                                         {0.2, 0.45})),
                    std::make_shared<PolicyPlayer>(
                            PolicyPlayer("Janxxx82", 9.6,
                                         {RAISE, RAISE, CALL, CHECK},
                                         {0.3, 0.1})),
                    std::make_shared<PolicyPlayer>(PolicyPlayer("pernth", 7.95, {FOLD})),
                    std::make_shared<PolicyPlayer>(PolicyPlayer("xxxbohunxxx", 10, {FOLD})),
            });
    players.setButton("pernth");
    // setting the button and the current player are different things
    ASSERT_STREQ(players.getButton()->getName().c_str(), "pernth");
    PokerEngine engine(&players, &gameVariables);

    // starts the game, reest through to first player to act
    // Seat 1: YuYuYu777 ($10 in chips)
    // Seat 2: Wade 204481 ($5.66 in chips)
    // Seat 3: Janxxx82 ($9.60 in chips)
    // Seat 4: pernth ($7.95 in chips)
    // Seat 5: xxxbohunxxx ($10 in chips)
    // xxxbohunxxx: posts small blind $0.05
    // YuYuYu777: posts big blind $0.10
    engine.action();

    // Wade 204481: bets $0.20
    ASSERT_EQ(PLAYER_TO_ACT_STATE, engine.getState()->getType());
    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(5.46, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);
    ASSERT_NEAR(0.2, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
    ASSERT_NEAR(0.35, gameVariables.getPot().getValue(), 0.001);
    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());

    // Janxxx82: raises $0.10 to $0.30
    ASSERT_STREQ("Janxxx82", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(9.3, engine.getPlayers()->getPlayerByName("Janxxx82")->getStack(), 0.001);
    ASSERT_NEAR(0.3, engine.getPlayers()->getPlayerByName("Janxxx82")->getAmountContrib(), 0.001);
    ASSERT_NEAR(0.65, gameVariables.getPot().getValue(), 0.001);
    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());

    // pernth folds
    ASSERT_STREQ("pernth", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(7.95, engine.getPlayers()->getPlayerByName("pernth")->getStack(), 0.001);
    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("pernth")->getAmountContrib(), 0.001);
    ASSERT_NEAR(0.65, gameVariables.getPot().getValue(), 0.001);
    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());

    // xxxbohunxxx folds
    // remember amountContrib is only for this round so blinds do not count
    ASSERT_STREQ("xxxbohunxxx", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(9.95, engine.getPlayers()->getPlayerByName("xxxbohunxxx")->getStack(), 0.01);
    ASSERT_NEAR(0.00, engine.getPlayers()->getPlayerByName("xxxbohunxxx")->getAmountContrib(), 0.01);
    ASSERT_NEAR(0.65, gameVariables.getPot().getValue(), 0.001);
    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());

    // YuYuYu777 folds
    ASSERT_STREQ("YuYuYu777", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(9.9, engine.getPlayers()->getPlayerByName("YuYuYu777")->getStack(), 0.001);
    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("YuYuYu777")->getAmountContrib(), 0.001);
    ASSERT_NEAR(0.65, gameVariables.getPot().getValue(), 0.001);
    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());

    // Wade 204481: calls 0.1
    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(5.36, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);

    // we've now had the flop, started a new street and set amountContrib to 0
    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);

    ASSERT_NEAR(0.75, gameVariables.getPot().getValue(), 0.001);
    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());

    // *** FLOP ***

    //Wade 204481: checks
    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(5.36, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);
    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
    ASSERT_NEAR(0.75, gameVariables.getPot().getValue(), 0.001);
    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());

    // Janxxx82: bets $0.10
    ASSERT_STREQ("Janxxx82", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(9.2, engine.getPlayers()->getPlayerByName("Janxxx82")->getStack(), 0.001);
    ASSERT_NEAR(0.1, engine.getPlayers()->getPlayerByName("Janxxx82")->getAmountContrib(), 0.001);
    ASSERT_NEAR(0.85, gameVariables.getPot().getValue(), 0.001);
    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());

    // Wade 204481: calls $0.10
    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(5.26, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);

    // ** turn **
    // amount contrib restarts
    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
    ASSERT_NEAR(0.95, gameVariables.getPot().getValue(), 0.001);
    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());

    //  Wade 204481: bets $0.45
    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(4.81, engine.getPlayers()->getPlayerByName("Wade")->getStack(), 0.001);
    ASSERT_NEAR(0.45, engine.getPlayers()->getPlayerByName("Wade")->getAmountContrib(), 0.001);
    ASSERT_NEAR(1.4, gameVariables.getPot().getValue(), 0.001);
    ASSERT_TRUE(gameVariables.hasBetBeenPlaced());

    // *** turn ***

    //  Janxxx82: calls $0.45
    ASSERT_STREQ("Janxxx82", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();
    ASSERT_NEAR(8.75, engine.getPlayers()->getPlayerByName("Janxxx82")->getStack(), 0.001);
    // resets because of turn
    ASSERT_NEAR(0.0, engine.getPlayers()->getPlayerByName("Janxxx82")->getAmountContrib(), 0.001);
    ASSERT_NEAR(1.85, gameVariables.getPot().getValue(), 0.001);
    ASSERT_FALSE(gameVariables.hasBetBeenPlaced());

    //  *** RIVER *** [Td Jc 2c Qs] [3h]
    //  Wade 204481: checks
    ASSERT_STREQ("Wade", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();

    //  Janxxx82: checks
    ASSERT_STREQ("Janxxx82", engine.getPlayers()->getCurrentPlayer()->getName().c_str());
    engine.action();

    //  *** SHOW DOWN ***
    engine.action();

    //  Wade 204481: shows [Ad 9h] (high card Ace)
    //  Janxxx82: shows [Kc Kh] (a pair of Kings)
    //  Janxxx82 collected $1.77 from pot

}







