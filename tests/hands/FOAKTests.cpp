//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/FourOfAKind.h"

using namespace pokerx;

class FourOfAKindTests : public ::testing::Test {
public:
    TestHands hands;
    FourOfAKindTests() = default;
};

TEST_F(FourOfAKindTests, TestFourOfAKindIsWhenItISAFourOfAKind){
    pokerx::FourOfAKind FourOfAKind(hands.four_of_a_kind.getCards());
    ASSERT_TRUE(FourOfAKind.isA());
}







