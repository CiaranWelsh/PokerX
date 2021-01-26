//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/Flush.h"

using namespace pokerx;

class FlushTests : public ::testing::Test {
public:
    TestHands hands;
    FlushTests() = default;
};

TEST_F(FlushTests, TestPairIsWhenItISAPair){
    pokerx::Flush flush(hands.flush1.getCards());
    ASSERT_TRUE(flush.isA());
}










