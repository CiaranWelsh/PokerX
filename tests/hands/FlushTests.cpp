//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/Flush.h"

using namespace pokerx;

class FlushTests : public ::testing::Test {
public:
    TestHands hands;
    Cards cards;
    FlushTests() = default;
};

TEST_F(FlushTests, TestFlush){
    pokerx::Flush flush(hands.flush1.getCards());
    ASSERT_TRUE(flush.isA());
}

TEST_F(FlushTests, TestFlushBestFive){
    pokerx::Flush flush(hands.flush1.getCards());
    CardCollection cc({
                              &cards.twoOfClubs,
                              &cards.fiveOfClubs,
                              &cards.sevenOfClubs,
                              &cards.nineOfClubs,
                              &cards.kingOfClubs
                      });
    ASSERT_EQ(cc, *flush.getBestFive());
}










