//
// Created by Ciaran Welsh on 30/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "hands/TestHands.h"
#include "PokerX/engine/hands/Straight.h"

using namespace pokerx;

class HandTests : public ::testing::Test {
public:
    Cards cards;
    TestHands hands;

    HandTests() = default;
};


/**
 * I want something that I can pass to std::max. How to go about implementing this?
 */

TEST_F(HandTests, TestTwoHighCards){
    std::vector<Hand> hands;
//    Hand hc1 = hands.highCard1;
//    Hand hc2 = hands.highCard2;

}















