#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "engine/CallStationPlayer.h"
#include "Mockups/MockEngine.h"

using namespace testing;
using namespace engine;

class CallStationTests : public ::testing::Test {
public:
    CallStationTests() = default;
};


TEST_F(CallStationTests, TestCallStationSelectsCallAction){
    CallStationPlayer callStation;
    MockEngine mockEngine;
    callStation.selectAction(&mockEngine);
}




















