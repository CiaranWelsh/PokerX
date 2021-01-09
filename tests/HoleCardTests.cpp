//
// Created by CiaranWelsh on 18/12/2019.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "card/HoleCards.h"
#include "Mockups/MockCard.h"

using namespace testing;

TEST(HoleCardTests, HoleCardTestGetRank) {
    MockCard card1(4, "S");
    MockCard card2(2, "D");

    EXPECT_CALL(card1, getRank()).Times(1).WillRepeatedly(Return(4));

    HoleCards h(&card1, &card2);
    ASSERT_TRUE(h[0]->getRank() == 4);
}

TEST(HoleCardTests, TestHoleCardFailsWithMoreThanTwoCards) {
    MockCard card1(4, "S");
    MockCard card2(4, "D");
    MockCard card3(6, "D");

    HoleCards h(&card1, &card2);
    ASSERT_THROW(h.add(&card3), std::logic_error);
}

