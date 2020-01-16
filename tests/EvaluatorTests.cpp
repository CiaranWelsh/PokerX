//
// Created by CiaranWelsh on 19/12/2019.
//

#include <eval/Evaluator.h>
#include "cards/Deck.h"
#include "eval/Hand.h"
#include "cards/Card.h"
#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "game/Table.h"

using namespace eval;

class EvaluatorTests : public ::testing::Test {
protected:
    EvaluatorTests() = default;

    static eval::Hand createHand(Card hc1, Card hc2, Card flop1, Card flop2, Card flop3, Card turn, Card river) {
        HoleCards hc(hc1, hc2);
        CommunityCards cc(flop1, flop2, flop3, turn, river);
        eval::Hand hand(hc, cc);
        return hand;
    };

    static void checkBest5(Hand &hand, const std::string &expected) {
        cout << "Checking Hand: " << hand << endl;
        const std::shared_ptr<Hand> &x = hand.evaluate();
        cout << "hand has been checked" << endl;
        ostringstream actual;
        CardCollection best5 = x->best5();
        best5.sort();
        actual << best5;
//        cout << "Actual: " << actual.str() << endl;
        ASSERT_EQ(expected, actual.str());
    }

    template<class ExpectedHand>
    static void checkIsA(Hand &hand) {
        cout << "Checking isa(): " << hand << endl;
        const std::shared_ptr<Hand> &x = hand.evaluate();
        ExpectedHand expected(&hand);
        bool actual = expected.isa();
        ASSERT_TRUE(actual);

    }

    static void checkWinnerHand(Hand hand1, Hand hand2, HandType expected_winner) {
        std::vector<HandPtr> hvec;
        hvec.push_back(make_shared<Hand>(hand1));
        hvec.push_back(make_shared<Hand>(hand2));
        eval::Evaluator evaluator;
        std::map<int, HandType> x = evaluator.evaluate(hvec);
        std::vector<HandType> values = Evaluator::getValuesOfMap(x);
        std::vector<HandType> expected = {expected_winner};
        ASSERT_EQ(expected, values);
    }

    static void checkWinnerPosition(Hand hand1, Hand hand2, int position) {
        std::vector<HandPtr> hvec;
        hvec.push_back(make_shared<Hand>(hand1));
        hvec.push_back(make_shared<Hand>(hand2));
        eval::Evaluator evaluator;
        std::map<int, HandType> x = evaluator.evaluate(hvec);
        std::vector<int> values = Evaluator::getKeysOfMap(x);
        std::vector<int> expected = {position};
        ASSERT_EQ(expected, values);
    }

    static void checkSplitPot(Hand hand1, Hand hand2) {
        std::vector<HandPtr> hvec;
        hvec.push_back(make_shared<Hand>(hand1));
        hvec.push_back(make_shared<Hand>(hand2));
        eval::Evaluator evaluator;
        std::map<int, HandType> x = evaluator.evaluate(hvec);
        ASSERT_EQ(2, x.size());
    }

    void checkSpecificConfiguration(CommunityCards communityCards, std::vector<HoleCards> holeCardsVec){
//        Player player0("player0", holeCards0);
//        Player player1("player1", holeCards0);
//        Player player2("player2", holeCards0);
//        Player player3("player3", holeCards0);
//        Player player4("player4", holeCards0);
//        Player player5("player5", holeCards0);
//        Player player6("player6", holeCards0);
//        Player player7("player7", holeCards0);
//        Player player8("player8", holeCards0);
        std::vector<std::shared_ptr<Player>> playerPtrVec;
        for (int i =0; i< holeCardsVec.size(); i++){
            ostringstream name;
            name << "player"<<i;
            Player player(name.str(), holeCardsVec[i]);
            playerPtrVec.push_back(std::make_shared<Player>(player));
            name.flush();
        }
//        game::Players players(playerPtrVec);
//        game::Table table(players);
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
    Hand highCard2 = createHand(
            twoOfClubs,
            fourOfSpades,
            nineOfDiamonds,
            tenOfDiamonds,
            eightOfClubs,
            kingOfHearts,
            aceOfHearts
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
    Hand pair2 = createHand(
            twoOfClubs,
            fourOfDiamonds,
            sixOfHearts,
            sevenOfClubs,
            tenOfDiamonds,
            tenOfClubs,
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
    Hand full_house2 = createHand(
            eightOfClubs,
            eightOfDiamonds,
            eightOfHearts,
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
    Hand straight2to6 = createHand(
            twoOfClubs,
            threeOfDiamonds,
            fourOfHearts,
            fiveOfSpades,
            sixOfDiamonds,
            aceOfDiamonds,
            kingOfClubs
    );
    Hand straight_low_ace = createHand(
            aceOfClubs,
            twoOfClubs,
            threeOfDiamonds,
            fourOfHearts,
            fiveOfSpades,
            kingOfClubs,
            queenOfClubs
    );
    Hand straight2to6_2 = createHand(
            twoOfClubs,
            threeOfDiamonds,
            fourOfHearts,
            fiveOfSpades,
            sixOfClubs,
            queenOfClubs,
            kingOfClubs
    );
    Hand straight4 = createHand(
            twoOfClubs,
            fiveOfClubs,
            sixOfHearts,
            sevenOfClubs,
            eightOfDiamonds,
            nineOfClubs,
            kingOfHearts
    );
    Hand straight5 = createHand(
            twoOfClubs,
            fiveOfClubs,
            sevenOfClubs,
            eightOfDiamonds,
            nineOfClubs,
            tenOfDiamonds,
            jackOfDiamonds
    );
    Hand flush1 = createHand(
            twoOfClubs,
            fiveOfClubs,
            sevenOfClubs,
            eightOfDiamonds,
            nineOfClubs,
            tenOfDiamonds,
            kingOfClubs
    );
    Hand straight_flush1 = createHand(
            twoOfClubs,
            threeOfClubs,
            fourOfClubs,
            fiveOfClubs,
            sixOfClubs,
            tenOfDiamonds,
            jackOfSpades
    );
    Hand straight_flush2 = createHand(
            twoOfClubs,
            threeOfClubs,
            fourOfClubs,
            fiveOfClubs,
            sixOfClubs,
            tenOfDiamonds,
            jackOfClubs
    );
    Hand straight_flush3 = createHand(
            twoOfClubs,
            threeOfClubs,
            fourOfClubs,
            fiveOfClubs,
            sixOfClubs,
            sevenOfClubs,
            jackOfClubs
    );
    Hand royal_flush1 = createHand(
            tenOfClubs,
            jackOfClubs,
            queenOfClubs,
            kingOfClubs,
            aceOfClubs,
            tenOfDiamonds,
            jackOfSpades
    );
};

TEST_F(EvaluatorTests, TestInstantiation1) {
    CommunityCards communityCards;
    communityCards.add(jackOfSpades);
    communityCards.add(aceOfClubs);
    communityCards.add(threeOfDiamonds);
    communityCards.add(fourOfDiamonds);
    communityCards.add(sixOfHearts);
    HoleCards holeCards;
    holeCards.add(sevenOfClubs);
    holeCards.add(nineOfClubs);
    Hand hand(holeCards, communityCards);
    ASSERT_TRUE(hand.type == Hand_);
}

TEST_F(EvaluatorTests, TestInstantiation2) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Hand hand(cards);
    ASSERT_TRUE(hand.type == Hand_);
}

TEST_F(EvaluatorTests, TestInstantiation3) {
    CommunityCards communityCards;
    communityCards.add(jackOfSpades);
    communityCards.add(jackOfClubs);
    communityCards.add(threeOfDiamonds);
    communityCards.add(fourOfDiamonds);
    communityCards.add(sixOfHearts);
    HoleCards holeCards;
    holeCards.add(sevenOfClubs);
    holeCards.add(nineOfClubs);
    Pair hand(holeCards, communityCards);
    ASSERT_TRUE(hand.type == Pair_);
}

TEST_F(EvaluatorTests, TestInstantiationStraight) {
    Straight straight(straight2to6);
    ASSERT_TRUE(straight.type == Straight_);
}

TEST_F(EvaluatorTests, TestInstantiationRoyalFlush) {
    RoyalFlush royalFlush(royal_flush1);
    ASSERT_TRUE(royalFlush.type == RoyalFlush_);
}

TEST_F(EvaluatorTests, TestInstantiation4) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Pair hand(cards);
    ASSERT_TRUE(hand.type == Pair_);
}

TEST_F(EvaluatorTests, TestCopyConstructor1) {
    Hand hand(highCard1);
    Hand hand2 = hand;
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Hand_);
}

TEST_F(EvaluatorTests, TestCopyConstructor2) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Pair hand(cards);
    Pair hand2 = hand;
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Pair_);
}

TEST_F(EvaluatorTests, TestCopyConstructorHandRef1) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Hand hand(cards);
    Hand hand2(hand);
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Hand_);
}

TEST_F(EvaluatorTests, TestCopyInstantiatePairFromAnotherPair) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Pair hand(cards);
    Pair hand2(hand);
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Pair_);
}

TEST_F(EvaluatorTests, TestInstantiateFromHandPointerPair) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Hand hand(cards);
    Pair hand2(&hand);
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Pair_);
}


TEST_F(EvaluatorTests, TestMoveConstructorHand) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Hand hand(cards);
    Hand hand2(std::move(hand));
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Hand_);
}

TEST_F(EvaluatorTests, TestMoveConstructorPair) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Pair hand(cards);
    Pair hand2(std::move(hand));
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Pair_);
}

TEST_F(EvaluatorTests, TestMoveAssignmentHand) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Hand hand(cards);
    Hand hand2 = std::move(hand);
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Hand_);
}

TEST_F(EvaluatorTests, TestMoveAssignmentPair) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    Pair hand(cards);
    Pair hand2 = std::move(hand);
    cout << hand2.type << endl;
    ASSERT_TRUE(hand2.type == Pair_);
}


TEST_F(EvaluatorTests, TestSumRanks) {
    ASSERT_EQ(49, pair1.sumBest5Ranks());
}

TEST_F(EvaluatorTests, TestSumRanks2) {
    ASSERT_EQ(15, straight_low_ace.sumBest5Ranks());
}

TEST_F(EvaluatorTests, InstantiateStraightWithPair) {
    Straight straight(pair1);
    ASSERT_FALSE(straight.isa());
}


TEST_F(EvaluatorTests, TestGreaterThan1) {
    ThreeOfAKind toak(&three_of_a_kind1);
    FourOfAKind fourOfAKind(&four_of_a_kind);
    bool actual = fourOfAKind > toak;
//    ASSERT_TRUE(actual);
}

TEST_F(EvaluatorTests, TestGreaterThan2) {
    ThreeOfAKind toak(&three_of_a_kind1);
    Pair pair(&pair1);
    bool actual = pair > toak;
    ASSERT_FALSE(actual);
}

TEST_F(EvaluatorTests, TestGreaterThanSameTypePair1) {
    Pair paira(&pair1);
    Pair pairb(&pair2);
    bool actual = paira > pairb;
    ASSERT_FALSE(actual);
}

TEST_F(EvaluatorTests, TestGreaterThanSameTypePair2) {
    Pair paira(&pair1);
    Pair pairb(&pair2);
    cout << paira << endl;
    cout << pairb << endl;
    bool actual = paira < pairb;
    ASSERT_TRUE(actual);
}

TEST_F(EvaluatorTests, TestGreaterThanSameTypeFullHouse1) {
    FullHouse handa(&full_house1);
    FullHouse handb(&full_house2);
    bool actual = handa < handb;
    ASSERT_TRUE(actual);
}

TEST_F(EvaluatorTests, TestGreaterThanSameTypeStraight1) {
    Straight handa(&straight2to6);
    Straight handb(&straight4);
    bool actual = handb > handa;
    ASSERT_TRUE(actual);
}


TEST_F(EvaluatorTests, TestGreaterThanSameTypeStraight2) {
    Straight handa(&straight2to6);
    Straight handb(&straight_low_ace);
    bool actual = handa > handb;
    ASSERT_TRUE(actual);
}


TEST_F(EvaluatorTests, TestThatYouCanCopyAPair) {
    Pair pair(&pair2);
    Pair another_pair = pair;
    ASSERT_EQ(another_pair.getHandType(), Pair_);
}

TEST_F(EvaluatorTests, TestThatYouCanMakeAStraightFlush) {
    StraightFlush straightFlush(&straight_flush1);
    ASSERT_EQ(straightFlush.getHandType(), StraightFlush_);
}

TEST_F(EvaluatorTests, TestThatYouCanMakeAStraightFlushFromEvaluate) {
    std::shared_ptr<Hand> hand = straight_flush1.evaluate();
    ASSERT_EQ(hand->getHandType(), StraightFlush_);
}

TEST_F(EvaluatorTests, TestThatYouCanCopyAHand) {
    Hand hand = pair1;
    ASSERT_EQ(hand.type, Hand_);
}

TEST_F(EvaluatorTests, TestEquality) {
    Hand royal_flush_again = createHand(
            tenOfClubs,
            jackOfClubs,
            queenOfClubs,
            kingOfClubs,
            aceOfClubs,
            tenOfDiamonds,
            jackOfSpades
    );
    ASSERT_TRUE(royal_flush1 == royal_flush_again);
}


TEST_F(EvaluatorTests, TestXOfAKind) {
    ASSERT_TRUE(pair1.xOfAKindIsA(2));
}

TEST_F(EvaluatorTests, TestXOfAKind3) {
    ASSERT_TRUE(three_of_a_kind1.xOfAKindIsA(3));
}

TEST_F(EvaluatorTests, TestXOfAKind4) {
    ASSERT_TRUE(four_of_a_kind.xOfAKindIsA(4));
}


TEST_F(EvaluatorTests, TestHighCard1) {
    std::string expected = "[Card(6H), Card(7C), Card(8C), Card(10D), Card(14C)]";
    checkBest5(highCard1, expected);
}

TEST_F(EvaluatorTests, TestHighCard2) {
    std::string expected = "[Card(8C), Card(9D), Card(10D), Card(13H), Card(14H)]";
    checkBest5(highCard2, expected);
}

TEST_F(EvaluatorTests, TestPair) {
    std::string expected = "[Card(2C), Card(2D), Card(8C), Card(10D), Card(14C)]";
    checkBest5(pair1, expected);
}

TEST_F(EvaluatorTests, TestTwoPairIsA2) {
    checkIsA<TwoPair>(two_pair1);
}

TEST_F(EvaluatorTests, TestTwoPairIsA3) {
    cout << two_pair2 << endl;
    checkIsA<TwoPair>(two_pair2);
}

//TEST_F(EvaluatorTests, TestTwoPair) {
//    std::string expected = "[Card(2C), Card(2D), Card(6H), Card(6C), Card(14C)]";
//    checkBest5(two_pair1, expected);
//}

TEST_F(EvaluatorTests, TestTwoPair2) {
    Hand hand = two_pair2;
    std::string expected = "[Card(6H), Card(6C), Card(8C), Card(10D), Card(10C)]";
    checkBest5(two_pair2, expected);
}

TEST_F(EvaluatorTests, TestTwoPair22) {

    Hand hand = two_pair2;
    cout << two_pair2 << endl;
    const std::shared_ptr<Hand> &x = two_pair2.evaluate();
    cout << x->type << endl;
    cout << x->best5() << endl;
//    ostringstream actual;
//    CardCollection best5 = x->best5();
//    cout << best5 << endl;
//    best5.sort();
//    actual << best5;
//    ASSERT_EQ(expected, actual.str());
}


//TEST_F(EvaluatorTests, TestTwoPair3) {
//    std::string expected = "[Card(6H), Card(6C), Card(8C), Card(10D), Card(10C)]";
//    checkBest5(two_pair3, expected);
//}

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
    checkIsA<FullHouse>(full_house1);
}

TEST_F(EvaluatorTests, TestFullHouseBest5) {
    std::string expected = "[Card(2C), Card(2D), Card(2H), Card(12C), Card(12D)]";
    checkBest5(full_house1, expected);
}


TEST_F(EvaluatorTests, TestFourOfAKindIsA) {
    checkIsA<FourOfAKind>(four_of_a_kind);
}

TEST_F(EvaluatorTests, TestFourOfAKindBest5) {
    std::string expected = "[Card(2C), Card(2D), Card(2H), Card(2S), Card(14D)]";
    checkBest5(four_of_a_kind, expected);
}

TEST_F(EvaluatorTests, TestStraight1IsA) {
    checkIsA<Straight>(straight2to6);
}


TEST_F(EvaluatorTests, TestStraight1Best5) {
    std::string expected = "[Card(2C), Card(3D), Card(4H), Card(5S), Card(6D)]";
    checkBest5(straight2to6, expected);
}


TEST_F(EvaluatorTests, TestStraight2IsA) {
    Straight straight(&straight_low_ace);
    ASSERT_TRUE(straight.isa());
}

TEST_F(EvaluatorTests, TestStraight2Best5) {
    std::string expected = "[Card(2C), Card(3D), Card(4H), Card(5S), Card(14C)]";
    checkBest5(straight_low_ace, expected);
}


TEST_F(EvaluatorTests, TestStraight3IsA) {
    Straight straight(&straight2to6_2);
    ASSERT_TRUE(straight.isa());
}

TEST_F(EvaluatorTests, TestStraight3Best5) {
    std::string expected = "[Card(2C), Card(3D), Card(4H), Card(5S), Card(6C)]";
    checkBest5(straight2to6_2, expected);
}

TEST_F(EvaluatorTests, TestStraight4IsA) {
    Straight straight(&straight4);
    ASSERT_TRUE(straight.isa());
}


TEST_F(EvaluatorTests, TestStraight4best5) {
    std::string expected = "[Card(5C), Card(6H), Card(7C), Card(8D), Card(9C)]";
    checkBest5(straight4, expected);
}

TEST_F(EvaluatorTests, TestStraight5IsA) {
    Straight straight(&straight5);
    ASSERT_TRUE(straight.isa());
}

TEST_F(EvaluatorTests, TestStraight5best5) {
    std::string expected = "[Card(7C), Card(8D), Card(9C), Card(10D), Card(11D)]";
    checkBest5(straight5, expected);
}

TEST_F(EvaluatorTests, TestFlushIsA) {
    Flush flush(&flush1);
    ASSERT_TRUE(flush.isa());
}

TEST_F(EvaluatorTests, TestFlushBest5) {
    std::string expected = "[Card(2C), Card(5C), Card(7C), Card(9C), Card(13C)]";
    checkBest5(flush1, expected);
}


TEST_F(EvaluatorTests, TestStraightFlushIsA) {
    StraightFlush straight_flush(&straight_flush1);
    ASSERT_TRUE(straight_flush.isa());
}

TEST_F(EvaluatorTests, TestStraightFlushBest5) {
    std::string expected = "[Card(2C), Card(3C), Card(4C), Card(5C), Card(6C)]";
    checkBest5(straight_flush1, expected);
}

TEST_F(EvaluatorTests, TestStraightFlushIsA2) {
    StraightFlush straight_flush(&straight_flush2);
    ASSERT_TRUE(straight_flush.isa());
}

TEST_F(EvaluatorTests, TestStraightFlushBest52) {
    std::string expected = "[Card(2C), Card(3C), Card(4C), Card(5C), Card(6C)]";
    checkBest5(straight_flush2, expected);
}

TEST_F(EvaluatorTests, TestStraightFlushBest53) {
    std::string expected = "[Card(3C), Card(4C), Card(5C), Card(6C), Card(7C)]";
    checkBest5(straight_flush3, expected);
}

TEST_F(EvaluatorTests, TestRoyalFlushIsA2) {
    RoyalFlush royalFlush(&royal_flush1);
    ASSERT_TRUE(royalFlush.isa());
}

TEST_F(EvaluatorTests, TestRoyalFlushBest52) {
    std::string expected = "[Card(10C), Card(11C), Card(12C), Card(13C), Card(14C)]";
    checkBest5(royal_flush1, expected);
}


TEST_F(EvaluatorTests, ComparingHandsTests1) {
    Pair pair(pair1);
    TwoPair twoPair(two_pair2);
    bool ans = pair1 > twoPair;
    ASSERT_FALSE(ans);
}

TEST_F(EvaluatorTests, ComparingHandsTests2) {
    Pair pair(pair1);
    TwoPair twoPair(two_pair2);
    bool ans = pair < twoPair;
    ASSERT_TRUE(ans);
}

TEST_F(EvaluatorTests, ComparingHandsTests3) {
    Straight straight1(straight2to6);
    TwoPair twoPair(two_pair2);
    bool ans = straight1 > twoPair;
    ASSERT_TRUE(ans);
}

TEST_F(EvaluatorTests, ComparingHandsTests4) {
    Straight straight(straight2to6);
    TwoPair twoPair(two_pair2);
    bool ans = straight < twoPair;
    ASSERT_FALSE(ans);
}


TEST_F(EvaluatorTests, ComparingHandsTests7) {
    Pair paira(pair1);
    Pair pairb(pair2);
    bool ans = paira > pairb;
    ASSERT_FALSE(ans);
}


TEST_F(EvaluatorTests, TestGetMaxOfMap) {
    std::map<int, HandType> map;
    map[0] = Pair_;
    map[1] = TwoPair_;
    map[2] = ThreeOfAKind_;
    auto out = Evaluator::getMaxValueOfAMap(map);
    ASSERT_EQ(ThreeOfAKind_, out.first);
    ASSERT_EQ(2, out.second[0]);
}

TEST_F(EvaluatorTests, TestGetMaxOfMap2) {
    std::map<int, int> map;
    map[0] = 1;
    map[1] = 3;
    map[2] = 2;
    auto out = Evaluator::getMaxValueOfAMap(map);
    ASSERT_EQ(3, out.first);
    ASSERT_EQ(1, out.second[0]);
}

TEST_F(EvaluatorTests, TestGetKeys) {
    std::map<int, int> x;
    x[0] = 1;
    x[1] = 2;
    std::vector<int> keys = Evaluator::getKeysOfMap(x);
    std::vector<int> expected = {0, 1};
    ASSERT_EQ(expected, keys);
}

TEST_F(EvaluatorTests, TestGetValues) {
    std::map<int, int> x;
    x[0] = 1;
    x[1] = 2;
    std::vector<int> values = Evaluator::getValuesOfMap(x);
    std::vector<int> expected = {1, 2};
    ASSERT_EQ(expected, values);
}


TEST_F(EvaluatorTests, TestSplitPot) {
    checkSplitPot(pair1, pair1);
}


/*
 * What if the overloading functions operator> and operator<
 * were to return different values, depending on whether
 * the hand being compared again also has the same hand type.
 */
TEST_F(EvaluatorTests, TestSetValuePair) {
    Pair pair(&pair1);
    ASSERT_EQ(2, pair.getValue());
}

TEST_F(EvaluatorTests, TestSetValueTwoPair) {
    TwoPair twopair(&two_pair1);
    ASSERT_EQ(6, twopair.getValue());
}

TEST_F(EvaluatorTests, TestSetValueTOAK) {
    ThreeOfAKind toak(&three_of_a_kind1);
    ASSERT_EQ(2, toak.getValue());
}

TEST_F(EvaluatorTests, TestSetValueStraight) {
    Straight straight(&straight2to6_2);
    ASSERT_EQ(6, straight.getValue());
}

TEST_F(EvaluatorTests, TestSetValueFlush) {
    Flush flush(&flush1);
    ASSERT_EQ(13, flush.getValue());
}

TEST_F(EvaluatorTests, TestSetValueFullHouse) {
    FullHouse fullHouse(&full_house1);
    ASSERT_EQ(2, fullHouse.getValue());
}

TEST_F(EvaluatorTests, TestSetValueFOAK) {
    FourOfAKind fourOfAKind(&four_of_a_kind);
    ASSERT_EQ(2, fourOfAKind.getValue());
}

TEST_F(EvaluatorTests, TestSetValueStraightFlush) {
    StraightFlush straightFlush(&straight_flush1);
    ASSERT_EQ(6, straightFlush.getValue());
}


TEST_F(EvaluatorTests, TestHandGetLArgestRank) {
    ASSERT_EQ(14, straight2to6.getLargestRank());
}


TEST_F(EvaluatorTests, Evaluate2PairVsTwoPairPosition) {
    checkWinnerPosition(pair1, two_pair1, 1);
}

TEST_F(EvaluatorTests, Evaluate2PairVsTwoPairHandValue) {
    checkWinnerHand(pair1, two_pair1, TwoPair_);
}

TEST_F(EvaluatorTests, Evaluate2StraightVsFlushHand) {
    checkWinnerHand(flush1, straight2to6, Flush_);
}

TEST_F(EvaluatorTests, Evaluate2StraightFlushVsStraight) {
    checkWinnerPosition(flush1, straight2to6, 0);
}

TEST_F(EvaluatorTests, Evaluate2StraighFlushtVsThreeOfAKindHand) {
    checkWinnerHand(three_of_a_kind1, straight_flush1, StraightFlush_);
}

TEST_F(EvaluatorTests, Evaluate2StraightVsThreeOfAKindPosition) {
    checkWinnerPosition(three_of_a_kind1, straight_flush1, 1);
}

TEST_F(EvaluatorTests, EvaluateTheHigherOfTwoPairsPosition) {
    checkWinnerPosition(pair1, pair2, 1);
}


TEST_F(EvaluatorTests, TestEvaluateAHand) {
    std::vector<Card> player0_vec = {Card(3, "C"), Card(5, "C"), Card(8, "H"), Card(10, "C"), Card(11, "S"),
                                     Card(12, "S"), Card(14, "D")};
    CardCollection player0(player0_vec);
    eval::Hand hand0(player0);
    hand0.evaluate();

    std::vector<Card> player1_vec = {Card(3, "C"), Card(5, "C"), Card(7, "C"), Card(7, "S"), Card(10, "C"),
                                     Card(11, "S"), Card(14, "D")};
    CardCollection player1(player1_vec);
    eval::Hand hand1(player1);

    std::vector<Card> player2_vec = {Card(3, "C"), Card(5, "S"), Card(5, "C"), Card(9, "S"), Card(10, "C"),
                                     Card(11, "S"), Card(14, "D")};
    CardCollection player2(player2_vec);
    eval::Hand hand2(player2);

    std::vector<Card> player3_vec = {Card(3, "C"), Card(5, "C"), Card(7, "H"), Card(10, "D"), Card(10, "C"),
                                     Card(11, "S"), Card(14, "D")};
    CardCollection player3(player3_vec);
    eval::Hand hand3(player3);

    std::vector<Card> player4_vec = {Card(3, "C"), Card(5, "C"), Card(10, "C"), Card(11, "S"), Card(12, "D"),
                                     Card(14, "H"), Card(14, "D")};
    CardCollection player4(player4_vec);
    eval::Hand hand4(player4);

    std::vector<Card> player5_vec = {Card(3, "C"), Card(5, "C"), Card(10, "H"), Card(10, "C"), Card(11, "S"),
                                     Card(12, "C"), Card(14, "D")};
    CardCollection player5(player5_vec);
    eval::Hand hand5(player5);

    std::vector<Card> player6_vec = {Card(3, "C"), Card(5, "C"), Card(6, "D"), Card(10, "C"), Card(11, "S"),
                                     Card(13, "S"), Card(14, "D")};
    CardCollection player6(player6_vec);
    eval::Hand hand6(player6);

    std::vector<Card> player7_vec = {Card(3, "C"), Card(4, "S"), Card(5, "C"), Card(10, "C"), Card(11, "S"),
                                     Card(14, "C"), Card(14, "D")};
    CardCollection player7(player7_vec);
    eval::Hand hand7(player7);

    std::vector<Card> player8_vec = {Card(3, "C"), Card(5, "H"), Card(5, "C"), Card(10, "S"), Card(10, "C"),
                                     Card(11, "S"), Card(14, "D")};
    CardCollection player8(player8_vec);
    eval::Hand hand8(player8);

    std::vector<std::shared_ptr<eval::Hand>> hands = {
            std::make_shared<eval::Hand>(hand0),
            std::make_shared<eval::Hand>(hand1),
            std::make_shared<eval::Hand>(hand2),
            std::make_shared<eval::Hand>(hand3),
            std::make_shared<eval::Hand>(hand4),
            std::make_shared<eval::Hand>(hand5),
            std::make_shared<eval::Hand>(hand6),
            std::make_shared<eval::Hand>(hand7),
            std::make_shared<eval::Hand>(hand8)};

    eval::Evaluator evaluator;
    auto answer = evaluator.evaluate(hands);
    ASSERT_TRUE(answer[8] == eval::HandType::TwoPair_);

}











