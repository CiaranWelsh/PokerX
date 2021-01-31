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
    Cards cards;
    TestHands hands;

    PairTests() = default;
};

TEST_F(PairTests, TestPairIsWhenItISAPair) {
    pokerx::Pair pair(hands.pair2sAceHigh);
    ASSERT_TRUE(pair.isA());
}


TEST_F(PairTests, TestPairIsWhenItISAPair2) {
    pokerx::Pair pair(hands.pair10s8high);
    ASSERT_TRUE(pair.isA());
}


TEST_F(PairTests, TestPairIsWhenItIsNot) {
    pokerx::Pair pair(hands.highCardAceTen);
    ASSERT_FALSE(pair.isA());
}


TEST_F(PairTests, TestPairIsWhenItISAPairBest5) {
    pokerx::Pair pair(hands.pair2sAceHigh);
    auto bestFive = pair.getBestFive();
    CardCollection cc({
                              &cards.twoOfClubs,
                              &cards.twoOfDiamonds,
                              &cards.eightOfClubs,
                              &cards.tenOfDiamonds,
                              &cards.aceOfClubs,
                      });
    ASSERT_TRUE(*bestFive == cc);
}

TEST_F(PairTests, TestPairIsWhenItISAPairBest5Pair2) {
    pokerx::Pair pair(hands.pair10s8high);
    auto bestFive = pair.getBestFive();
    CardCollection cc({
                              &cards.sixOfHearts,
                              &cards.sevenOfClubs,
                              &cards.eightOfClubs,
                              &cards.tenOfDiamonds,
                              &cards.tenOfClubs,
                      });
    ASSERT_EQ(*bestFive, cc);
}








