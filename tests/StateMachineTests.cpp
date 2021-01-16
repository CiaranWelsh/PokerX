/**
 * This is more of an integration style test to ensure I can
 * derive a simple state machine from StateMachine and State.
 * The idea is a simple, basically linear state machine for a
 * light switch. This concept is based on this article:
 *  - https://www.aleksandrhovhannisyan.com/blog/finite-state-machine-fsm-tutorial-implementing-an-fsm-in-c/
 * and I'll use it to derive a PokerEngine state machine.
 *
 * But first, lets make sure it works.
 */

#include "PokerX/engine/StateMachine.h"
#include "AbstractStateMachineTests/LightOff.h"
#include "AbstractStateMachineTests/eState.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace pokerx;


class LightSwitchMachine : public StateMachine {
public:

    LightSwitchMachine() : StateMachine(&LightOff::getInstance()) {};

    void action() override {
        state_->action(this);
    }

    void setState(State &state) override {
        state_->enter(this);
        state_ = &state;
        state_->exit(this);
    }

};


class LightSwitchMachineTests : public ::testing::Test {
public:

    LightSwitchMachineTests() = default;
};



TEST_F(LightSwitchMachineTests, AssertLightMachineIsOffInitially){
    LightSwitchMachine sm;
    ASSERT_EQ(LIGHT_OFF, sm.getState()->getType());
}


TEST_F(LightSwitchMachineTests, CheckThatLightIsLowWhenActionCalledOnce){
    LightSwitchMachine sm;
    sm.action();
    ASSERT_EQ(LIGHT_LOW, sm.getState()->getType());
}

TEST_F(LightSwitchMachineTests, CheckThatLightIsHighWhenActionCalledTwice){
    LightSwitchMachine sm;
    sm.action();
    sm.action();
    ASSERT_EQ(LIGHT_HIGH, sm.getState()->getType());
}

TEST_F(LightSwitchMachineTests, CheckThatLightIsOffAgainWhenActionCalledThreeTimes){
    LightSwitchMachine sm;
    sm.action();
    sm.action();
    sm.action();
    ASSERT_EQ(LIGHT_OFF, sm.getState()->getType());
}






