//
// Created by CiaranWelsh on 19/12/2019.
//

#include <Evaluator.h>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "gtest/gtest.h"

using namespace eval;

class EvaluatorTests : public ::testing::Test {
protected:
    eval::Hand createHand(Card hc1, Card hc2, Card flop1, Card flop2, Card flop3, Card turn, Card river) {
        HoleCards hc(hc1, hc2);
        CommunityCards cc(flop1, flop2, flop3, turn, river);
        eval::Hand hand(hc, cc);
        return hand;
    };

//    void SetUp() override {}
    Card twoOfClubs = Card(2, "C");
    Card threeOfClubs = Card(3, "C");
    Card fourOfClubs = Card(4, "C");
    Card fiveOfClubs = Card(5, "C");
    Card sixOfClubs = Card(6, "C");
    Card sevenOfClubs = Card(7, "C");
    Card eightOfClubs = Card(8, "C");
    Card nineOfClubs = Card(9, "C");
    Card tenOfClubs = Card(10, "C");
    Card jackOfClubs = Card(11, "C");
    Card queenOfClubs = Card(12, "C");
    Card kingOfClubs = Card(13, "C");
    Card aceOfClubs = Card(14, "C");

    Card twoOfSpades = Card(2, "S");
    Card threeOfSpades = Card(3, "S");
    Card fourOfSpades = Card(4, "S");
    Card fiveOfSpades = Card(5, "S");
    Card sixOfSpades = Card(6, "S");
    Card sevenOfSpades = Card(7, "S");
    Card eightOfSpades = Card(8, "S");
    Card nineOfSpades = Card(9, "S");
    Card tenOfSpades = Card(10, "S");
    Card jackOfSpades = Card(11, "S");
    Card queenOfSpades = Card(12, "S");
    Card kingOfSpades = Card(13, "S");
    Card aceOfSpades = Card(14, "S");

    Card twoOfHearts = Card(2, "H");
    Card threeOfHearts = Card(3, "H");
    Card fourOfHearts = Card(4, "H");
    Card fiveOfHearts = Card(5, "H");
    Card sixOfHearts = Card(6, "H");
    Card sevenOfHearts = Card(7, "H");
    Card eightOfHearts = Card(8, "H");
    Card nineOfHearts = Card(9, "H");
    Card tenOfHearts = Card(10, "H");
    Card jackOfHearts = Card(11, "H");
    Card queenOfHearts = Card(12, "H");
    Card kingOfHearts = Card(13, "H");
    Card aceOfHearts = Card(14, "H");

    Card twoOfDiamonds = Card(2, "D");
    Card threeOfDiamonds = Card(3, "D");
    Card fourOfDiamonds = Card(4, "D");
    Card fiveOfDiamonds = Card(5, "D");
    Card sixOfDiamonds = Card(6, "D");
    Card sevenOfDiamonds = Card(7, "D");
    Card eightOfDiamonds = Card(8, "D");
    Card nineOfDiamonds = Card(9, "D");
    Card tenOfDiamonds = Card(10, "D");
    Card jackOfDiamonds = Card(11, "D");
    Card queenOfDiamonds = Card(12, "D");
    Card kingOfDiamonds = Card(13, "D");
    Card aceOfDiamonds = Card(14, "D");

    eval::Hand highCard1 = createHand(
            twoOfClubs,
            fourOfDiamonds,
            sixOfHearts,
            sevenOfClubs,
            tenOfDiamonds,
            aceOfClubs,
            eightOfClubs
    );
};

TEST_F(EvaluatorTests, t1){
    Evaluator evaluator;
    evaluator.evaluate(highCard1);

}























