//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/FullHouse.h"

using namespace pokerx;

class FlushTests : public ::testing::Test {
public:
    TestHands hands;
    FlushTests() = default;
};

TEST_F(FlushTests, TestFullhouse1){
    pokerx::FullHouse fullHouse(hands.full_house1.getCards());
    ASSERT_TRUE(fullHouse.isA());
}


TEST_F(FlushTests, TestFullHouse){
    pokerx::FullHouse fullHouse(hands.full_house2.getCards());
    ASSERT_TRUE(fullHouse.isA());
}








