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
    Cards cards;

    ThreeOfAKindTests() = default;
};

TEST_F(ThreeOfAKindTests, TestThreeOfAKindIsWhenItISAThreeOfAKind) {
    pokerx::ThreeOfAKind threeOfAKind(hands.threeOfAKindThrees);
    ASSERT_TRUE(threeOfAKind.isA());
}


TEST_F(ThreeOfAKindTests, TestThreeOfAKindBestFive) {
    pokerx::ThreeOfAKind threeOfAKind(hands.threeOfAKindThrees);
    CardCollection cc({"2C", "2D", "2H", "KC", "AD"});
    ASSERT_EQ(cc, *threeOfAKind.getBestFive());
}







