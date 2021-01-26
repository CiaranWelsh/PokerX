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
    RoyalFlushTests() = default;
};

TEST_F(RoyalFlushTests, TestIsAWhenTrue){
    RoyalFlush royalFlush(hands.royal_flush1.getCards());
    ASSERT_TRUE(royalFlush.isA());
}









