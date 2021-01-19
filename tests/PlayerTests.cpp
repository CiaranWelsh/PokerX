//
// Created by Ciaran on 17/01/2021.
//

#include <PokerX/engine/StateMachine.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/Player.h"
#include "PokerX/engine/GameVariables.h"

using namespace pokerx;

class FakePlayer : public Player {
public:
    using Player::Player;

    /**
     * Our Fake player is a call station.
     */
    Action selectAction(pokerx::StateMachine *engine) override {
        return CALL;
    }

    /**
     * FakePlayer's raising strategy is to double the call amount
     */
    float raise() override {
        float amount = 2 * getGameVariables()->getAmountToCall();
        stack_ -= amount;
        return amount;
    }
};

class PlayerTests : public ::testing::Test {
public:
    GameVariables gameVariables;

    PlayerTests() = default;
};

/**
 * Player is abstract and cannot be used directly
 * We therefore create a class to test the interface here
 */



TEST_F(PlayerTests, TestPlayerStartingStack) {
    FakePlayer player;
    gameVariables.addSubscriber(&player);
    ASSERT_EQ(1000.0, player.getStack());
}

TEST_F(PlayerTests, CheckPlayersIsInPlayFlagTurnedOffWhenFold) {
    FakePlayer player;
    gameVariables.addSubscriber(&player);
    player.fold();
    ASSERT_FALSE(player.isInPlay());
}


TEST_F(PlayerTests, MakeSureThatErrorWhenCheckNotAvailable) {
    FakePlayer player;
    gameVariables.addSubscriber(&player);
    gameVariables.setCheckAvailable(false);
    // something has to be updated
    ASSERT_THROW(player.check(), std::runtime_error);
}

TEST_F(PlayerTests, TestCheckActionWorks) {
    FakePlayer player;
    gameVariables.addSubscriber(&player);
    gameVariables.setCheckAvailable(true);
    ASSERT_NO_THROW(player.check());
}


TEST_F(PlayerTests, Call) {
    FakePlayer player("p1", 100);
    gameVariables.addSubscriber(&player);

    gameVariables.setAmountToCall(10.0);
    float amount = player.call();
    ASSERT_EQ(amount, 10.0);
    ASSERT_EQ(player.getStack(), 90.0);

}

TEST_F(PlayerTests, CheckRaiseWhenAmountIsGreaterThanCalAmount) {
    FakePlayer player("p1", 100.0);
    gameVariables.addSubscriber(&player);

    gameVariables.setAmountToCall(10.0);

    float amount = player.raise();
    ASSERT_EQ(amount, 20.0);
    ASSERT_EQ(player.getStack(), 80.0);
}




























