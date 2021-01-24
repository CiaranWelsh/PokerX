//
// Created by Ciaran on 16/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "AbstractStateMachineTests/LightOff.h"
#include "AbstractStateMachineTests/LightLow.h"
#include "AbstractStateMachineTests/LightHigh.h"
#include "AbstractStateMachineTests/enumState.h"

class LightSwitchStateTests : public ::testing::Test {
public:
    LightSwitchStateTests() = default;

};


TEST_F(LightSwitchStateTests, AssertLightOffCanBeInstantiated) {
    ASSERT_NO_THROW(LightOff& off = LightOff::getInstance());
}


TEST_F(LightSwitchStateTests, AssertReturnedInstanceIsNotNullptr) {
    LightOff& off = LightOff::getInstance();
    ASSERT_NE(nullptr, &off);
}

TEST_F(LightSwitchStateTests, CheckThatWeCanGetTheType) {
    LightOff& off = LightOff::getInstance();
    ASSERT_EQ(off.getType(), LIGHT_OFF);
}










