//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_FULLGAMETESTS_H
#define POKERSIMULATIONSINCPP_FULLGAMETESTS_H

/**
 * What is it that I'm actually trying to do?
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "eval/Hand.h"
#include "Mockups/MockCard.h"

using namespace testing;


class FullGameTests : public ::testing::Test {
public:

    HandTests() = default;
};


/**
 * State design pattern? State machine
 * Mediator pattern
 */
TEST_F(FullGameTests, WhatDoIWantTheAPIToLookLike) {

    Poker poker(2, 1, 2); // 2 player game; small blind is 1, big is 2;



}

















#endif //POKERSIMULATIONSINCPP_FULLGAMETESTS_H
