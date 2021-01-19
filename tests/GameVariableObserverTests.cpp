/**
 * Players observe GameVariables using the observer pattern
 * This is an integration style test suit to exercise this pattern
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/GameVariables.h"
#include "PokerX/engine/Player.h"
#include "PokerX/engine/PlayerManager.h"

using namespace pokerx;

/**
 *  We create a simple fake Player
 *
 */
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


class GameVariableObserverTests : public ::testing::Test {
public:
    PlayerManager playerManager;

    GameVariableObserverTests() {
        playerManager = PlayerManager::populate<FakePlayer>(6, 100.0);
    };
};


TEST_F(GameVariableObserverTests, CheckThatGetGameVariablesDoesNotReturnNullptr) {
    GameVariables gameVariables; //observed

    // We artificially change the amount to call
    gameVariables.setAmountToCall(10.0);

    // Notify observers of the change
    playerManager.update(gameVariables, "amountToCall");

    ASSERT_NE(playerManager[0], nullptr);

}

TEST_F(GameVariableObserverTests, CheckThatAmountToCallIsProperlyUpdated) {
    GameVariables gameVariables; //observed

    // We artificially change the amount to call
    gameVariables.setAmountToCall(10.0);

    // Notify observers of the change
    playerManager.update(gameVariables, "amountToCall");

    for (const auto& player : playerManager){
        ASSERT_EQ(10.0, player->getGameVariables()->getAmountToCall());
    }

}

















