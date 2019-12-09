//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

//class HandTestFixture : testing::Test{
//public:
//    ranks = {1..13};
//};


TEST(DeckTests, TestLen) {
    Deck deck = Deck();
    int actual = deck.len();
    int expected = 52;
    ASSERT_EQ(expected, actual);
}

TEST(DeckTests, BuildDeck) {
    Deck deck = Deck();
    cout << deck << endl;
}

TEST(DeckTests, TestOstream) {
    Deck deck = Deck();
    stringstream expected;
    expected
            << "[Card(2S), Card(2H), Card(2D), Card(2H), Card(3S), Card(3H), Card(3D), Card(3H), Card(4S), Card(4H), Card(4D), Card(4H), Card(5S), Card(5H), Card(5D), Card(5H), Card(6S), Card(6H), Card(6D), Card(6H), Card(7S), Card(7H), Card(7D), Card(7H), Card(8S), Card(8H), Card(8D), Card(8H), Card(9S), Card(9H), Card(9D), Card(9H), Card(10S), Card(10H), Card(10D), Card(10H), Card(11S), Card(11H), Card(11D), Card(11H), Card(12S), Card(12H), Card(12D), Card(12H), Card(13S), Card(13H), Card(13D), Card(13H), Card(14S), Card(14H), Card(14D), Card(14H)]";
    stringstream actual;
    actual << deck;
    ASSERT_EQ(expected.str(), actual.str());
}

TEST(DeckTests, TestShuffle) {
    Deck deck = Deck();
    deck.shuffle();
    stringstream expected;
    expected << "[Card(2S), Card(2H), Card(2D), Card(2H), Card(3S), "
                "Card(3H), Card(3D), Card(3H), Card(4S), Card(4H), "
                "Card(4D), Card(4H), Card(5S), Card(5H), Card(5D), "
                "Card(5H), Card(6S), Card(6H), Card(6D), Card(6H), "
                "Card(7S), Card(7H), Card(7D), Card(7H), Card(8S), "
                "Card(8H), Card(8D), Card(8H), Card(9S), Card(9H), "
                "Card(9D), Card(9H), Card(10S), Card(10H), Card(10D),"
                " Card(10H), Card(11S), Card(11H), Card(11D), Card(11H),"
                " Card(12S), Card(12H), Card(12D), Card(12H), Card(13S),"
                " Card(13H), Card(13D), Card(13H), Card(14S), Card(14H),"
                " Card(14D), Card(14H)]";
    stringstream actual;
    actual << deck;
    ASSERT_NE(expected.str(), actual.str());
}


TEST(DeckTests, TestPop) {
    Deck deck = Deck();
    Card card = deck.pop();
    stringstream expected;
    expected << "[Card(2H), Card(2D), Card(2H), Card(3S), "
                "Card(3H), Card(3D), Card(3H), Card(4S), "
                "Card(4H), Card(4D), Card(4H), Card(5S), "
                "Card(5H), Card(5D), Card(5H), Card(6S),"
                " Card(6H), Card(6D), Card(6H), Card(7S), "
                "Card(7H), Card(7D), Card(7H), Card(8S), "
                "Card(8H), Card(8D), Card(8H), Card(9S), "
                "Card(9H), Card(9D), Card(9H), Card(10S),"
                " Card(10H), Card(10D), Card(10H), Card(11S),"
                " Card(11H), Card(11D), Card(11H), Card(12S),"
                " Card(12H), Card(12D), Card(12H), Card(13S),"
                " Card(13H), Card(13D), Card(13H), Card(14S),"
                " Card(14H), Card(14D), Card(14H)]";
    stringstream actual;
    actual << deck;
    ASSERT_EQ(expected.str(), actual.str());
    Card expectedCard = Card(2, 'S');
    bool ans = card == expectedCard;
    ASSERT_TRUE(ans);
}
















