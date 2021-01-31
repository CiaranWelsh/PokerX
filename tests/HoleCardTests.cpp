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
    HoleCards h(&cards.fourOfSpades, &cards.twoOfDiamonds);
    ASSERT_TRUE(h[0]->getRank() == 2);
}

TEST_F(HoleCardTests, TestHoleCardFailsWithMoreThanTwoCards) {
    MockCard card1(4, "S");
    MockCard card2(4, "D");
    MockCard card3(6, "D");

    HoleCards h(&card1, &card2);
    ASSERT_THROW(h.add(&card3), std::logic_error);
}

