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

    static Hand createHand(ICard* hc1, ICard* hc2, ICard* flop1, ICard* flop2, ICard* flop3, ICard* turn, ICard* river ){
        return Hand({hc1, hc2, flop1, flop2, flop3, turn, river});
    }

    Hand highCard1 = createHand(
            &cards.sevenOfClubs,
            &cards.fourOfDiamonds,
            &cards.tenOfDiamonds,
            &cards.sixOfHearts,
            &cards.twoOfClubs,
            &cards.aceOfClubs,
            &cards.eightOfClubs
    );
    Hand highCard2 = createHand(
            &cards.twoOfClubs,
            &cards.fourOfSpades,
            &cards.nineOfDiamonds,
            &cards.tenOfDiamonds,
            &cards.eightOfClubs,
            &cards.kingOfHearts,
            &cards.aceOfHearts
    );
    Hand pair1 = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.sixOfHearts,
            &cards.sevenOfClubs,
            &cards.tenOfDiamonds,
            &cards.aceOfClubs,
            &cards.eightOfClubs
    );
    Hand pair2 = createHand(
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
    Hand two_pair3 = createHand(
            &cards.sixOfHearts,
            &cards.sixOfClubs,
            &cards.tenOfDiamonds,
            &cards.tenOfClubs,
            &cards.eightOfClubs,
            &cards.twoOfClubs,
            &cards.twoOfDiamonds
    );
    Hand two_pair4 = createHand(
            &cards.aceOfDiamonds,
            &cards.eightOfDiamonds,
            &cards.queenOfClubs,
            &cards.aceOfClubs,
            &cards.queenOfDiamonds,
            &cards.eightOfClubs,
            &cards.twoOfDiamonds
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
    Hand two_pair6 = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.fourOfDiamonds,
            &cards.fourOfClubs,
            &cards.queenOfDiamonds,
            &cards.queenOfClubs,
            &cards.kingOfClubs
    );
    Hand three_of_a_kind1 = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.twoOfHearts,
            &cards.fourOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand full_house1 = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.twoOfHearts,
            &cards.queenOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand full_house2 = createHand(
            &cards.eightOfClubs,
            &cards.eightOfDiamonds,
            &cards.eightOfHearts,
            &cards.queenOfClubs,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
            &cards.kingOfClubs
    );
    Hand four_of_a_kind = createHand(
            &cards.twoOfClubs,
            &cards.twoOfDiamonds,
            &cards.twoOfHearts,
            &cards.twoOfSpades,
            &cards.queenOfDiamonds,
            &cards.aceOfDiamonds,
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

    Hand flush1 = createHand(
            &cards.twoOfClubs,
            &cards.fiveOfClubs,
            &cards.sevenOfClubs,
            &cards.eightOfDiamonds,
            &cards.nineOfClubs,
            &cards.tenOfDiamonds,
            &cards.kingOfClubs
    );
    Hand straight_flush1 = createHand(
            &cards.twoOfClubs,
            &cards.threeOfClubs,
            &cards.fourOfClubs,
            &cards.fiveOfClubs,
            &cards.sixOfClubs,
            &cards.tenOfDiamonds,
            &cards.jackOfSpades
    );
    Hand straight_flush2 = createHand(
            &cards.twoOfClubs,
            &cards.threeOfClubs,
            &cards.fourOfClubs,
            &cards.fiveOfClubs,
            &cards.sixOfClubs,
            &cards.tenOfDiamonds,
            &cards.jackOfClubs
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
    Hand royal_flush1 = createHand(
            &cards.tenOfClubs,
            &cards.jackOfClubs,
            &cards.queenOfClubs,
            &cards.kingOfClubs,
            &cards.aceOfClubs,
            &cards.tenOfDiamonds,
            &cards.jackOfSpades
    );
};

#endif //POKERX_TESTHANDS_H
