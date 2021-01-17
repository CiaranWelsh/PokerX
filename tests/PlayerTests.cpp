//
// Created by Ciaran on 17/01/2021.
//

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
    Action selectAction(PokerEngine *engine) override {
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


