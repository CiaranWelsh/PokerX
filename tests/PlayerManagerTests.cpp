//
// Created by Ciaran on 17/01/2021.
//

#include "gtest/gtest.h"
#include "PokerX/engine/PlayerManager.h"
#include "Mockups/FakePlayer.h"
#include <memory>

using namespace pokerx;

class PlayerManagerTests : public ::testing::Test {
public:
    FakePlayer btn;
    PlayerManager playerManager = PlayerManager::populate<FakePlayer>(6, 100.0);

    PlayerManagerTests() = default;
};

TEST_F(PlayerManagerTests, TestPopulateMethodCreatesRightNumberOfPlayers){
    PlayerManager playerManager = PlayerManager::populate<FakePlayer>(6, 100.0);
    ASSERT_EQ(6, playerManager.size());
}

TEST_F(PlayerManagerTests, CheckThatNoneOfThePlayersAreNullptr) {
    for (const auto &player : playerManager) {
        ASSERT_FALSE(player == nullptr);
    }
}

TEST_F(PlayerManagerTests, CheckThatButtonIsNotNullptr) {
    ASSERT_FALSE(playerManager.getButton() == nullptr);
}

TEST_F(PlayerManagerTests, CheckThatCurrentPlayerIsNotNullptr) {
    ASSERT_FALSE(playerManager.getCurrentPlayer() == nullptr);
}

TEST_F(PlayerManagerTests, TestAddAPlayer) {
    // check that original size is 6
    ASSERT_EQ(6, playerManager.size());
    FakePlayer player;
    playerManager.add(std::make_shared<FakePlayer>(player));
    ASSERT_EQ(7, playerManager.size());
}

TEST_F(PlayerManagerTests, TestPlayerRotation) {
    // player manager index starts with 0
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 0);
    playerManager.nextPlayer();
    // and should be player 1 after 1 rotation
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 1);
}























