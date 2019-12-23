//
// Created by CiaranWelsh on 19/12/2019.
//

#include <eval/Evaluator.h>
#include "cards/Deck.h"
#include "eval/Hand.h"
#include "cards/Card.h"
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

    static void checkBest5(Hand &hand, const std::string &expected) {
        cout << "Checking Hand: " << hand << endl;
        const unique_ptr<Hand> &x = hand.evaluate();
        ostringstream actual;
        CardCollection best5 = (*x).best5(hand.getCards());
        best5.sort();
        actual << best5;
        cout << actual.str() << endl;
        ASSERT_EQ(expected, actual.str());
    }

    template<class ExpectedHand>
    static void checkIsA(Hand &hand) {
        cout << "Checking isa(): " << hand << endl;
        const unique_ptr<Hand> &x = hand.evaluate();
        ExpectedHand expected(hand);
        bool actual = expected.isa();
        ASSERT_TRUE(actual);

    }

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

    Hand highCard1 = createHand(
            sevenOfClubs,
            fourOfDiamonds,
            tenOfDiamonds,
            sixOfHearts,
            twoOfClubs,
            aceOfClubs,
            eightOfClubs
    );
    Hand pair1 = createHand(
            twoOfClubs,
            twoOfDiamonds,
            sixOfHearts,
            sevenOfClubs,
            tenOfDiamonds,
            aceOfClubs,
            eightOfClubs
    );
    Hand two_pair1 = createHand(
            twoOfClubs,
            twoOfDiamonds,
            sixOfHearts,
            sixOfClubs,
            tenOfDiamonds,
            aceOfClubs,
            eightOfClubs
    );
    Hand two_pair2 = createHand(
            twoOfClubs,
            twoOfDiamonds,
            sixOfHearts,
            sixOfClubs,
            tenOfDiamonds,
            tenOfClubs,
            eightOfClubs
    );
    Hand two_pair3 = createHand(
            sixOfHearts,
            sixOfClubs,
            tenOfDiamonds,
            tenOfClubs,
            eightOfClubs,
            twoOfClubs,
            twoOfDiamonds
    );
    Hand two_pair4 = createHand(
            aceOfDiamonds,
            eightOfDiamonds,
            queenOfClubs,
            aceOfClubs,
            queenOfDiamonds,
            eightOfClubs,
            twoOfDiamonds
    );
    Hand two_pair5 = createHand(
            twoOfClubs,
            twoOfDiamonds,
            fourOfDiamonds,
            fourOfClubs,
            queenOfDiamonds,
            aceOfDiamonds,
            kingOfClubs
    );
    Hand two_pair6 = createHand(
            twoOfClubs,
            twoOfDiamonds,
            fourOfDiamonds,
            fourOfClubs,
            queenOfDiamonds,
            queenOfClubs,
            kingOfClubs
    );
    Hand three_of_a_kind1 = createHand(
            twoOfClubs,
            twoOfDiamonds,
            twoOfHearts,
            fourOfClubs,
            queenOfDiamonds,
            aceOfDiamonds,
            kingOfClubs
    );
    Hand full_house1 = createHand(
            twoOfClubs,
            twoOfDiamonds,
            twoOfHearts,
            queenOfClubs,
            queenOfDiamonds,
            aceOfDiamonds,
            kingOfClubs
    );
    Hand four_of_a_kind = createHand(
            twoOfClubs,
            twoOfDiamonds,
            twoOfHearts,
            twoOfSpades,
            queenOfDiamonds,
            aceOfDiamonds,
            kingOfClubs
    );
};



TEST_F(EvaluatorTests, TestXOfAKind) {
    ASSERT_TRUE(pair1.xOfAKind(2));
}

TEST_F(EvaluatorTests, TestXOfAKind3) {
    ASSERT_TRUE(three_of_a_kind1.xOfAKind(3));
}

TEST_F(EvaluatorTests, TestXOfAKind4) {
    ASSERT_TRUE(four_of_a_kind.xOfAKind(4));
}


TEST_F(EvaluatorTests, TestHighCard) {
    std::string expected = "[Card(6H), Card(7C), Card(8C), Card(10D), Card(14C)]";
    checkBest5(highCard1, expected);
}

TEST_F(EvaluatorTests, TestPair) {
    std::string expected = "[Card(2C), Card(2D), Card(8C), Card(10D), Card(14C)]";
    checkBest5(pair1, expected);
}

TEST_F(EvaluatorTests, TestTwoPairIsA) {
    Hand hand = two_pair1;
    const unique_ptr<Hand> &x = hand.evaluate();
    ostringstream actual;
    actual << (*x).isa();
    ASSERT_TRUE((*x).isa());
}
TEST_F(EvaluatorTests, TestTwoPairIsA2) {
    checkIsA<TwoPair>(two_pair1);
}

TEST_F(EvaluatorTests, TestTwoPair) {
    std::string expected = "[Card(2C), Card(2D), Card(6H), Card(6C), Card(14C)]";
    checkBest5(two_pair1, expected);
}

TEST_F(EvaluatorTests, TestTwoPair2) {
    Hand hand = two_pair2;
    std::string expected = "[Card(6H), Card(6C), Card(8C), Card(10D), Card(10C)]";
    checkBest5(two_pair2, expected);
}

TEST_F(EvaluatorTests, TestTwoPair3) {
    std::string expected = "[Card(6H), Card(6C), Card(8C), Card(10D), Card(10C)]";
    checkBest5(two_pair3, expected);
}

TEST_F(EvaluatorTests, TestTwoPair4) {
    Hand hand = two_pair4;
    std::string expected = "[Card(8C), Card(12C), Card(12D), Card(14D), Card(14C)]";
    checkBest5(two_pair4, expected);
}

TEST_F(EvaluatorTests, TestTwoPair5) {
    std::string expected = "[Card(2C), Card(2D), Card(4D), Card(4C), Card(14D)]";
    checkBest5(two_pair5, expected);
}

TEST_F(EvaluatorTests, TestTwoPair6) {
    std::string expected = "[Card(4D), Card(4C), Card(12D), Card(12C), Card(13C)]";
    checkBest5(two_pair6, expected);
}

TEST_F(EvaluatorTests, TestThreeOfAKing1) {
    std::string expected = "[Card(2C), Card(2D), Card(2H), Card(13C), Card(14D)]";
    checkBest5(three_of_a_kind1, expected);
}


TEST_F(EvaluatorTests, TestFullHouse1IsA) {
    Pair pair(full_house1);
    cout << pair << endl;
    cout << pair.isa() << endl;
    checkIsA<FullHouse>(full_house1);
}

//TEST_F(EvaluatorTests, TestXOfAKindBest5) {
//    pair1.xOfAKindBest5(2);
//}































