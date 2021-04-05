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

    static Hand
    createHand(ICard *hc1, ICard *hc2, ICard *flop1, ICard *flop2, ICard *flop3, ICard *turn, ICard *river) {
        return Hand({hc1, hc2, flop1, flop2, flop3, turn, river});
    }

    Hand highCardAceTen = createHand(
            &cards.twoOfClubs,
            &cards.fourOfDiamonds,
            &cards.sixOfHearts,
            &cards.sevenOfClubs,
            &cards.eightOfClubs,
            &cards.tenOfDiamonds,
            &cards.aceOfClubs
    );
    Hand highCardAceKing = createHand(
            &cards.twoOfClubs,
            &cards.fourOfSpades,
            &cards.nineOfDiamonds,
            &cards.tenOfDiamonds,
            &cards.eightOfClubs,
            &cards.kingOfHearts,
            &cards.aceOfHearts
    );
    Hand pair2sAceHigh = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.sixOfHearts,
            &cards.sevenOfClubs,
            &cards.tenOfDiamonds,
            &cards.aceOfClubs,
            &cards.eightOfClubs
    );
    Hand pair10s8high = createHand(
            &cards.twoOfClubs,
            &cards.fourOfDiamonds,
            &cards.sixOfHearts,
            &cards.sevenOfClubs,
            &cards.tenOfDiamonds,
            &cards.tenOfClubs,
            &cards.eightOfClubs
    );
    Hand two_pair1 = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.sixOfHearts,
            &cards.sixOfClubs,
            &cards.tenOfDiamonds,
            &cards.aceOfClubs,
            &cards.eightOfClubs
    );
    Hand two_pair2 = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.sixOfHearts,
            &cards.sixOfClubs,
            &cards.tenOfDiamonds,
            &cards.tenOfClubs,
            &cards.eightOfClubs
    );
    Hand TwoPairSixAndTens = createHand(
            &cards.sixOfHearts,
            &cards.sixOfClubs,
            &cards.tenOfDiamonds,
            &cards.tenOfClubs,
            &cards.eightOfClubs,
            &cards.twoOfClubs,
            &cards.twoOfDiamonds
    );
    Hand TwoPairAceAndQueens = createHand(
            &cards.twoOfDiamonds,
            &cards.eightOfDiamonds,
            &cards.eightOfClubs,
            &cards.queenOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.aceOfClubs
    );

    Hand two_pair5 = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.fourOfDiamonds,
            &cards.fourOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand TwoPairFourAndQueens = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.fourOfDiamonds,
            &cards.fourOfClubs,
            &cards.queenOfDiamonds,
            &cards.queenOfClubs,
            &cards.kingOfClubs
    );
    Hand threeOfAKindThrees = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.twoOfHearts,
            &cards.fourOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand three_of_a_kind2 = createHand(
            &cards.fourOfClubs,
            &cards.fiveOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs,
            &cards.kingOfSpades,
            &cards.kingOfDiamonds
    );
    Hand fullHouseTwosfullOfThrees = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.twoOfHearts,
            &cards.queenOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand fullHouseEightsFullOfQueens = createHand(
            &cards.eightOfClubs,
            &cards.eightOfDiamonds,
            &cards.eightOfHearts,
            &cards.queenOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand fourOfAKindTwos = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.twoOfHearts,
            &cards.twoOfSpades,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand fourOfAKindSixes = createHand(
            &cards.twoOfClubs,
            &cards.threeOfDiamonds,
            &cards.sixOfSpades,
            &cards.sixOfDiamonds,
            &cards.sixOfClubs,
            &cards.sixOfHearts,
            &cards.kingOfClubs
    );
    Hand straight2to6 = createHand(
            &cards.twoOfClubs,
            &cards.threeOfDiamonds,
            &cards.fourOfHearts,
            &cards.fiveOfSpades,
            &cards.sixOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand straightAto5 = createHand(
            &cards.aceOfClubs,
            &cards.twoOfClubs,
            &cards.threeOfDiamonds,
            &cards.fourOfHearts,
            &cards.fiveOfSpades,
            &cards.kingOfClubs,
            &cards.queenOfClubs
    );
    Hand straight2to6_2 = createHand(
            &cards.twoOfClubs,
            &cards.threeOfDiamonds,
            &cards.fourOfHearts,
            &cards.fiveOfSpades,
            &cards.sixOfClubs,
            &cards.queenOfClubs,
            &cards.kingOfClubs
    );
    Hand straight5to9 = createHand(
            &cards.twoOfClubs,
            &cards.fiveOfClubs,
            &cards.sixOfHearts,
            &cards.sevenOfClubs,
            &cards.eightOfDiamonds,
            &cards.nineOfClubs,
            &cards.kingOfHearts
    );
    Hand straight7toJ = createHand(
            &cards.twoOfClubs,
            &cards.fiveOfClubs,
            &cards.sevenOfClubs,
            &cards.eightOfDiamonds,
            &cards.nineOfClubs,
            &cards.tenOfDiamonds,
            &cards.jackOfDiamonds
    );
    Hand straight2to9 = createHand(
            &cards.twoOfClubs,
            &cards.threeOfDiamonds,
            &cards.fourOfClubs,
            &cards.fiveOfHearts,
            &cards.sixOfSpades,
            &cards.sevenOfHearts,
            &cards.eightOfDiamonds
    );
    Hand straight10toAce = createHand(
            &cards.twoOfClubs,
            &cards.threeOfDiamonds,
            &cards.tenOfSpades,
            &cards.jackOfClubs,
            &cards.queenOfHearts,
            &cards.kingOfHearts,
            &cards.aceOfClubs
    );

    Hand straightWithPairs = createHand(
            &cards.queenOfSpades,
            &cards.aceOfDiamonds,
            &cards.tenOfSpades,
            &cards.jackOfClubs,
            &cards.queenOfHearts,
            &cards.kingOfHearts,
            &cards.aceOfClubs
    );

    Hand flushKingHigh = createHand(
            &cards.twoOfClubs,
            &cards.fiveOfClubs,
            &cards.sevenOfClubs,
            &cards.eightOfDiamonds,
            &cards.nineOfClubs,
            &cards.tenOfDiamonds,
            &cards.kingOfClubs
    );

    Hand flushTenHigh = createHand(
            &cards.twoOfClubs,
            &cards.fiveOfClubs,
            &cards.sevenOfClubs,
            &cards.eightOfDiamonds,
            &cards.nineOfClubs,
            &cards.tenOfClubs,
            &cards.twoOfDiamonds
    );
    Hand straightFlushSixHigh = createHand(
            &cards.twoOfClubs,
            &cards.threeOfClubs,
            &cards.fourOfClubs,
            &cards.fiveOfClubs,
            &cards.sixOfClubs,
            &cards.tenOfDiamonds,
            &cards.jackOfSpades
    );
    Hand straightFlushTenHigh = createHand(
            &cards.twoOfClubs,
            &cards.threeOfClubs,
            &cards.sixOfClubs,
            &cards.sevenOfClubs,
            &cards.eightOfClubs,
            &cards.nineOfClubs,
            &cards.tenOfClubs
    );
    Hand straight_flush3 = createHand(
            &cards.twoOfClubs,
            &cards.threeOfClubs,
            &cards.fourOfClubs,
            &cards.fiveOfClubs,
            &cards.sixOfClubs,
            &cards.sevenOfClubs,
            &cards.jackOfClubs
    );
    Hand royalFlushClubs = createHand(
            &cards.tenOfClubs,
            &cards.jackOfClubs,
            &cards.queenOfClubs,
            &cards.kingOfClubs,
            &cards.aceOfClubs,
            &cards.tenOfDiamonds,
            &cards.jackOfSpades
    );
    Hand royalFlushDiamonds = createHand(
            &cards.tenOfDiamonds,
            &cards.jackOfDiamonds,
            &cards.queenOfDiamonds,
            &cards.kingOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.tenOfClubs,
            &cards.jackOfSpades
    );
};

#endif //POKERX_TESTHANDS_H
