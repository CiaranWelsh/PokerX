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
TEST_F(GameScenarioTests, TestRealGame1){

    GameVariables gameVariables;
    gameVariables.setN(1);
    gameVariables.setSmallBlind(0.05);
    gameVariables.setBigBlind(0.10);

    PolicyPlayer DrLevty("DrLevty", 10.40, {CHECK, CHECK, CALL, CHECK, FOLD});
    PolicyPlayer OhJee("Ohhh Jeee", 4.60, {CALL, RAISE, RAISE}, {0.24, 0.70});
    PolicyPlayer goku("gokudousan", 8.51, { FOLD});
    PolicyPlayer aka("aka_Kranv1ch", 10.0, { FOLD});
    PolicyPlayer mal("Malyar-88", 4.07, { FOLD});
    PolicyPlayer lord("Lord_Antoan", 10, { FOLD});

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
    PokerEngine engine(&players, &gameVariables );

    // skip past big blind action
    // next player and button moves are two different things!
    // current player idx points to who's turn it is
    // button is always player 0, but the table rotates when game starts
    // so current player index should always start at 1 for the sb.
//    ASSERT_EQ(1, players.getCurrentPlayerIdx());
    while(engine.getState()->getType() != DEAL_FLOP_STATE ){
        engine.action();
    }

    // next player needs to ignore folded or sitting out individuals
    while(!gameVariables.isDone()){
        engine.action();
    }


}







