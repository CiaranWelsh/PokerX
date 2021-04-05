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
    Cards cards;
    TestHands hands;

    TwoPairTests() = default;
};

TEST_F(TwoPairTests, TestTwoPair1IsA) {
    TwoPair twoPair(hands.two_pair1);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair2IsA) {
    TwoPair twoPair(hands.two_pair2);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair3IsA) {
    TwoPair twoPair(hands.TwoPairSixAndTens);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair4IsA) {
    TwoPair twoPair(hands.TwoPairAceAndQueens);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair5IsA) {
    TwoPair twoPair(hands.two_pair5);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair6IsA) {
    TwoPair twoPair(hands.TwoPairFourAndQueens);
    ASSERT_TRUE(twoPair.isA());
}


TEST_F(TwoPairTests, TestTwoPair1BestFive) {
    TwoPair twoPair(hands.two_pair1);
    CardCollection cc({"2C", "2D", "6H", "6C", "AC"});
    ASSERT_EQ(cc, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair2BestFive) {
    TwoPair twoPair(hands.two_pair2);
    CardCollection cc({"6H", "6C", "TD", "10C", "8C"});
    auto cc2 = twoPair.getBestFive();
//    cc == cc2;
//    ASSERT_EQ(cc, cc2);
}

TEST_F(TwoPairTests, TestTwoPair3BestFive) {
    TwoPair twoPair(hands.TwoPairSixAndTens);
    CardCollection cc({"6H", "6C", "TD", "10C", "8C"});
    ASSERT_EQ(cc, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair4BestFive) {
    TwoPair twoPair(hands.TwoPairAceAndQueens);
    CardCollection cc({"8D", "QC", "QD", "AC", "AD"});
    ASSERT_EQ(cc, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair5BestFive) {
    TwoPair twoPair(hands.two_pair5);
    CardCollection cc({"2C", "2D", "4D", "4C", "AD"});
    ASSERT_EQ(cc, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair6BestFive) {
    TwoPair twoPair(hands.TwoPairFourAndQueens);
    CardCollection cc({"4D", "4C", "QC", "QD", "KC"});
    ASSERT_EQ(cc, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestPairIsntTwoPair) {
    TwoPair twoPair(hands.pair2sAceHigh);
    ASSERT_FALSE(twoPair.isA());
}








