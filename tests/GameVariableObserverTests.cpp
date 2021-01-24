/**
 * Players observe GameVariables using the observer pattern
 * This is an integration style test suit to exercise this pattern
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/FakePlayer.h"

#include "PokerX/engine/GameVariables.h"
#include "PokerX/engine/Player.h"
#include "PokerX/engine/PlayerManager.h"

using namespace pokerx;


class GameVariableObserverTests : public ::testing::Test {
public:
    PlayerManager playerManager;

    GameVariableObserverTests() {
        playerManager = PlayerManager::populate<FakePlayer>(6, 100.0);
    };
};


TEST_F(GameVariableObserverTests, CheckThatGetGameVariablesDoesNotReturnNullptr) {
    GameVariables gameVariables; //observed
    playerManager.watch(&gameVariables);

    // We artificially change the amount to call
    gameVariables.setAmountToCall(10.0);

    // Notify observers of the change
    playerManager.updateObservers(gameVariables, "amountToCall");

    ASSERT_NE(playerManager[0], nullptr);

}

TEST_F(GameVariableObserverTests, CheckThatAmountToCallIsProperlyUpdated) {
    GameVariables gameVariables; //observed
    playerManager.watch(&gameVariables);

    // We artificially change the amount to call
    gameVariables.setAmountToCall(10.0);

    // Notify observers of the change
    playerManager.updateObservers(gameVariables, "amountToCall");

    for (const auto &player : playerManager) {
        ASSERT_EQ(10.0, player->getGameVariables()->getAmountToCall());
    }

}


TEST_F(GameVariableObserverTests, CanWeUseTheWatchMethodToSubscribeToObservers) {
    /**
     * So we have a playerManager which houses players.
     * Players watch or obsever GamePlayers.
     * Using any of the setters for GameVariables initializes the
     * GameVariables reference in the Player class.
     * ... But if you try to access the PLayer::gameVariables
     * without first having initialized (via setter method), we'll
     * get segfault. This is bad design, so I'm trying to introduce a
     * watch method that we do all that is necessary to configure the
     * observer (by registering for observer) and initializing the
     * gameVariables reference in Player objects
     */
    GameVariables gameVariables; //observed

    // associate the players in the playerManager object
    // with the gameVariables object. The players will now
    // "watch" the gameVariables
    playerManager.watch(&gameVariables);

    // When we neglect to use the watch method the gameVariable reference inside
    // player instances are nullptr. This test ensures that this is not the case
    ASSERT_FALSE(
            playerManager.getCurrentPlayer()->getGameVariables() == nullptr
    );

}




























