//
// Created by Ciaran Welsh on 30/01/2021.
//

#include <PokerX/engine/Evaluator.h>
#include "gtest/gtest.h"
#include "hands/TestHands.h"
#include <algorithm>

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

TEST_F(HandTests, TestTwoHighCards) {
    hands.highCardAceTen > hands.highCardAceKing;
//    Evaluator evaluator;
//    std::vector<Hand> h(
//            {
//                    hands.highCardAceTen,
//                    hands.highCardAceKing,
//            });
//    std::max(h);
//    Hand hc1 = hands.highCardAceTen;
//    Hand hc2 = hands.highCardAceKing;

}















