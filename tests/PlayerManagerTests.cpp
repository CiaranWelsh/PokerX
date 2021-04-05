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

TEST_F(PlayerManagerTests, TestPopulateMethodCreatesRightNumberOfPlayers) {
    PlayerManager playerManager = PlayerManager::populate<FakePlayer>(6, 100.0);
    ASSERT_EQ(6, playerManager.size());
}

TEST_F(PlayerManagerTests, CheckThatNoneOfThePlayersAreNullptr) {
    for (const auto &player : playerManager) {
        ASSERT_FALSE(player == nullptr);
    }
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

/**
 * At the end of a round the game resets and the button moves
 * Practically what happens in the order of the container
 * shifts and the last becomes the first. Then the button is 0 again
 */
TEST_F(PlayerManagerTests, TestMoveButton) {
    std::cout << playerManager << std::endl;
    playerManager.moveButton();
    std::cout << playerManager << std::endl;
    // and should be player 5 after 1 rotation
    ASSERT_STREQ(playerManager[0]->getName().c_str(), "Player5");

    // But the current index should be at 0, ready for a new round of betting
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 0);
}

TEST_F(PlayerManagerTests, TestNextPlayerSimple) {

    // Players have not rotated so Player0 should still be at position 0
    ASSERT_STREQ(playerManager[0]->getName().c_str(), "Player0");
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 0);

    playerManager.nextPlayer();

    ASSERT_STREQ(
            playerManager.getCurrentPlayer()->getName().c_str(),
            "Player1"
    );
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 1);
}

TEST_F(PlayerManagerTests, TestNextPlayerWhenAplayerHasFolded) {
    ASSERT_STREQ(playerManager[0]->getName().c_str(), "Player0");
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 0);

    // This time player 0 has folded by default
    playerManager.getPlayer(1)->setHasFolded(true);

    playerManager.nextPlayer();


    // Players have not rotated so Player0 should still be at position 0

    // But the current index should be at 1, since player 0 has taken their go
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 2);
    ASSERT_STREQ(
            playerManager.getCurrentPlayer()->getName().c_str(),
            "Player2"
    );
}

TEST_F(PlayerManagerTests, TestNextPlayerWhenPlayerIsSittingOut) {
    ASSERT_STREQ(playerManager[0]->getName().c_str(), "Player0");
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 0);

    // This time player 0 has folded by defaul
    playerManager.getPlayer(1)->setSittingOut(true);

    playerManager.nextPlayer();


    // Players have not rotated so Player0 should still be at position 0

    // But the current index should be at 1, since player 0 has taken their go
    ASSERT_EQ(playerManager.getCurrentPlayerIdx(), 2);
    ASSERT_STREQ(
            playerManager.getCurrentPlayer()->getName().c_str(),
            "Player2"
    );
}


TEST_F(PlayerManagerTests, TestSetAllPlayersStacks) {
    playerManager.setStackSizeTo(15.0);
    for (auto player: playerManager) {
        ASSERT_EQ(player->getStack(), 15.0);
    }
}


TEST_F(PlayerManagerTests, TestSetCurrentPlayerIdxByName) {
    // set a players name
    playerManager.getPlayer(3)->setName("James");
    playerManager.setCurrentPlayerByName("James");
    ASSERT_STREQ(playerManager.getCurrentPlayer()->getName().c_str(), "James");
}

TEST_F(PlayerManagerTests, TestGetIndexOfPlayer) {
    // set a players name
    auto player = playerManager.getPlayer(3);
    ASSERT_EQ(3, playerManager.getIndexOfPlayer(player));
}


TEST_F(PlayerManagerTests, TestGetPlayerByName) {
    // set a players name
    auto player = playerManager.getPlayer(3);
    player->setName("James");
    ASSERT_STREQ("James", playerManager.getPlayerByName("James")->getName().c_str());
}


TEST_F(PlayerManagerTests, CheckAllPlayersEqualWhenTrue) {
    playerManager[0]->setAmountContrib(10);
    playerManager[1]->setAmountContrib(10);
    playerManager[2]->setAmountContrib(10);
    playerManager[3]->setAmountContrib(10);
    playerManager[4]->setAmountContrib(10);
    playerManager[5]->setAmountContrib(10);

    ASSERT_TRUE(playerManager.allPlayersEqual());

}


TEST_F(PlayerManagerTests, CheckThankYouCanSetAmountContrib) {
    playerManager.getPlayer(0)->setAmountContrib(10);
    ASSERT_EQ(10, playerManager.getPlayer(0)->getAmountContrib());
}

TEST_F(PlayerManagerTests, CheckAllPlayersEqualWhenFalse) {
    playerManager[0]->setAmountContrib(10);
    playerManager[1]->setAmountContrib(20);
    playerManager[2]->setAmountContrib(30);
    playerManager[3]->setAmountContrib(40);
    playerManager[4]->setAmountContrib(50);
    playerManager[5]->setAmountContrib(60);

    ASSERT_FALSE(playerManager.allPlayersEqual());

}
TEST_F(PlayerManagerTests, CheckAllPlayersEqualWithFloats) {
    playerManager[0]->setAmountContrib(10.567);
    playerManager[1]->setAmountContrib(10.432);
    playerManager[2]->setAmountContrib(10.443);
    playerManager[3]->setAmountContrib(10.342);
    playerManager[4]->setAmountContrib(10.121);
    playerManager[5]->setAmountContrib(10.5667);

    ASSERT_FALSE(playerManager.allPlayersEqual());
}

TEST_F(PlayerManagerTests, CheckAllPlayerTakenAtLeastOneTurnWhenTrue) {
    playerManager[0]->setNumActionsThisStreet(1);
    playerManager[1]->setNumActionsThisStreet(1);
    playerManager[2]->setNumActionsThisStreet(1);
    playerManager[3]->setNumActionsThisStreet(1);
    playerManager[4]->setNumActionsThisStreet(1);
    playerManager[5]->setNumActionsThisStreet(1);

    ASSERT_TRUE(playerManager.allPlayersTakenAtLeastOneTurn());
}

TEST_F(PlayerManagerTests, CheckAllPlayerTakenAtLeastOneTurnWhenFalse) {
    playerManager[0]->setNumActionsThisStreet(1);
    playerManager[1]->setNumActionsThisStreet(1);
    playerManager[2]->setNumActionsThisStreet(1);
    playerManager[3]->setNumActionsThisStreet(1);
    playerManager[4]->setNumActionsThisStreet(1);
    playerManager[5]->setNumActionsThisStreet(0);

    ASSERT_FALSE(playerManager.allPlayersTakenAtLeastOneTurn());
}

TEST_F(PlayerManagerTests, CheckThatSePlayerToButtonWorks) {
    playerManager.setButton("Player4");
    ASSERT_STREQ(
            playerManager.getButton()->getName().c_str(),
            "Player4"
    );
    auto player4 = playerManager.getPlayerByName("Player4");
    ASSERT_EQ(0, playerManager.getIndexOfPlayer(player4));

}


























