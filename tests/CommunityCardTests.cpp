//
// Created by CiaranWelsh on 18/12/2019.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Mockups/MockCard.h"
#include "PokerX/engine/CommunityCards.h"

using namespace testing;

class CommunityCardTests : public ::testing::Test {
public:

    MockCards mockCards;

    CommunityCardTests() = default;
};

TEST_F(CommunityCardTests, EnsureCorrectRepresentationOfCardsInCollection) {
    CommunityCards comm = CommunityCards(&mockCards.sixOfDiamonds, &mockCards.fiveOfDiamonds, &mockCards.fourOfHearts);
    EXPECT_CALL(mockCards.fourOfHearts, getRank()).WillRepeatedly(Return(4));
    EXPECT_CALL(mockCards.fourOfHearts, getSuit()).WillRepeatedly(Return("H"));

    ASSERT_EQ(comm[0]->getRank(), 4);
    ASSERT_EQ(comm[0]->getSuit(), "H");
}


