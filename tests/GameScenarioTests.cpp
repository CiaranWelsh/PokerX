//
// Created by Ciaran Welsh on 31/01/2021.
//
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
    AllInPlayer allInPlayer;
    FolderPlayer folderPlayer;
    CheckerPlayer checkerPlayer;

    GameScenarioTests() {
        // name the players to easily find them in the tests
        raiserPlayer.setName("Raiser");
        callStationPlayer.setName("Caller");

    }
};

TEST_F(GameScenarioTests, TestCaller){
    playerManager.setStackSizeTo(100);
    playerManager.add(std::make_shared<CallStationPlayer>(callStationPlayer));
    playerManager.add(std::make_shared<RaiserPlayer>(raiserPlayer));
    playerManager.setCurrentPlayerByName("Raiser");
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 1);

    // so when does crrent player go back to call station?

    const auto& caller = playerManager.getPlayerByName("Caller");
    const auto& raiser = playerManager.getPlayerByName("Raiser");

    caller->setAmountContrib(10);
    caller->setStack(caller->getStack() - 10);

    gameVariables.setAmountToCall(10);
    gameVariables.getPot() += 10;

    PokerEngine engine(&playerManager, &gameVariables);
    engine.setState(PlayerToAct::getInstance());
    // raiser should raise by to 20
    engine.action();
    ASSERT_EQ(raiser->getAmountContrib(), 20);
}










