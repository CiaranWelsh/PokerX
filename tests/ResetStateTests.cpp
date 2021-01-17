#include "gmock/gmock.h"

#include "PokerX/engine/Reset.h"
#include "Mockups/MockPokerEngine.h"
#include "Mockups/MockPot.h"

using namespace pokerx;
using namespace testing;

class ResetStateTests : public ::testing::Test {

public:
    MockPokerEngine engine;
    ResetStateTests() = default;

};

/**
 * This test checks that the ResetState state will call the reset() method of the
 * PokerEngine one time.
 *
 * Remember that it is the function of the unit tests for PokerEngine itself to
 * ensure the *values* set by calling the reset() method are appropriate. Here
 * all we care about is that ResetState calls the reset() method from PokerEngine.
 */
TEST_F(ResetStateTests, CheckThatResetStateCallsTheResetMethodOfPokerEngine) {
    Reset state = Reset::getInstance();
    EXPECT_CALL(engine, reset()).Times(1);
    state.action(&engine);
}

TEST_F(ResetStateTests, CheckThatResetStateCallsTheSetStateMethodOfPokerEngine) {
    Reset state = Reset::getInstance();
    EXPECT_CALL(engine, setState).Times(1);
    state.action(&engine);
}












