//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/Straight.h"

using namespace pokerx;

class StraightTests : public ::testing::Test {
public:
    TestHands hands;
    StraightTests() = default;
};

TEST_F(StraightTests, Straight2To6){
    pokerx::Straight straight(hands.straight2to6.getCards());
    ASSERT_TRUE(straight.isA());
}


TEST_F(StraightTests, Straight2To62){
    pokerx::Straight straight(hands.straight2to6_2.getCards());
    ASSERT_TRUE(straight.isA());
}


TEST_F(StraightTests, Straight4){
    pokerx::Straight straight(hands.straight4.getCards());
    ASSERT_FALSE(straight.isA());
}

TEST_F(StraightTests, Straight5){
    pokerx::Straight straight(hands.straight5.getCards());
    ASSERT_FALSE(straight.isA());
}







