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

TEST_F(HandTests, TestTwoHighCards) {
    std::unordered_map<std::string, Hand> hc{
            {"AceTen", hands.highCardAceTen},
            {"AceKing", hands.highCardAceKing}
    };
    auto [name, hand] = Evaluator::evaluate(hc);

    ASSERT_STREQ(name.c_str(), "AceKing");
    ASSERT_EQ(*hand.bestFiveCards(), std::vector<std::string>({"8C", "9D", "10D", "13H", "14H"}));
}

TEST_F(HandTests, TestHighCardVsPair) {

    std::unordered_map<std::string, Hand> hc{
            {"highCardAceQueen", hands.highCardAceQueen},
            {"pairKings", hands.pairKings}
    };
    auto [name, hand] = Evaluator::evaluate(hc);

    ASSERT_STREQ(name.c_str(), "pairKings");
    ASSERT_EQ(*hand.bestFiveCards(), std::vector<std::string>({"10D", "11C", "12S", "13C", "13H"}));
}















