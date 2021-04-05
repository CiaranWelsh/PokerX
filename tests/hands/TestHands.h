//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_TESTHANDS_H
#define POKERX_TESTHANDS_H

#include "Mockups/MockCard.h"
#include "PokerX/engine/hands/Hand.h"

class TestHands {
public:
    Cards cards;

    TestHands() = default;

//    static Hand createHand(ICard *hc1, ICard *hc2, ICard *flop1, ICard *flop2, ICard *flop3, ICard *turn, ICard *river) {
//        return Hand({hc1, hc2, flop1, flop2, flop3, turn, river});
//    }

    static Hand createHand(
            const std::string & hc1, const std::string & hc2, const std::string & flop1,
            const std::string & flop2, const std::string & flop3, const std::string & turn,
            const std::string & river) {
        return Hand({hc1, hc2, flop1, flop2, flop3, turn, river});
    }

    Hand highCardAceTen = createHand("2C", "4D", "6H", "7C", "8C", "TD", "AC");

    Hand highCardAceKing = createHand("2C", "4S", "9D", "10D", "8C", "KH", "AH");

    Hand pair2sAceHigh = createHand("2C", "2D", "6H", "7C", "10D", "AC", "8C");

    Hand pair10s8high = createHand("2C", "4D", "6H", "7C", "10D", "10C", "8C");

    Hand two_pair1 = createHand("2C", "2D", "6H", "6C", "10D", "AC", "8C");

    Hand two_pair2 = createHand("2C", "4D", "6H", "6C", "10D", "10C", "8C");

    Hand TwoPairSixAndTens = createHand("6H", "6C", "10D", "10C", "8C", "2C", "2D");

    Hand TwoPairAceAndQueens = createHand("2C", "8D", "8C", "QC", "QD", "AD", "AC");

    Hand two_pair5 = createHand("2C", "2D", "4D", "4C", "QD", "AD", "KC");

    Hand TwoPairFourAndQueens = createHand("2C", "2D", "4D", "4C", "QD", "QC", "KC");

    Hand threeOfAKindThrees = createHand("2C", "2D", "2H", "4C", "QD", "AD", "KC");

    Hand three_of_a_kind2 = createHand("4C", "5C", "QD", "AD", "KC", "KS", "KD");

    Hand fullHouseTwosfullOfThrees = createHand("2C", "2D", "2H", "QC", "QD", "AD", "KC");

    Hand fullHouseEightsFullOfQueens = createHand("8C", "8D", "8H", "QC", "QD", "AD", "KC");

    Hand fourOfAKindTwos = createHand("2C", "2D", "2H", "2S", "QD", "AD", "KC");

    Hand fourOfAKindSixes = createHand("2C", "3D", "6S", "6D", "6C", "6H", "KC");

    Hand straight2to6 = createHand("2C", "3D", "4H", "5S", "6D", "AD", "KC");

    Hand straightAto5 = createHand("AC", "2C", "3D", "4H", "5S", "KC", "QC");

    Hand straight2to6_2 = createHand("2C", "3D", "4H", "5S", "6C", "QC", "KC");

    Hand straight5to9 = createHand("2C", "5C", "6H", "7C", "8D", "9C", "KH");

    Hand straight7toJ = createHand("2C", "5D", "7H", "8D", "9C", "TD", "JD");

    Hand straight2to9 = createHand("2C", "3D", "4C", "5H", "6S", "7H", "8D");

    Hand straight10toAce = createHand("2C", "3D", "TS", "JC", "QH", "KH", "AC");

    Hand straightWithPairs = createHand("QS", "AD", "TS", "JC", "QH", "KH", "AC");

    Hand flushKingHigh = createHand("2C", "5C", "7C", "8D", "9C", "TD", "KC");

    Hand flushTenHigh = createHand("2C", "5C", "7C", "8D", "9C", "10C", "2D");

    Hand straightFlushSixHigh = createHand("2C", "3C", "4C", "5C", "6C", "TD", "JS");

    Hand straightFlushTenHigh = createHand("2C", "3C", "6C", "7C", "8C", "9C", "10C");

    Hand straight_flush3 = createHand("2C", "3C", "4C", "5C", "6C", "7C", "JC");

    Hand royalFlushClubs = createHand("10C", "JC", "QC", "KC", "AC", "TD", "JS");

    Hand royalFlushDiamonds = createHand("TD", "JD", "QD", "KD", "AD", "TC", "JS");
};

#endif //POKERX_TESTHANDS_H
