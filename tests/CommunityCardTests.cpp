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
    CommunityCards comm = CommunityCards({"6D", "5D", "4H"});

    ASSERT_EQ(*comm[0], "4H");
}


