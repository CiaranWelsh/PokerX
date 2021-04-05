/**
 * Integration tests for hand evaluator
 */
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/HandEvaluator.old.h"
#include "PokerX/engine/Deck.h"
#include "PokerX/engine/Card.h"


using namespace pokerx;

class HandTests : public ::testing::Test {
protected:
    HandTests() = default;

    static HighCard createHand(
            ICardPtr  hc1,
            ICardPtr  hc2,
            ICardPtr  flop1,
            ICardPtr  flop2,
            ICardPtr  flop3,
            ICardPtr  turn,
            ICardPtr  river
    ) {
        HoleCards hc(hc1, hc2);
        CommunityCards cc(flop1, flop2, flop3, turn, river);
        HighCard hand(hc, cc);
        return hand;
    };

    static void checkBest5(HighCard &hand, const std::string &expected) {
        cout << "Checking HighCard.old: " << hand << endl;
        const std::shared_ptr<HighCard> &x = hand.evaluate();
        cout << "hand has been checked" << endl;
        ostringstream actual;
        CardCollection best5 = x->best5();
        best5.sort();
        actual << best5;
//        cout << "Actual: " << actual.str() << endl;
        ASSERT_EQ(expected, actual.str());
    }

    template<class ExpectedHand>
    static void checkIsA(HighCard &hand) {
        cout << "Checking isa(): " << hand << endl;
        const std::shared_ptr<HighCard> &x = hand.evaluate();
        ExpectedHand expected(&hand);
        bool actual = expected.isa();
        ASSERT_TRUE(actual);

    }

    static void checkWinnerHand(HighCard hand1, HighCard hand2, HandType expected_winner) {
        std::vector<HandPtr> hvec;
        hvec.push_back(make_shared<HighCard>(hand1));
        hvec.push_back(make_shared<HighCard>(hand2));
        Evaluator evaluator;
        std::map<int, HandType> x = evaluator.evaluate(hvec);
        std::vector<HandType> values = Evaluator::getValuesOfMap(x);
        std::vector<HandType> expected = {expected_winner};
        ASSERT_EQ(expected, values);
    }

    static void checkWinnerPosition(HighCard hand1, HighCard hand2, int position) {
        std::vector<HandPtr> hvec;
        hvec.push_back(make_shared<HighCard>(hand1));
        hvec.push_back(make_shared<HighCard>(hand2));
        Evaluator evaluator;
        std::map<int, HandType> x = evaluator.evaluate(hvec);
        std::vector<int> values = Evaluator::getKeysOfMap(x);
        std::vector<int> expected = {position};
        ASSERT_EQ(expected, values);
    }

    static void checkSplitPot(HighCard hand1, HighCard hand2) {
        std::vector<HandPtr> hvec;
        hvec.push_back(make_shared<HighCard>(hand1));
        hvec.push_back(make_shared<HighCard>(hand2));
        Evaluator evaluator;
        std::map<int, HandType> x = evaluator.evaluate(hvec);
        ASSERT_EQ(2, x.size());
    }

    void checkSpecificConfiguration(CommunityCards communityCards, std::vector<HoleCards> holeCardsVec) {
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
        for (int i = 0; i < holeCardsVec.size(); i++) {
            ostringstream name;
            name << "player" << i;
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

    HighCard highCard1 = createHand(
            &sevenOfClubs,
            &fourOfDiamonds,
            &tenOfDiamonds,
            &sixOfHearts,
            &twoOfClubs,
            &aceOfClubs,
            &eightOfClubs
    );
    HighCard highCard2 = createHand(
            &twoOfClubs,
            &fourOfSpades,
            &nineOfDiamonds,
            &tenOfDiamonds,
            &eightOfClubs,
            &kingOfHearts,
            &aceOfHearts
    );
    HighCard pair1 = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &sixOfHearts,
            &sevenOfClubs,
            &tenOfDiamonds,
            &aceOfClubs,
            &eightOfClubs
    );
    HighCard pair2 = createHand(
            &twoOfClubs,
            &fourOfDiamonds,
            &sixOfHearts,
            &sevenOfClubs,
            &tenOfDiamonds,
            &tenOfClubs,
            &eightOfClubs
    );
    HighCard two_pair1 = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &sixOfHearts,
            &sixOfClubs,
            &tenOfDiamonds,
            &aceOfClubs,
            &eightOfClubs
    );
    HighCard two_pair2 = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &sixOfHearts,
            &sixOfClubs,
            &tenOfDiamonds,
            &tenOfClubs,
            &eightOfClubs
    );
    HighCard two_pair3 = createHand(
            &sixOfHearts,
            &sixOfClubs,
            &tenOfDiamonds,
            &tenOfClubs,
            &eightOfClubs,
            &twoOfClubs,
            &twoOfDiamonds
    );
    HighCard two_pair4 = createHand(
            &aceOfDiamonds,
            &eightOfDiamonds,
            &queenOfClubs,
            &aceOfClubs,
            &queenOfDiamonds,
            &eightOfClubs,
            &twoOfDiamonds
    );
    HighCard two_pair5 = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &fourOfDiamonds,
            &fourOfClubs,
            &queenOfDiamonds,
            &aceOfDiamonds,
            &kingOfClubs
    );
    HighCard two_pair6 = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &fourOfDiamonds,
            &fourOfClubs,
            &queenOfDiamonds,
            &queenOfClubs,
            &kingOfClubs
    );
    HighCard three_of_a_kind1 = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &twoOfHearts,
            &fourOfClubs,
            &queenOfDiamonds,
            &aceOfDiamonds,
            &kingOfClubs
    );
    HighCard full_house1 = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &twoOfHearts,
            &queenOfClubs,
            &queenOfDiamonds,
            &aceOfDiamonds,
            &kingOfClubs
    );
    HighCard full_house2 = createHand(
            &eightOfClubs,
            &eightOfDiamonds,
            &eightOfHearts,
            &queenOfClubs,
            &queenOfDiamonds,
            &aceOfDiamonds,
            &kingOfClubs
    );
    HighCard four_of_a_kind = createHand(
            &twoOfClubs,
            &twoOfDiamonds,
            &twoOfHearts,
            &twoOfSpades,
            &queenOfDiamonds,
            &aceOfDiamonds,
            &kingOfClubs
    );
    HighCard straight2to6 = createHand(
            &twoOfClubs,
            &threeOfDiamonds,
            &fourOfHearts,
            &fiveOfSpades,
            &sixOfDiamonds,
            &aceOfDiamonds,
            &kingOfClubs
    );
    HighCard straight_low_ace = createHand(
            &aceOfClubs,
            &twoOfClubs,
            &threeOfDiamonds,
            &fourOfHearts,
            &fiveOfSpades,
            &kingOfClubs,
            &queenOfClubs
    );
    HighCard straight2to6_2 = createHand(
            &twoOfClubs,
            &threeOfDiamonds,
            &fourOfHearts,
            &fiveOfSpades,
            &sixOfClubs,
            &queenOfClubs,
            &kingOfClubs
    );
    HighCard straight4 = createHand(
            &twoOfClubs,
            &fiveOfClubs,
            &sixOfHearts,
            &sevenOfClubs,
            &eightOfDiamonds,
            &nineOfClubs,
            &kingOfHearts
    );
    HighCard straight5 = createHand(
            &twoOfClubs,
            &fiveOfClubs,
            &sevenOfClubs,
            &eightOfDiamonds,
            &nineOfClubs,
            &tenOfDiamonds,
            &jackOfDiamonds
    );
    HighCard flush1 = createHand(
            &twoOfClubs,
            &fiveOfClubs,
            &sevenOfClubs,
            &eightOfDiamonds,
            &nineOfClubs,
            &tenOfDiamonds,
            &kingOfClubs
    );
    HighCard straight_flush1 = createHand(
            &twoOfClubs,
            &threeOfClubs,
            &fourOfClubs,
            &fiveOfClubs,
            &sixOfClubs,
            &tenOfDiamonds,
            &jackOfSpades
    );
    HighCard straight_flush2 = createHand(
            &twoOfClubs,
            &threeOfClubs,
            &fourOfClubs,
            &fiveOfClubs,
            &sixOfClubs,
            &tenOfDiamonds,
            &jackOfClubs
    );
    HighCard straight_flush3 = createHand(
            &twoOfClubs,
            &threeOfClubs,
            &fourOfClubs,
            &fiveOfClubs,
            &sixOfClubs,
            &sevenOfClubs,
            &jackOfClubs
    );
    HighCard royal_flush1 = createHand(
            &tenOfClubs,
            &jackOfClubs,
            &queenOfClubs,
            &kingOfClubs,
            &aceOfClubs,
            &tenOfDiamonds,
            &jackOfSpades
    );
};


TEST_F(HandTests, TestInstantiation2) {
    CardCollection cards;
    cards.add(jackOfSpades);
    cards.add(aceOfClubs);
    cards.add(threeOfDiamonds);
    cards.add(fourOfDiamonds);
    cards.add(sixOfHearts);
    cards.add(sevenOfClubs);
    cards.add(nineOfClubs);
    HighCard hand(cards);
    ASSERT_TRUE(hand.type == Hand_);
}

//TEST_F(HandTests, TestInstantiation3) {
//    CommunityCards communityCards;
//    communityCards.add(jackOfSpades);
//    communityCards.add(jackOfClubs);
//    communityCards.add(threeOfDiamonds);
//    communityCards.add(fourOfDiamonds);
//    communityCards.add(sixOfHearts);
//    HoleCards holeCards;
//    holeCards.add(sevenOfClubs);
//    holeCards.add(nineOfClubs);
//    Pair hand(holeCards, communityCards);
//    ASSERT_TRUE(hand.type == Pair_);
//}
//
//TEST_F(HandTests, TestInstantiationStraight) {
//    Straight straight(straight2to6);
//    ASSERT_TRUE(straight.type == Straight_);
//}
//
//TEST_F(HandTests, TestInstantiationRoyalFlush) {
//    RoyalFlush royalFlush(royalFlushClubs);
//    ASSERT_TRUE(royalFlush.type == RoyalFlush_);
//}
//
//TEST_F(HandTests, TestInstantiation4) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    Pair hand(cards);
//    ASSERT_TRUE(hand.type == Pair_);
//}
//
//TEST_F(HandTests, TestCopyConstructor1) {
//    HighCard.old hand(highCardAceTen);
//    HighCard.old hand2 = hand;
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Hand_);
//}
//
//TEST_F(HandTests, TestCopyConstructor2) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    Pair hand(cards);
//    Pair hand2 = hand;
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Pair_);
//}
//
//TEST_F(HandTests, TestCopyConstructorHandRef1) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    HighCard.old hand(cards);
//    HighCard.old hand2(hand);
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Hand_);
//}
//
//TEST_F(HandTests, TestCopyInstantiatePairFromAnotherPair) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    Pair hand(cards);
//    Pair hand2(hand);
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Pair_);
//}
//
//TEST_F(HandTests, TestInstantiateFromHandPointerPair) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    HighCard.old hand(cards);
//    Pair hand2(&hand);
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Pair_);
//}
//
//
//TEST_F(HandTests, TestMoveConstructorHand) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    HighCard.old hand(cards);
//    HighCard.old hand2(std::move(hand));
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Hand_);
//}
//
//TEST_F(HandTests, TestMoveConstructorPair) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    Pair hand(cards);
//    Pair hand2(std::move(hand));
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Pair_);
//}
//
//TEST_F(HandTests, TestMoveAssignmentHand) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    HighCard.old hand(cards);
//    HighCard.old hand2 = std::move(hand);
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Hand_);
//}
//
//TEST_F(HandTests, TestMoveAssignmentPair) {
//    CardCollection cards;
//    cards.add(jackOfSpades);
//    cards.add(aceOfClubs);
//    cards.add(threeOfDiamonds);
//    cards.add(fourOfDiamonds);
//    cards.add(sixOfHearts);
//    cards.add(sevenOfClubs);
//    cards.add(nineOfClubs);
//    Pair hand(cards);
//    Pair hand2 = std::move(hand);
//    cout << hand2.type << endl;
//    ASSERT_TRUE(hand2.type == Pair_);
//}
//
//
//TEST_F(HandTests, TestSumRanks) {
//    ASSERT_EQ(49, pair2sAceHigh.sumBest5Ranks());
//}
//
//TEST_F(HandTests, TestSumRanks2) {
//    ASSERT_EQ(15, straightAto5.sumBest5Ranks());
//}
//
//TEST_F(HandTests, InstantiateStraightWithPair) {
//    Straight straight(pair2sAceHigh);
//    ASSERT_FALSE(straight.isa());
//}
//
//
//TEST_F(HandTests, TestGreaterThan1) {
//    ThreeOfAKind toak(&threeOfAKindThrees);
//    FourOfAKind fourOfAKind(&fourOfAKindTwos);
//    bool actual = fourOfAKind > toak;
////    ASSERT_TRUE(actual);
//}
//
//TEST_F(HandTests, TestGreaterThan2) {
//    ThreeOfAKind toak(&threeOfAKindThrees);
//    Pair pair(&pair2sAceHigh);
//    bool actual = pair > toak;
//    ASSERT_FALSE(actual);
//}
//
//TEST_F(HandTests, TestGreaterThanSameTypePair1) {
//    Pair paira(&pair2sAceHigh);
//    Pair pairb(&pair10s8high);
//    bool actual = paira > pairb;
//    ASSERT_FALSE(actual);
//}
//
//TEST_F(HandTests, TestGreaterThanSameTypePair2) {
//    Pair paira(&pair2sAceHigh);
//    Pair pairb(&pair10s8high);
//    cout << paira << endl;
//    cout << pairb << endl;
//    bool actual = paira < pairb;
//    ASSERT_TRUE(actual);
//}
//
//TEST_F(HandTests, TestGreaterThanSameTypeFullHouse1) {
//    FullHouse handa(&fullHouseTwosfullOfThrees);
//    FullHouse handb(&fullHouseEightsFullOfQueens);
//    bool actual = handa < handb;
//    ASSERT_TRUE(actual);
//}
//
//TEST_F(HandTests, TestGreaterThanSameTypeStraight1) {
//    Straight handa(&straight2to6);
//    Straight handb(&straight5to9);
//    bool actual = handb > handa;
//    ASSERT_TRUE(actual);
//}
//
//
//TEST_F(HandTests, TestGreaterThanSameTypeStraight2) {
//    Straight handa(&straight2to6);
//    Straight handb(&straightAto5);
//    bool actual = handa > handb;
//    ASSERT_TRUE(actual);
//}
//
//
//TEST_F(HandTests, TestThatYouCanCopyAPair) {
//    Pair pair(&pair10s8high);
//    Pair another_pair = pair;
//    ASSERT_EQ(another_pair.getHandType(), Pair_);
//}
//
//TEST_F(HandTests, TestThatYouCanMakeAStraightFlush) {
//    StraightFlush straightFlush(&straightFlushSixHigh);
//    ASSERT_EQ(straightFlush.getHandType(), StraightFlush_);
//}
//
//TEST_F(HandTests, TestThatYouCanMakeAStraightFlushFromEvaluate) {
//    std::shared_ptr<HighCard.old> hand = straightFlushSixHigh.evaluate();
//    ASSERT_EQ(hand->getHandType(), StraightFlush_);
//}
//
//TEST_F(HandTests, TestThatYouCanCopyAHand) {
//    HighCard.old hand = pair2sAceHigh;
//    ASSERT_EQ(hand.type, Hand_);
//}
//
//TEST_F(HandTests, TestEquality) {
//    HighCard.old royal_flush_again = createHand(
//            tenOfClubs,
//            jackOfClubs,
//            queenOfClubs,
//            kingOfClubs,
//            aceOfClubs,
//            tenOfDiamonds,
//            jackOfSpades
//    );
//    ASSERT_TRUE(royalFlushClubs == royal_flush_again);
//}
//
//
//TEST_F(HandTests, TestXOfAKind) {
//    ASSERT_TRUE(pair2sAceHigh.xOfAKindIsA(2));
//}
//
//TEST_F(HandTests, TestXOfAKind3) {
//    ASSERT_TRUE(threeOfAKindThrees.xOfAKindIsA(3));
//}
//
//TEST_F(HandTests, TestXOfAKind4) {
//    ASSERT_TRUE(fourOfAKindTwos.xOfAKindIsA(4));
//}
//
//
//TEST_F(HandTests, TestHighCard1) {
//    std::string expected = "[Card(6H), Card(7C), Card(8C), Card(10D), Card(14C)]";
//    checkBest5(highCardAceTen, expected);
//}
//
//TEST_F(HandTests, TestHighCard2) {
//    std::string expected = "[Card(8C), Card(9D), Card(10D), Card(13H), Card(14H)]";
//    checkBest5(highCardAceKing, expected);
//}
//
//TEST_F(HandTests, TestPair) {
//    std::string expected = "[Card(2C), Card(2D), Card(8C), Card(10D), Card(14C)]";
//    checkBest5(pair2sAceHigh, expected);
//}
//
//TEST_F(HandTests, TestTwoPairIsA2) {
//    checkIsA<TwoPair>(two_pair1);
//}
//
//TEST_F(HandTests, TestTwoPairIsA3) {
//    cout << two_pair2 << endl;
//    checkIsA<TwoPair>(two_pair2);
//}
//
////TEST_F(HandTests, TestTwoPair) {
////    std::string expected = "[Card(2C), Card(2D), Card(6H), Card(6C), Card(14C)]";
////    checkBest5(two_pair1, expected);
////}
//
//TEST_F(HandTests, TestTwoPair2) {
//    HighCard.old hand = two_pair2;
//    std::string expected = "[Card(6H), Card(6C), Card(8C), Card(10D), Card(10C)]";
//    checkBest5(two_pair2, expected);
//}
//
//TEST_F(HandTests, TestTwoPair22) {
//
//    HighCard.old hand = two_pair2;
//    cout << two_pair2 << endl;
//    const std::shared_ptr<HighCard.old> &x = two_pair2.evaluate();
//    cout << x->type << endl;
//    cout << x->best5() << endl;
////    ostringstream actual;
////    CardCollection best5 = x->best5();
////    cout << best5 << endl;
////    best5.sort();
////    actual << best5;
////    ASSERT_EQ(expected, actual.str());
//}
//
//
////TEST_F(HandTests, TestTwoPair3) {
////    std::string expected = "[Card(6H), Card(6C), Card(8C), Card(10D), Card(10C)]";
////    checkBest5(TwoPairSixAndTens, expected);
////}
//
//TEST_F(HandTests, TestTwoPair4) {
//    HighCard.old hand = TwoPairAceAndQueens;
//    std::string expected = "[Card(8C), Card(12C), Card(12D), Card(14D), Card(14C)]";
//    checkBest5(TwoPairAceAndQueens, expected);
//}
//
//TEST_F(HandTests, TestTwoPair5) {
//    std::string expected = "[Card(2C), Card(2D), Card(4D), Card(4C), Card(14D)]";
//    checkBest5(two_pair5, expected);
//}
//
//TEST_F(HandTests, TestTwoPair6) {
//    std::string expected = "[Card(4D), Card(4C), Card(12D), Card(12C), Card(13C)]";
//    checkBest5(TwoPairFourAndQueens, expected);
//}
//
//TEST_F(HandTests, TestThreeOfAKing1) {
//    std::string expected = "[Card(2C), Card(2D), Card(2H), Card(13C), Card(14D)]";
//    checkBest5(threeOfAKindThrees, expected);
//}
//
//
//TEST_F(HandTests, TestFullHouse1IsA) {
//    checkIsA<FullHouse>(fullHouseTwosfullOfThrees);
//}
//
//TEST_F(HandTests, TestFullHouseBest5) {
//    std::string expected = "[Card(2C), Card(2D), Card(2H), Card(12C), Card(12D)]";
//    checkBest5(fullHouseTwosfullOfThrees, expected);
//}
//
//
//TEST_F(HandTests, TestFourOfAKindIsA) {
//    checkIsA<FourOfAKind>(fourOfAKindTwos);
//}
//
//TEST_F(HandTests, TestFourOfAKindBest5) {
//    std::string expected = "[Card(2C), Card(2D), Card(2H), Card(2S), Card(14D)]";
//    checkBest5(fourOfAKindTwos, expected);
//}
//
//TEST_F(HandTests, TestStraight1IsA) {
//    checkIsA<Straight>(straight2to6);
//}
//
//
//TEST_F(HandTests, TestStraight1Best5) {
//    std::string expected = "[Card(2C), Card(3D), Card(4H), Card(5S), Card(6D)]";
//    checkBest5(straight2to6, expected);
//}
//
//
//TEST_F(HandTests, TestStraight2IsA) {
//    Straight straight(&straightAto5);
//    ASSERT_TRUE(straight.isa());
//}
//
//TEST_F(HandTests, TestStraight2Best5) {
//    std::string expected = "[Card(2C), Card(3D), Card(4H), Card(5S), Card(14C)]";
//    checkBest5(straightAto5, expected);
//}
//
//
//TEST_F(HandTests, TestStraight3IsA) {
//    Straight straight(&straight2to6_2);
//    ASSERT_TRUE(straight.isa());
//}
//
//TEST_F(HandTests, TestStraight3Best5) {
//    std::string expected = "[Card(2C), Card(3D), Card(4H), Card(5S), Card(6C)]";
//    checkBest5(straight2to6_2, expected);
//}
//
//TEST_F(HandTests, TestStraight4IsA) {
//    Straight straight(&straight5to9);
//    ASSERT_TRUE(straight.isa());
//}
//
//
//TEST_F(HandTests, TestStraight4best5) {
//    std::string expected = "[Card(5C), Card(6H), Card(7C), Card(8D), Card(9C)]";
//    checkBest5(straight5to9, expected);
//}
//
//TEST_F(HandTests, TestStraight5IsA) {
//    Straight straight(&straight7toJ);
//    ASSERT_TRUE(straight.isa());
//}
//
//TEST_F(HandTests, TestStraight5best5) {
//    std::string expected = "[Card(7C), Card(8D), Card(9C), Card(10D), Card(11D)]";
//    checkBest5(straight7toJ, expected);
//}
//
//TEST_F(HandTests, TestFlushIsA) {
//    Flush flush(&flushKingHigh);
//    ASSERT_TRUE(flush.isa());
//}
//
//TEST_F(HandTests, TestFlushBest5) {
//    std::string expected = "[Card(2C), Card(5C), Card(7C), Card(9C), Card(13C)]";
//    checkBest5(flushKingHigh, expected);
//}
//
//
//TEST_F(HandTests, TestStraightFlushIsA) {
//    StraightFlush straight_flush(&straightFlushSixHigh);
//    ASSERT_TRUE(straight_flush.isa());
//}
//
//TEST_F(HandTests, TestStraightFlushBest5) {
//    std::string expected = "[Card(2C), Card(3C), Card(4C), Card(5C), Card(6C)]";
//    checkBest5(straightFlushSixHigh, expected);
//}
//
//TEST_F(HandTests, TestStraightFlushIsA2) {
//    StraightFlush straight_flush(&straightFlushTenHigh);
//    ASSERT_TRUE(straight_flush.isa());
//}
//
//TEST_F(HandTests, TestStraightFlushBest52) {
//    std::string expected = "[Card(2C), Card(3C), Card(4C), Card(5C), Card(6C)]";
//    checkBest5(straightFlushTenHigh, expected);
//}
//
//TEST_F(HandTests, TestStraightFlushBest53) {
//    std::string expected = "[Card(3C), Card(4C), Card(5C), Card(6C), Card(7C)]";
//    checkBest5(straight_flush3, expected);
//}
//
//TEST_F(HandTests, TestRoyalFlushIsA2) {
//    RoyalFlush royalFlush(&royalFlushClubs);
//    ASSERT_TRUE(royalFlush.isa());
//}
//
//TEST_F(HandTests, TestRoyalFlushBest52) {
//    std::string expected = "[Card(10C), Card(11C), Card(12C), Card(13C), Card(14C)]";
//    checkBest5(royalFlushClubs, expected);
//}
//
//
//TEST_F(HandTests, ComparingHandsTests1) {
//    Pair pair(pair2sAceHigh);
//    TwoPair twoPair(two_pair2);
//    bool ans = pair2sAceHigh > twoPair;
//    ASSERT_FALSE(ans);
//}
//
//TEST_F(HandTests, ComparingHandsTests2) {
//    Pair pair(pair2sAceHigh);
//    TwoPair twoPair(two_pair2);
//    bool ans = pair < twoPair;
//    ASSERT_TRUE(ans);
//}
//
//TEST_F(HandTests, ComparingHandsTests3) {
//    Straight straight1(straight2to6);
//    TwoPair twoPair(two_pair2);
//    bool ans = straight1 > twoPair;
//    ASSERT_TRUE(ans);
//}
//
//TEST_F(HandTests, ComparingHandsTests4) {
//    Straight straight(straight2to6);
//    TwoPair twoPair(two_pair2);
//    bool ans = straight < twoPair;
//    ASSERT_FALSE(ans);
//}
//
//
//TEST_F(HandTests, ComparingHandsTests7) {
//    Pair paira(pair2sAceHigh);
//    Pair pairb(pair10s8high);
//    bool ans = paira > pairb;
//    ASSERT_FALSE(ans);
//}
//
//
//TEST_F(HandTests, TestGetMaxOfMap) {
//    std::map<int, HandType> map;
//    map[0] = Pair_;
//    map[1] = TwoPair_;
//    map[2] = ThreeOfAKind_;
//    auto out = Evaluator::getMaxValueOfAMap(map);
//    ASSERT_EQ(ThreeOfAKind_, out.first);
//    ASSERT_EQ(2, out.second[0]);
//}
//
//TEST_F(HandTests, TestGetMaxOfMap2) {
//    std::map<int, int> map;
//    map[0] = 1;
//    map[1] = 3;
//    map[2] = 2;
//    auto out = Evaluator::getMaxValueOfAMap(map);
//    ASSERT_EQ(3, out.first);
//    ASSERT_EQ(1, out.second[0]);
//}
//
//TEST_F(HandTests, TestGetKeys) {
//    std::map<int, int> x;
//    x[0] = 1;
//    x[1] = 2;
//    std::vector<int> keys = Evaluator::getKeysOfMap(x);
//    std::vector<int> expected = {0, 1};
//    ASSERT_EQ(expected, keys);
//}
//
//TEST_F(HandTests, TestGetValues) {
//    std::map<int, int> x;
//    x[0] = 1;
//    x[1] = 2;
//    std::vector<int> values = Evaluator::getValuesOfMap(x);
//    std::vector<int> expected = {1, 2};
//    ASSERT_EQ(expected, values);
//}
//
//
//TEST_F(HandTests, TestSplitPot) {
//    checkSplitPot(pair2sAceHigh, pair2sAceHigh);
//}
//
//
///*
// * What if the overloading functions operator> and operator<
// * were to return different values, depending on whether
// * the hand being compared again also has the same hand type.
// */
//TEST_F(HandTests, TestSetValuePair) {
//    Pair pair(&pair2sAceHigh);
//    ASSERT_EQ(2, pair.getValue());
//}
//
//TEST_F(HandTests, TestSetValueTwoPair) {
//    TwoPair twopair(&two_pair1);
//    ASSERT_EQ(6, twopair.getValue());
//}
//
//TEST_F(HandTests, TestSetValueTOAK) {
//    ThreeOfAKind toak(&threeOfAKindThrees);
//    ASSERT_EQ(2, toak.getValue());
//}
//
//TEST_F(HandTests, TestSetValueStraight) {
//    Straight straight(&straight2to6_2);
//    ASSERT_EQ(6, straight.getValue());
//}
//
//TEST_F(HandTests, TestSetValueFlush) {
//    Flush flush(&flushKingHigh);
//    ASSERT_EQ(13, flush.getValue());
//}
//
//TEST_F(HandTests, TestSetValueFullHouse) {
//    FullHouse fullHouse(&fullHouseTwosfullOfThrees);
//    ASSERT_EQ(2, fullHouse.getValue());
//}
//
//TEST_F(HandTests, TestSetValueFOAK) {
//    FourOfAKind fourOfAKind(&fourOfAKindTwos);
//    ASSERT_EQ(2, fourOfAKind.getValue());
//}
//
//TEST_F(HandTests, TestSetValueStraightFlush) {
//    StraightFlush straightFlush(&straightFlushSixHigh);
//    ASSERT_EQ(6, straightFlush.getValue());
//}
//
//
//TEST_F(HandTests, TestHandGetLArgestRank) {
//    ASSERT_EQ(14, straight2to6.getLargestRank());
//}
//
//
//TEST_F(HandTests, Evaluate2PairVsTwoPairPosition) {
//    checkWinnerPosition(pair2sAceHigh, two_pair1, 1);
//}
//
//TEST_F(HandTests, Evaluate2PairVsTwoPairHandValue) {
//    checkWinnerHand(pair2sAceHigh, two_pair1, TwoPair_);
//}
//
//TEST_F(HandTests, Evaluate2StraightVsFlushHand) {
//    checkWinnerHand(flushKingHigh, straight2to6, Flush_);
//}
//
//TEST_F(HandTests, Evaluate2StraightFlushVsStraight) {
//    checkWinnerPosition(flushKingHigh, straight2to6, 0);
//}
//
//TEST_F(HandTests, Evaluate2StraighFlushtVsThreeOfAKindHand) {
//    checkWinnerHand(threeOfAKindThrees, straightFlushSixHigh, StraightFlush_);
//}
//
//TEST_F(HandTests, Evaluate2StraightVsThreeOfAKindPosition) {
//    checkWinnerPosition(threeOfAKindThrees, straightFlushSixHigh, 1);
//}
//
//TEST_F(HandTests, EvaluateTheHigherOfTwoPairsPosition) {
//    checkWinnerPosition(pair2sAceHigh, pair10s8high, 1);
//}
//
//
//TEST_F(HandTests, TestEvaluateAHand) {
//    std::vector<Card> player0_vec = {Card(3, "C"), Card(5, "C"), Card(8, "H"), Card(10, "C"), Card(11, "S"),
//                                     Card(12, "S"), Card(14, "D")};
//    CardCollection player0(player0_vec);
//    HighCard.old hand0(player0);
//    hand0.evaluate();
//
//    std::vector<Card> player1_vec = {Card(3, "C"), Card(5, "C"), Card(7, "C"), Card(7, "S"), Card(10, "C"),
//                                     Card(11, "S"), Card(14, "D")};
//    CardCollection player1(player1_vec);
//    HighCard.old hand1(player1);
//
//    std::vector<Card> player2_vec = {Card(3, "C"), Card(5, "S"), Card(5, "C"), Card(9, "S"), Card(10, "C"),
//                                     Card(11, "S"), Card(14, "D")};
//    CardCollection player2(player2_vec);
//    HighCard.old hand2(player2);
//
//    std::vector<Card> player3_vec = {Card(3, "C"), Card(5, "C"), Card(7, "H"), Card(10, "D"), Card(10, "C"),
//                                     Card(11, "S"), Card(14, "D")};
//    CardCollection player3(player3_vec);
//    HighCard.old hand3(player3);
//
//    std::vector<Card> player4_vec = {Card(3, "C"), Card(5, "C"), Card(10, "C"), Card(11, "S"), Card(12, "D"),
//                                     Card(14, "H"), Card(14, "D")};
//    CardCollection player4(player4_vec);
//    HighCard.old hand4(player4);
//
//    std::vector<Card> player5_vec = {Card(3, "C"), Card(5, "C"), Card(10, "H"), Card(10, "C"), Card(11, "S"),
//                                     Card(12, "C"), Card(14, "D")};
//    CardCollection player5(player5_vec);
//    HighCard.old hand5(player5);
//
//    std::vector<Card> player6_vec = {Card(3, "C"), Card(5, "C"), Card(6, "D"), Card(10, "C"), Card(11, "S"),
//                                     Card(13, "S"), Card(14, "D")};
//    CardCollection player6(player6_vec);
//    HighCard.old hand6(player6);
//
//    std::vector<Card> player7_vec = {Card(3, "C"), Card(4, "S"), Card(5, "C"), Card(10, "C"), Card(11, "S"),
//                                     Card(14, "C"), Card(14, "D")};
//    CardCollection player7(player7_vec);
//    HighCard.old hand7(player7);
//
//    std::vector<Card> player8_vec = {Card(3, "C"), Card(5, "H"), Card(5, "C"), Card(10, "S"), Card(10, "C"),
//                                     Card(11, "S"), Card(14, "D")};
//    CardCollection player8(player8_vec);
//    HighCard.old hand8(player8);
//
//    std::vector<std::shared_ptr<HighCard.old>> hands = {
//            std::make_shared<HighCard.old>(hand0),
//            std::make_shared<HighCard.old>(hand1),
//            std::make_shared<HighCard.old>(hand2),
//            std::make_shared<HighCard.old>(hand3),
//            std::make_shared<HighCard.old>(hand4),
//            std::make_shared<HighCard.old>(hand5),
//            std::make_shared<HighCard.old>(hand6),
//            std::make_shared<HighCard.old>(hand7),
//            std::make_shared<HighCard.old>(hand8)};
//
//    Evaluator evaluator;
//    auto answer = evaluator.evaluate(hands);
//    ASSERT_TRUE(answer[8] == HandType::TwoPair_);
//
//}
//
//
//
//







