//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/TwoPair.h"

using namespace pokerx;

class TwoPairTests : public ::testing::Test {
public:
    TestHands hands;
    TwoPairTests() = default;
};

TEST_F(TwoPairTests, TestTwoPair1){
    pokerx::TwoPair twoPair(hands.two_pair1.getCards());
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair2){
    pokerx::TwoPair twoPair(hands.two_pair2.getCards());
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair3){
    pokerx::TwoPair twoPair(hands.two_pair3.getCards());
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair4){
    pokerx::TwoPair twoPair(hands.two_pair4.getCards());
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair5){
    pokerx::TwoPair twoPair(hands.two_pair5.getCards());
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair6){
    pokerx::TwoPair twoPair(hands.two_pair6.getCards());
    ASSERT_TRUE(twoPair.isA());
}









