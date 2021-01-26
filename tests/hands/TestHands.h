//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_TESTHANDS_H
#define POKERX_TESTHANDS_H

#include "Mockups/MockCard.h"
#include "PokerX/engine/hands/Hand.h"

class TestHands {
public:
    MockCards mockCards;
    TestHands() = default;

    static Hand createHand(ICard* hc1, ICard* hc2, ICard* flop1, ICard* flop2, ICard* flop3, ICard* turn, ICard* river ){
        return Hand({hc1, hc2, flop1, flop2, flop3, turn, river});
    }

    Hand highCard1 = createHand(
            &mockCards.sevenOfClubs,
            &mockCards.fourOfDiamonds,
            &mockCards.tenOfDiamonds,
            &mockCards.sixOfHearts,
            &mockCards.twoOfClubs,
            &mockCards.aceOfClubs,
            &mockCards.eightOfClubs
    );
    Hand highCard2 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.fourOfSpades,
            &mockCards.nineOfDiamonds,
            &mockCards.tenOfDiamonds,
            &mockCards.eightOfClubs,
            &mockCards.kingOfHearts,
            &mockCards.aceOfHearts
    );
    Hand pair1 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.sixOfHearts,
            &mockCards.sevenOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.aceOfClubs,
            &mockCards.eightOfClubs
    );
    Hand pair2 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.fourOfDiamonds,
            &mockCards.sixOfHearts,
            &mockCards.sevenOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.tenOfClubs,
            &mockCards.eightOfClubs
    );
    Hand two_pair1 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.sixOfHearts,
            &mockCards.sixOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.aceOfClubs,
            &mockCards.eightOfClubs
    );
    Hand two_pair2 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.sixOfHearts,
            &mockCards.sixOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.tenOfClubs,
            &mockCards.eightOfClubs
    );
    Hand two_pair3 = createHand(
            &mockCards.sixOfHearts,
            &mockCards.sixOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.tenOfClubs,
            &mockCards.eightOfClubs,
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds
    );
    Hand two_pair4 = createHand(
            &mockCards.aceOfDiamonds,
            &mockCards.eightOfDiamonds,
            &mockCards.queenOfClubs,
            &mockCards.aceOfClubs,
            &mockCards.queenOfDiamonds,
            &mockCards.eightOfClubs,
            &mockCards.twoOfDiamonds
    );
    Hand two_pair5 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.fourOfDiamonds,
            &mockCards.fourOfClubs,
            &mockCards.queenOfDiamonds,
            &mockCards.aceOfDiamonds,
            &mockCards.kingOfClubs
    );
    Hand two_pair6 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.fourOfDiamonds,
            &mockCards.fourOfClubs,
            &mockCards.queenOfDiamonds,
            &mockCards.queenOfClubs,
            &mockCards.kingOfClubs
    );
    Hand three_of_a_kind1 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.twoOfHearts,
            &mockCards.fourOfClubs,
            &mockCards.queenOfDiamonds,
            &mockCards.aceOfDiamonds,
            &mockCards.kingOfClubs
    );
    Hand full_house1 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.twoOfHearts,
            &mockCards.queenOfClubs,
            &mockCards.queenOfDiamonds,
            &mockCards.aceOfDiamonds,
            &mockCards.kingOfClubs
    );
    Hand full_house2 = createHand(
            &mockCards.eightOfClubs,
            &mockCards.eightOfDiamonds,
            &mockCards.eightOfHearts,
            &mockCards.queenOfClubs,
            &mockCards.queenOfDiamonds,
            &mockCards.aceOfDiamonds,
            &mockCards.kingOfClubs
    );
    Hand four_of_a_kind = createHand(
            &mockCards.twoOfClubs,
            &mockCards.twoOfDiamonds,
            &mockCards.twoOfHearts,
            &mockCards.twoOfSpades,
            &mockCards.queenOfDiamonds,
            &mockCards.aceOfDiamonds,
            &mockCards.kingOfClubs
    );
    Hand straight2to6 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.threeOfDiamonds,
            &mockCards.fourOfHearts,
            &mockCards.fiveOfSpades,
            &mockCards.sixOfDiamonds,
            &mockCards.aceOfDiamonds,
            &mockCards.kingOfClubs
    );
    Hand straight_low_ace = createHand(
            &mockCards.aceOfClubs,
            &mockCards.twoOfClubs,
            &mockCards.threeOfDiamonds,
            &mockCards.fourOfHearts,
            &mockCards.fiveOfSpades,
            &mockCards.kingOfClubs,
            &mockCards.queenOfClubs
    );
    Hand straight2to6_2 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.threeOfDiamonds,
            &mockCards.fourOfHearts,
            &mockCards.fiveOfSpades,
            &mockCards.sixOfClubs,
            &mockCards.queenOfClubs,
            &mockCards.kingOfClubs
    );
    Hand straight4 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.fiveOfClubs,
            &mockCards.sixOfHearts,
            &mockCards.sevenOfClubs,
            &mockCards.eightOfDiamonds,
            &mockCards.nineOfClubs,
            &mockCards.kingOfHearts
    );
    Hand straight5 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.fiveOfClubs,
            &mockCards.sevenOfClubs,
            &mockCards.eightOfDiamonds,
            &mockCards.nineOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.jackOfDiamonds
    );
    Hand flush1 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.fiveOfClubs,
            &mockCards.sevenOfClubs,
            &mockCards.eightOfDiamonds,
            &mockCards.nineOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.kingOfClubs
    );
    Hand straight_flush1 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.threeOfClubs,
            &mockCards.fourOfClubs,
            &mockCards.fiveOfClubs,
            &mockCards.sixOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.jackOfSpades
    );
    Hand straight_flush2 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.threeOfClubs,
            &mockCards.fourOfClubs,
            &mockCards.fiveOfClubs,
            &mockCards.sixOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.jackOfClubs
    );
    Hand straight_flush3 = createHand(
            &mockCards.twoOfClubs,
            &mockCards.threeOfClubs,
            &mockCards.fourOfClubs,
            &mockCards.fiveOfClubs,
            &mockCards.sixOfClubs,
            &mockCards.sevenOfClubs,
            &mockCards.jackOfClubs
    );
    Hand royal_flush1 = createHand(
            &mockCards.tenOfClubs,
            &mockCards.jackOfClubs,
            &mockCards.queenOfClubs,
            &mockCards.kingOfClubs,
            &mockCards.aceOfClubs,
            &mockCards.tenOfDiamonds,
            &mockCards.jackOfSpades
    );
};

#endif //POKERX_TESTHANDS_H
