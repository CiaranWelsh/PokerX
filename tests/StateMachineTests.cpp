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

#include <PokerX/engine/Action.h>
#include "PokerX/engine/StateMachine.h"
#include "AbstractStateMachineTests/LightOff.h"
#include "AbstractStateMachineTests/enumState.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace pokerx;


class LightSwitchMachine : public StateMachine {
public:

    LightSwitchMachine() : StateMachine(&LightOff::getInstance()) {};

    void action(Action action) override {
        state_->action(this);
    }

    void setState(State &state) override {
        state_->enter(this);
        state_ = &state;
        state_->exit(this);
    }

    void reset() override {
        state_ = &LightOff::getInstance();
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
    sm.action(NONE);
    ASSERT_EQ(LIGHT_LOW, sm.getState()->getType());
}

TEST_F(LightSwitchMachineTests, CheckThatLightIsHighWhenActionCalledTwice){
    LightSwitchMachine sm;
    sm.action(NONE);
    sm.action(NONE);
    ASSERT_EQ(LIGHT_HIGH, sm.getState()->getType());
}

TEST_F(LightSwitchMachineTests, CheckThatLightIsOffAgainWhenActionCalledThreeTimes){
    LightSwitchMachine sm;
    sm.action(NONE);
    sm.action(NONE);
    sm.action(NONE);
    ASSERT_EQ(LIGHT_OFF, sm.getState()->getType());
}


TEST_F(LightSwitchMachineTests, CheckThatResetMethodReturnsTheStateMachineToOffPosition){
    LightSwitchMachine sm;
    sm.action(NONE);
    sm.action(NONE); // StateMachine is in the LIGHT_HIGH state
    sm.reset(); // reset StateMachine back to LIGHT_OFF state
    ASSERT_EQ(LIGHT_OFF, sm.getState()->getType());
}






