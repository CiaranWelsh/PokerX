//
// Created by Ciaran on 17/01/2021.
//

#include <PokerX/engine/StateMachine.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/Player.h"

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
    FakePlayer player;
    float amount = player.call();

}

TEST_F(PlayerTests, Raise){
    FakePlayer player;
    player.raise(10.0);
    float amount = player.call();
}




























