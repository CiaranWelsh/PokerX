//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/ThreeOfAKind.h"

using namespace pokerx;

class ThreeOfAKindTests : public ::testing::Test {
public:
    TestHands hands;
    ThreeOfAKindTests() = default;
};

TEST_F(ThreeOfAKindTests, TestThreeOfAKindIsWhenItISAThreeOfAKind){
    pokerx::ThreeOfAKind ThreeOfAKind(hands.three_of_a_kind1.getCards());
    ASSERT_TRUE(ThreeOfAKind.isA());
}







