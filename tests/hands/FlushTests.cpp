//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/Pair.h"

using namespace pokerx;

class PairTests : public ::testing::Test {
public:
    TestHands hands;
    PairTests() = default;
};

TEST_F(PairTests, TestPairIsWhenItISAPair){
    pokerx::Pair pair(hands.pair1.getCards());
    ASSERT_TRUE(pair.isA());
}


TEST_F(PairTests, TestPairIsWhenItISAPair2){
    pokerx::Pair pair(hands.pair2.getCards());
    ASSERT_TRUE(pair.isA());
}


TEST_F(PairTests, TestPairIsWhenItIsNot){
    pokerx::Pair pair(hands.highCard1.getCards());
    ASSERT_FALSE(pair.isA());
}







