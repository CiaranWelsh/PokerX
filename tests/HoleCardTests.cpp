//
// Created by CiaranWelsh on 18/12/2019.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PokerX/engine/HoleCards.h"
#include "Mockups/MockCard.h"

using namespace testing;

class HoleCardTests : public ::testing::Test {
public:
    Cards cards;
    HoleCardTests() = default;
};

TEST_F(HoleCardTests, HoleCardTestGetRank) {
    HoleCards h({"4S", "2D"});
    ASSERT_TRUE(h[0]->getRank() == 2);
}

TEST_F(HoleCardTests, TestHoleCardFailsWithMoreThanTwoCards) {
    HoleCards h({"4S", "4D"});
    ASSERT_THROW(h.add({"6H"}), std::logic_error);
}

