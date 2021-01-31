//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/HighCard.h"

using namespace pokerx;

class HighCardTests : public ::testing::Test {
public:
    Cards cards;
    TestHands hands;

    HighCardTests() = default;
};

TEST_F(HighCardTests, TestHighCard1IsA) {
    pokerx::HighCard highCard(hands.highCardAceTen);
    ASSERT_TRUE(highCard.isA());
}


TEST_F(HighCardTests, TestHighCard1BestFive) {
    pokerx::HighCard highCard(hands.highCardAceTen);
    CardCollection expected({
                                    &cards.sixOfHearts,
                                    &cards.sevenOfClubs,
                                    &cards.eightOfClubs,
                                    &cards.tenOfDiamonds,
                                    &cards.aceOfClubs,
                            });
    auto best5 = highCard.getBestFive();
    ASSERT_TRUE(expected == *best5);
}


TEST_F(HighCardTests, TestHighCard2IsA) {
    pokerx::HighCard highCard(hands.highCardAceKing);
    ASSERT_TRUE(highCard.isA());
}


TEST_F(HighCardTests, TestHighCard2BestFive) {
    pokerx::HighCard highCard(hands.highCardAceKing);
    CardCollection expected({
                                    &cards.eightOfClubs,
                                    &cards.nineOfDiamonds,
                                    &cards.tenOfDiamonds,
                                    &cards.kingOfHearts,
                                    &cards.aceOfHearts
                            });
    auto best5 = highCard.getBestFive();
    ASSERT_TRUE(expected == *best5);
}











