//
// Created by Ciaran on 09/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "eval/Hand.h"
#include "Mockups/MockCard.h"

using namespace testing;


class HandTests : public ::testing::Test {
public:
    MockCards c;

    HandTests() = default;
};

TEST_F(HandTests, TestHighCardIsAMethod) {
    HighCard highCard({&c.twoOfClubs,
                       &c.fiveOfHearts,
                       &c.sevenOfDiamonds,
                       &c.eightOfSpades,
                       &c.jackOfClubs,
                       &c.queenOfClubs,
                       &c.kingOfDiamonds});
}



