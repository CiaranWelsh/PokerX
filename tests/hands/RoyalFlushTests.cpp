//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/RoyalFlush.h"

using namespace pokerx;

class RoyalFlushTests : public ::testing::Test {
public:
    TestHands hands;
    Cards cards;
    RoyalFlushTests() = default;
};

TEST_F(RoyalFlushTests, TestIsA){
    RoyalFlush royalFlush(hands.royalFlushClubs);
    ASSERT_TRUE(royalFlush.isA());
}

TEST_F(RoyalFlushTests, TestBest5){
    RoyalFlush royalFlush(hands.royalFlushClubs);
    CardCollection cc ({
            &cards.tenOfClubs,
            &cards.jackOfClubs,
            &cards.queenOfClubs,
            &cards.kingOfClubs,
            &cards.aceOfClubs,
    });
    ASSERT_EQ(cc, *royalFlush.getBestFive());
}









