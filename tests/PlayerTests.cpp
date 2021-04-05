//
// Created by Ciaran on 17/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"
#include "Mockups/MockGameVariables.h"
#include "Mockups/MockPot.h"
#include "Mockups/FakePlayer.h"


using namespace pokerx;

std::ostream &operator<<(std::ostream &os, const FakePlayer &player) {
    return player.print(os);
}


class PlayerTests : public ::testing::Test {
public:
    MockGameVariables gameVariables;

    MockPot pot;

    ~PlayerTests() override = default;

    PlayerTests() = default;
};


TEST_F(PlayerTests, TestPlayerStartingStack) {
    // this test is so simple that we do not need to register as observer
    FakePlayer player;
    ASSERT_EQ(1000.0, player.getStack());
}

TEST_F(PlayerTests, CheckPlayersIsInPlayFlagTurnedOffWhenFold) {
    FakePlayer player;
    player.fold();
    ASSERT_TRUE(player.hasFolded());
}


TEST_F(PlayerTests, TestCheckErrorsWhenCheckNotAvailable) {
    FakePlayer player;
    player.watch(&gameVariables);
    EXPECT_CALL(gameVariables, setBetPlaced).Times(1);
    gameVariables.setBetPlaced(true);
    // something has to be updated
    //ASSERT_THROW(player.check(), std::runtime_error);
}

TEST_F(PlayerTests, TestCheckPlayersStackUnchanged) {
    FakePlayer player;
    player.watch(&gameVariables);
    player.check();
    ASSERT_EQ(player.getStack(), 1000.0);
}


TEST_F(PlayerTests, TestCallReducesPlayerStack) {
    EXPECT_CALL(gameVariables, getAmountToCall).Times(1).WillRepeatedly(Return(10.0));
    EXPECT_CALL(gameVariables, getPot).Times(1).WillRepeatedly(ReturnRef(pot));
    FakePlayer player("p1", 100);
    player.watch(&gameVariables);
    player.call();
    ASSERT_EQ(player.getStack(), 90.0);
}

TEST_F(PlayerTests, TestAmountContributedIncrementsWhenCall) {
    // not yet implemented
//    EXPECT_CALL(gameVariables, getAmountToCall).Times(1).WillRepeatedly(Return(10.0));
//    EXPECT_CALL(gameVariables, getPot).Times(1).WillRepeatedly(ReturnRef(pot));
//    FakePlayer player("p1", 100);
//    player.watch(&gameVariables);
//    player.call();
//    ASSERT_EQ(player.getStack(), 90.0);
}


TEST_F(PlayerTests, TestRaise) {
    FakePlayer player("p1", 100.0);
    player.watch(&gameVariables);

    // set amount to call to 10
    EXPECT_CALL(gameVariables, getAmountToCall).WillRepeatedly(Return(10.0));
    EXPECT_CALL(gameVariables, getPot).Times(1).WillRepeatedly(ReturnRef(pot));

    // player raises 20 to 30
    player.raise();

    // This particular players raising strategy is to double the call amount (see definition)
    ASSERT_EQ(player.getStack(), 70.0);
}


TEST_F(PlayerTests, TestInjectHoleCards) {
    FakePlayer player("p1", 100.0);
    player.watch(&gameVariables);

    player.injectHoleCards(std::vector<std::string>({"4H", "6D"}));

    ASSERT_EQ(player.getHoleCards(),std::vector<std::string>({"4H", "6D"}));
}





























