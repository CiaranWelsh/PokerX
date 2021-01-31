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
    ASSERT_EQ(hands.highCardAceTen.getType(), HIGH_CARD);
}

TEST_F(HandTests, TesthighCard2) {
    ASSERT_EQ(hands.highCardAceKing.getType(), HIGH_CARD);
}

TEST_F(HandTests, Testpair1) {
    ASSERT_EQ(hands.pair2sAceHigh.getType(), PAIR);
}

TEST_F(HandTests, Testpair2) {
    ASSERT_EQ(hands.pair10s8high.getType(), PAIR);
}

TEST_F(HandTests, TestTwoPair1) {
    ASSERT_EQ(hands.two_pair1.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair2) {
    ASSERT_EQ(hands.two_pair2.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair3) {
    ASSERT_EQ(hands.TwoPairSixAndTens.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair4) {
    ASSERT_EQ(hands.TwoPairAceAndQueens.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair5) {
    ASSERT_EQ(hands.two_pair5.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestTwoPair6) {
    ASSERT_EQ(hands.TwoPairFourAndQueens.getType(), TWO_PAIR);
}

TEST_F(HandTests, TestThreeOfAKind) {
    ASSERT_EQ(hands.threeOfAKindThrees.getType(), THREE_OF_A_KIND);
}

TEST_F(HandTests, TestFullHouse1) {
    ASSERT_EQ(hands.fullHouseTwosfullOfThrees.getType(), FULL_HOUSE);
}

TEST_F(HandTests, TestFullHouse2) {
    ASSERT_EQ(hands.fullHouseEightsFullOfQueens.getType(), FULL_HOUSE);
}

TEST_F(HandTests, TestFourOfAKind) {
    ASSERT_EQ(hands.fourOfAKindTwos.getType(), FOUR_OF_A_KIND);
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
    ASSERT_EQ(hands.flushKingHigh.getType(), FLUSH);
}

TEST_F(HandTests, TestStraightFlush) {
    ASSERT_EQ(hands.straightFlushSixHigh.getType(), STRAIGHT_FLUSH);
}

TEST_F(HandTests, TestStraightFlush2) {
    ASSERT_EQ(hands.straightFlushTenHigh.getType(), STRAIGHT_FLUSH);
}

TEST_F(HandTests, TestStraightFlush3) {
    ASSERT_EQ(hands.straight_flush3.getType(), STRAIGHT_FLUSH);
}

TEST_F(HandTests, TestRoyalFlush) {
    ASSERT_EQ(hands.royalFlushClubs.getType(), ROYAL_FLUSH);
}


/**
 * for high card winner is highest 5 cards
 */
TEST_F(HandTests, HighCardEqualityWhenFalse) {
    Hand h1 = hands.highCardAceTen;
    Hand h2 = hands.highCardAceKing;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, HighCardEqualityWhenTrue) {
    Hand h1 = hands.highCardAceTen;
    Hand h2 = hands.highCardAceTen;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, HighCardGL) {
    Hand h1 = hands.highCardAceTen;
    Hand h2 = hands.highCardAceKing;
    ASSERT_FALSE(h1 > h2);
}

TEST_F(HandTests, HighCardLT) {
    Hand h1 = hands.highCardAceTen;
    Hand h2 = hands.highCardAceKing;
    ASSERT_TRUE(h1 < h2);
}


TEST_F(HandTests, PairEqualityWhenFalse) {
    Hand h1 = hands.pair2sAceHigh;
    Hand h2 = hands.pair10s8high;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, PairEqualityWhenTrue) {
    Hand h1 = hands.pair2sAceHigh;
    Hand h2 = hands.pair2sAceHigh;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, PairGL) {
    Hand h1 = hands.pair2sAceHigh;
    Hand h2 = hands.pair10s8high;
    ASSERT_FALSE(h1 > h2);
}

TEST_F(HandTests, PairLT) {
    Hand h1 = hands.pair2sAceHigh;
    Hand h2 = hands.pair10s8high;
    ASSERT_TRUE(h1 < h2);
}

TEST_F(HandTests, TwoPairEqualityWhenFalse) {
    Hand h1 = hands.two_pair1;
    Hand h2 = hands.two_pair2;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, TwoPairEqualityWhenTrue) {
    Hand h1 = hands.TwoPairSixAndTens;
    Hand h2 = hands.TwoPairSixAndTens;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, TwoPairGL) {
    Hand h1 = hands.two_pair1;
    Hand h2 = hands.two_pair5;
    ASSERT_TRUE(h1 > h2);
}

TEST_F(HandTests, TwoPairLT) {
    Hand h1 = hands.TwoPairAceAndQueens;
    Hand h2 = hands.TwoPairFourAndQueens;
    ASSERT_FALSE(h1 < h2);
}


TEST_F(HandTests, TOAKEqualityWhenFalse) {
    Hand h1 = hands.threeOfAKindThrees;
    Hand h2 = hands.three_of_a_kind2;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, TOAKEqualityWhenTrue) {
    Hand h1 = hands.threeOfAKindThrees;
    Hand h2 = hands.threeOfAKindThrees;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, TOAKGL) {
    Hand h1 = hands.threeOfAKindThrees;
    Hand h2 = hands.three_of_a_kind2;
    ASSERT_TRUE(h2 > h1);
}

TEST_F(HandTests, StraightEqualityWhenFalse) {
    Hand h1 = hands.straight2to6_2;
    Hand h2 = hands.straight10toAce;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, StraightEqualityWhenTrue) {
    Hand h1 = hands.straight2to6_2;
    Hand h2 = hands.straight2to6_2;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, StraightGL) {
    Hand h1 = hands.straight2to6_2;
    Hand h2 = hands.straight10toAce;
    ASSERT_TRUE(h2 > h1);
}

TEST_F(HandTests, StraightLT) {
    Hand h1 = hands.straight2to6_2;
    Hand h2 = hands.straight10toAce;
    ASSERT_FALSE(h2 < h1);
}


TEST_F(HandTests, FlushEqualityWhenFalse) {
    Hand h1 = hands.flushKingHigh;
    Hand h2 = hands.flushTenHigh;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, FlushEqualityWhenTrue) {
    Hand h1 = hands.flushKingHigh;
    Hand h2 = hands.flushKingHigh;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, FlushGL) {
    Hand h1 = hands.flushTenHigh;
    Hand h2 = hands.flushKingHigh;
    ASSERT_TRUE(h2 > h1);
}

TEST_F(HandTests, FlushLT) {
    Hand h1 = hands.flushTenHigh;
    Hand h2 = hands.flushKingHigh;
    ASSERT_TRUE(h1 < h2);
}


TEST_F(HandTests, FullHouseEqualityWhenFalse) {
    Hand h1 = hands.fullHouseTwosfullOfThrees;
    Hand h2 = hands.fullHouseEightsFullOfQueens;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, FullHouseEqualityWhenTrue) {
    Hand h1 = hands.fullHouseTwosfullOfThrees;
    Hand h2 = hands.fullHouseTwosfullOfThrees;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, FullHouseGL) {
    Hand h1 = hands.fullHouseTwosfullOfThrees;
    Hand h2 = hands.fullHouseEightsFullOfQueens;
    ASSERT_TRUE(h2 > h1);
}

TEST_F(HandTests, FullHouseLT) {
    Hand h1 = hands.fullHouseTwosfullOfThrees;
    Hand h2 = hands.fullHouseEightsFullOfQueens;
    ASSERT_TRUE(h1 < h2);
}


TEST_F(HandTests, FourOfAKindEqualityWhenFalse) {
    Hand h1 = hands.fourOfAKindTwos;
    Hand h2 = hands.fourOfAKindSixes;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, FourOfAKindEqualityWhenTrue) {
    Hand h1 = hands.fourOfAKindTwos;
    Hand h2 = hands.fourOfAKindTwos;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, FourOfAKindGL) {
    Hand h1 = hands.fourOfAKindTwos;
    Hand h2 = hands.fourOfAKindSixes;
    ASSERT_TRUE(h2 > h1);
}

TEST_F(HandTests, FourOfAKindLT) {
    Hand h1 = hands.fourOfAKindTwos;
    Hand h2 = hands.fourOfAKindSixes;
    ASSERT_TRUE(h1 < h2);
}

TEST_F(HandTests, StraightFlushEqualityWhenTrue) {
    Hand h1 = hands.straightFlushSixHigh;
    Hand h2 = hands.straightFlushSixHigh;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, StraightFlushEqualityWhenFalse) {
    Hand h1 = hands.straightFlushTenHigh;
    Hand h2 = hands.straightFlushSixHigh;
    ASSERT_FALSE(h1 == h2);
}

TEST_F(HandTests, StraightFlushGL) {
    Hand h1 = hands.straightFlushSixHigh;
    Hand h2 = hands.straightFlushTenHigh;
    ASSERT_TRUE(h2 > h1);
}

TEST_F(HandTests, StraightFlushLT) {
    Hand h1 = hands.straightFlushSixHigh;
    Hand h2 = hands.straightFlushTenHigh;
    ASSERT_TRUE(h1 < h2);
}

TEST_F(HandTests, RoyalFlushEqualityWhenTrue) {
    Hand h1 = hands.royalFlushClubs;
    Hand h2 = hands.royalFlushDiamonds;
    ASSERT_TRUE(h1 == h2);
}

TEST_F(HandTests, RoyalFlushGL) {
    Hand h1 = hands.royalFlushClubs;
    Hand h2 = hands.royalFlushDiamonds;
    ASSERT_FALSE(h2 > h1);
}

TEST_F(HandTests, RoyalFlushLT) {
    Hand h1 = hands.royalFlushClubs;
    Hand h2 = hands.royalFlushDiamonds;
    ASSERT_FALSE(h1 < h2);
}


TEST_F(HandTests, StandardMaxAlgo) {
    std::vector<Hand> h({
                                hands.TwoPairFourAndQueens,
                                hands.pair2sAceHigh,
                                hands.TwoPairAceAndQueens,
                                hands.pair10s8high,
                        });
    auto pos = std::max_element(h.begin(), h.end());
    int idx = std::distance(h.begin(), pos);
    ASSERT_EQ(idx, 2);
}






















