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
    pokerx::TwoPair twoPair(hands.two_pair1);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair2IsA) {
    pokerx::TwoPair twoPair(hands.two_pair2);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair3IsA) {
    pokerx::TwoPair twoPair(hands.TwoPairSixAndTens);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair4IsA) {
    pokerx::TwoPair twoPair(hands.TwoPairAceAndQueens);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair5IsA) {
    pokerx::TwoPair twoPair(hands.two_pair5);
    ASSERT_TRUE(twoPair.isA());
}

TEST_F(TwoPairTests, TestTwoPair6IsA) {
    pokerx::TwoPair twoPair(hands.TwoPairFourAndQueens);
    ASSERT_TRUE(twoPair.isA());
}


TEST_F(TwoPairTests, TestTwoPair1BestFive) {
    pokerx::TwoPair twoPair(hands.two_pair1);
    CardCollection expected({
                                    &cards.twoOfClubs,
                                    &cards.twoOfDiamonds,
                                    &cards.sixOfHearts,
                                    &cards.sixOfClubs,
                                    &cards.aceOfClubs,
                            });
    ASSERT_EQ(expected, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair2BestFive) {
    pokerx::TwoPair twoPair(hands.two_pair2);
    CardCollection expected({
                                    &cards.sixOfHearts,
                                    &cards.sixOfClubs,
                                    &cards.tenOfDiamonds,
                                    &cards.tenOfClubs,
                                    &cards.eightOfClubs
                            });
    ASSERT_EQ(expected, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair3BestFive) {
    pokerx::TwoPair twoPair(hands.TwoPairSixAndTens);
    CardCollection expected({
                                    &cards.sixOfHearts,
                                    &cards.sixOfClubs,
                                    &cards.tenOfDiamonds,
                                    &cards.tenOfClubs,
                                    &cards.eightOfClubs,
                            });
    ASSERT_EQ(expected, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair4BestFive) {
    pokerx::TwoPair twoPair(hands.TwoPairAceAndQueens);
    CardCollection expected({
                                    &cards.eightOfDiamonds,
                                    &cards.queenOfClubs,
                                    &cards.queenOfDiamonds,
                                    &cards.aceOfClubs,
                                    &cards.aceOfDiamonds,
                            });
    ASSERT_EQ(expected, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair5BestFive) {
    pokerx::TwoPair twoPair(hands.two_pair5);
    CardCollection expected({
                                    &cards.twoOfClubs,
                                    &cards.twoOfDiamonds,
                                    &cards.fourOfDiamonds,
                                    &cards.fourOfClubs,
                                    &cards.aceOfDiamonds,
                            });
    ASSERT_EQ(expected, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestTwoPair6BestFive) {
    pokerx::TwoPair twoPair(hands.TwoPairFourAndQueens);
    CardCollection expected({
                                    &cards.fourOfDiamonds,
                                    &cards.fourOfClubs,
                                    &cards.queenOfDiamonds,
                                    &cards.queenOfClubs,
                                    &cards.kingOfClubs
                            });
    ASSERT_EQ(expected, *twoPair.getBestFive());
}

TEST_F(TwoPairTests, TestPairIsntTwoPair){
    TwoPair twoPair(hands.pair2sAceHigh);
    ASSERT_FALSE(twoPair.isA());
}








