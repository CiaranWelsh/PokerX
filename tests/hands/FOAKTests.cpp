//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/FourOfAKind.h"

using namespace pokerx;

class FourOfAKindTests : public ::testing::Test {
public:
    TestHands hands;
    Cards cards;

    FourOfAKindTests() = default;
};

TEST_F(FourOfAKindTests, TestFourOfAKindIsWhenItISAFourOfAKind) {
    pokerx::FourOfAKind FourOfAKind(hands.four_of_a_kind.getCards());
    ASSERT_TRUE(FourOfAKind.isA());
}


TEST_F(FourOfAKindTests, TestFourOfAKindBest5) {
    pokerx::FourOfAKind FourOfAKind(hands.four_of_a_kind.getCards());
    CardCollection cc({
                              &cards.twoOfClubs,
                              &cards.twoOfDiamonds,
                              &cards.twoOfHearts,
                              &cards.twoOfSpades,
                              &cards.aceOfDiamonds,
                      });
    ASSERT_EQ(cc, *FourOfAKind.getBestFive());

}







