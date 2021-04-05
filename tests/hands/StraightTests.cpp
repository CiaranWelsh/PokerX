//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/Straight.h"

using namespace pokerx;

class StraightTests : public ::testing::Test {
public:
    Cards cards;
    TestHands hands;

    StraightTests() = default;
};

TEST_F(StraightTests, StraightAto5) {
    pokerx::Straight straight(hands.straightAto5);
    ASSERT_TRUE(straight.isA());
}

TEST_F(StraightTests, Straight2To6) {
    pokerx::Straight straight(hands.straight2to6);
    ASSERT_TRUE(straight.isA());
}


TEST_F(StraightTests, Straight2To62) {
    pokerx::Straight straight(hands.straight2to6_2);
    ASSERT_TRUE(straight.isA());
}


TEST_F(StraightTests, Straight4) {
    pokerx::Straight straight(hands.straight5to9);
    ASSERT_TRUE(straight.isA());
}

TEST_F(StraightTests, Straight5) {
    pokerx::Straight straight(hands.straight7toJ);
    ASSERT_TRUE(straight.isA());
}


TEST_F(StraightTests, Straight6) {
    pokerx::Straight straight(hands.straight2to9);
    ASSERT_TRUE(straight.isA());
}

TEST_F(StraightTests, Straight7) {
    pokerx::Straight straight(hands.straight10toAce);
    ASSERT_TRUE(straight.isA());
}

TEST_F(StraightTests, Straight8) {
    pokerx::Straight straight(hands.straightWithPairs);
    ASSERT_TRUE(straight.isA());
}


TEST_F(StraightTests, StraightAto5Best5) {
    pokerx::Straight straight(hands.straightAto5);
    CardCollection cc({"AC", "2C", "3D", "4H", "5S"});
    ASSERT_EQ(cc, *straight.getBestFive());
}

TEST_F(StraightTests, Straight2To6Best5) {
    pokerx::Straight straight(hands.straight2to6);
    CardCollection cc({"2C", "3D", "4H", "5S", "6D"});
    ASSERT_EQ(cc, *straight.getBestFive());
}


TEST_F(StraightTests, Straight2To62Best5) {
    pokerx::Straight straight(hands.straight2to6_2);
    CardCollection cc({"2C", "3D", "4H", "5S", "6C"});
    ASSERT_EQ(cc, *straight.getBestFive());
}


TEST_F(StraightTests, Straight4Best5) {
    pokerx::Straight straight(hands.straight5to9);
    CardCollection cc({"5C", "6H", "7C", "8D", "9C"});
    ASSERT_EQ(cc, *straight.getBestFive());
}

TEST_F(StraightTests, Straight5Best5) {
    pokerx::Straight straight(hands.straight7toJ);
    CardCollection cc({"7H", "8D", "9C", "10D", "JD"});
    ASSERT_EQ(cc, *straight.getBestFive());
}


TEST_F(StraightTests, Straight6Best5) {
    pokerx::Straight straight(hands.straight2to9);
    CardCollection cc({"4C", "5H", "6S", "7H", "8D"});
    ASSERT_EQ(cc, *straight.getBestFive());
}


TEST_F(StraightTests, Straight7Best5TenToAce) {
    pokerx::Straight straight(hands.straight10toAce);
    CardCollection cc({"10S", "JC", "QH", "KH", "AC"});
    ASSERT_EQ(cc, *straight.getBestFive());
}


TEST_F(StraightTests, StraightWithPairs) {
    pokerx::Straight straight(hands.straightWithPairs);
    CardCollection cc({"10S", "JC", "QH", "KH", "AC"});
    ASSERT_EQ(cc, *straight.getBestFive());
}







