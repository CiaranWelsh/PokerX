//
// Created by Ciaran on 17/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/Player.h"
#include "PokerX/engine/Action.h"
#include "Mockups/MockGameVariables.h"


using namespace pokerx;

class FakePlayer : public Player {
public:
    using Player::Player;

    ~FakePlayer() override = default;

    /**
     * Our Fake player is a call station.
     */
    pokerx::Action selectAction(pokerx::StateMachine *engine) override {
        return CALL;
    }

    /**
     * FakePlayer's raising strategy is to double the call amount
     * But it'll never be used
     */
    float raise() override {
        float amount = 2 * getGameVariables()->getAmountToCall();
        stack_ -= amount;
        return amount;
    }

    friend std::ostream& operator<<(std::ostream& os, const FakePlayer& player);

};

std::ostream &operator<<(ostream &os, const FakePlayer& player) {
    return player.print(os);
}


class PlayerTests : public ::testing::Test {
public:
    MockGameVariables gameVariables;

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
    ASSERT_FALSE(player.isInPlay());
}


TEST_F(PlayerTests, TestCheckErrorsWhenCheckNotAvailable) {
    FakePlayer player;
    player.watch(&gameVariables);
    EXPECT_CALL(gameVariables, setCheckAvailable).Times(1);
    gameVariables.setCheckAvailable(false);
    // something has to be updated
    ASSERT_THROW(player.check(), std::runtime_error);
}

TEST_F(PlayerTests, TestCheckPlayersStackUnchanged) {
    FakePlayer player;
    player.watch(&gameVariables);
    EXPECT_CALL(gameVariables, isCheckAvailable).Times(1).WillRepeatedly(Return(true));
    player.check();
    ASSERT_EQ(player.getStack(), 1000.0);
}


TEST_F(PlayerTests, TestCallReducesPlayerStack) {
    FakePlayer player("p1", 100);
    player.watch(&gameVariables);
    EXPECT_CALL(gameVariables, getAmountToCall).Times(1).WillRepeatedly(Return(10.0));
    float amount = player.call();
    ASSERT_EQ(amount, 10.0);
    ASSERT_EQ(player.getStack(), 90.0);
}

TEST_F(PlayerTests, TestRaiseWhenAmountIsGreaterThanCallAmount) {
    FakePlayer player("p1", 100.0);
    player.watch(&gameVariables);

    // set amount to call to 10
    EXPECT_CALL(gameVariables, getAmountToCall).Times(1).WillRepeatedly(Return(10.0));

    // player raises to 20
    float amount = player.raise();

    // This particular players raising strategy is to double the call amount (see definition)
    ASSERT_EQ(amount, 20.0);
    ASSERT_EQ(player.getStack(), 80.0);
}































