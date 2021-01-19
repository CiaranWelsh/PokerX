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



TEST_F(PlayerTests, TestPlayerStartingStack){
    FakePlayer player;
    ASSERT_EQ(1000.0, player.getStack());
}

TEST_F(PlayerTests, CheckPlayersIsInPlayFlagTurnedOffWhenFold){
    FakePlayer player;
    player.fold();
    ASSERT_FALSE(player.isInPlay());
}


TEST_F(PlayerTests, Check){
    FakePlayer player;
    player.check();
    ASSERT_TRUE(player.isInPlay());
}


TEST_F(PlayerTests, Call){
    FakePlayer player("p1", 100);
    gameVariables.addSubscriber(&player);

    gameVariables.setAmountToCall(10.0);
    float amount = player.call();
    ASSERT_EQ(amount, 10.0);
    ASSERT_EQ(player.getStack(), 90.0);

}

TEST_F(PlayerTests, CheckRaiseWhenAmountIsGreaterThanCalAmount){
    FakePlayer player("p1", 100);
    gameVariables.addSubscriber(&player);

    gameVariables.setAmountToCall(10.0);

    float amount = player.raise(15.0);
    ASSERT_EQ(amount, 15.0);
    ASSERT_EQ(player.getStack(), 85.0);
}




























