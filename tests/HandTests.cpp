//
// Created by Ciaran Welsh on 30/01/2021.
//

#include "gtest/gtest.h"
#include "hands/TestHands.h"
#include "PokerX/engine/hands/Straight.h"

/**
 * The Hand class is the public interface to the hand types API.
 * It contains a factory method that reaches out to hand type classes (Pair etc) 
 * to determine the class of a set of cards. Here we test this. 
 */

using namespace pokerx;

class HandTests : public ::testing::Test {
public:
    Cards cards;
    TestHands hands;

    HandTests() = default;
};

TEST_F(HandTests, TesthighCard1) {
    ASSERT_EQ(hands.highCard1.getType(), HIGH_CARD);
}

TEST_F(HandTests, TesthighCard2) {
    ASSERT_EQ(hands.highCard2.getType(), HIGH_CARD);
}

TEST_F(HandTests, Testpair1) {
    ASSERT_EQ(hands.pair1.getType(), PAIR);
}

TEST_F(HandTests, Testpair2) {
    ASSERT_EQ(hands.pair2.getType(), PAIR);
}

TEST_F(HandTests, TestTwoPair1) {
    ASSERT_EQ(hands.two_pair1.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair2) {
    ASSERT_EQ(hands.two_pair2.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair3) {
    ASSERT_EQ(hands.two_pair3.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair4) {
    ASSERT_EQ(hands.two_pair4.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair5) {
    ASSERT_EQ(hands.two_pair5.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair6) {
    ASSERT_EQ(hands.two_pair6.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestThreeOfAKind) {
    ASSERT_EQ(hands.three_of_a_kind1.getType(), THREE_OF_A_KIND);
}

TEST_F(HandTests, TestFullHouse1) {
    ASSERT_EQ(hands.full_house1.getType(), FULL_HOUSE);
}

TEST_F(HandTests, TestFullHouse2) {
    ASSERT_EQ(hands.full_house2.getType(), FULL_HOUSE);
}

TEST_F(HandTests, TestFourOfAKind) {
    ASSERT_EQ(hands.four_of_a_kind.getType(), FOUR_OF_A_KIND);
}

TEST_F(HandTests, Teststraight2to6) {
    ASSERT_EQ(hands.straight2to6.getType(), STRAIGHT);
}

TEST_F(HandTests, TeststraightAto5) {
    ASSERT_EQ(hands.straightAto5.getType(), STRAIGHT);
}

TEST_F(HandTests, Teststraight2to6_2) {
    ASSERT_EQ(hands.straight2to6_2.getType(), STRAIGHT);
}

TEST_F(HandTests, Teststraight5to9) {
    ASSERT_EQ(hands.straight5to9.getType(), STRAIGHT);
}

TEST_F(HandTests, Teststraight7toJ) {
    ASSERT_EQ(hands.straight7toJ.getType(), STRAIGHT);
}

TEST_F(HandTests, Teststraight2to9) {
    ASSERT_EQ(hands.straight2to9.getType(), STRAIGHT);
}

TEST_F(HandTests, Teststraight10toAce) {
    ASSERT_EQ(hands.straight10toAce.getType(), STRAIGHT);
}

TEST_F(HandTests, TeststraightWithPairs) {
    ASSERT_EQ(hands.straightWithPairs.getType(), STRAIGHT);
}

TEST_F(HandTests, Testflush1) {
    ASSERT_EQ(hands.flush1.getType(), FLUSH);
}

TEST_F(HandTests, TestStraightFlush) {
    ASSERT_EQ(hands.straight_flush1.getType(), STRAIGHT_FLUSH);
}

TEST_F(HandTests, TestStraightFlush2) {
    ASSERT_EQ(hands.straight_flush2.getType(), STRAIGHT_FLUSH);
}

TEST_F(HandTests, TestStraightFlush3) {
    ASSERT_EQ(hands.straight_flush3.getType(), STRAIGHT_FLUSH);
}

TEST_F(HandTests, TestRoyalFlush) {
    ASSERT_EQ(hands.royal_flush1.getType(), ROYAL_FLUSH);
}

























