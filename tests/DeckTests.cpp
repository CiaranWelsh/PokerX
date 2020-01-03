//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "cards/Card.h"
#include "eval/Hand.h"
#include "cards/Deck.h"


TEST(DeckTests, TestLen) {
    Deck deck;
    int actual = deck.size();
    int expected = 52;
    ASSERT_EQ(expected, actual);
}


//TEST(DeckTests, TestOstream) {
//    Deck deck;
//    stringstream expected;
//    expected
//            << "[Card(2S), Card(2H), Card(2D), Card(2C), Card(3S), Card(3H), Card(3D), Card(3C),"
//               " Card(4S), Card(4H), Card(4D), Card(4C), Card(5S), Card(5H), Card(5D), Card(5C), "
//               "Card(6S), Card(6H), Card(6D), Card(6C), Card(7S), Card(7H), Card(7D), Card(7C), "
//               "Card(8S), Card(8H), Card(8D), Card(8C), Card(9S), Card(9H), Card(9D), Card(9C), "
//               "Card(10S), Card(10H), Card(10D), Card(10C), Card(11S), Card(11H), Card(11D), Card(11C), "
//               "Card(12S), Card(12H), Card(12D), Card(12C), Card(13S), Card(13H), Card(13D), Card(13C), "
//               "Card(14S), Card(14H), Card(14D), Card(14C)]";
//    stringstream actual;
//    actual << deck;
//    ASSERT_EQ(expected.str(), actual.str());
//}

TEST(DeckTests, TestShuffle) {
    Deck deck;
    deck.shuffle();

    stringstream expected;
    expected << "[Card(2S), Card(2H), Card(2D), Card(2C), Card(3S), Card(3H), Card(3D), Card(3C),"
                " Card(4S), Card(4H), Card(4D), Card(4C), Card(5S), Card(5H), Card(5D), Card(5C), "
                "Card(6S), Card(6H), Card(6D), Card(6C), Card(7S), Card(7H), Card(7D), Card(7C), "
                "Card(8S), Card(8H), Card(8D), Card(8C), Card(9S), Card(9H), Card(9D), Card(9C), "
                "Card(10S), Card(10H), Card(10D), Card(10C), Card(11S), Card(11H), Card(11D), Card(11C), "
                "Card(12S), Card(12H), Card(12D), Card(12C), Card(13S), Card(13H), Card(13D), Card(13C), "
                "Card(14S), Card(14H), Card(14D), Card(14C)]";
    stringstream actual;
    actual << deck;
    ASSERT_NE(expected.str(), actual.str());
}

//TEST(DeckTests, TestPop) {
//    Deck deck;
//    deck.sort();
//    Card card = deck.pop();
//    stringstream expected;
//
//    expected << "[Card(2C), Card(2H), Card(2D),"
//                " Card(3S), Card(3H), Card(3D),"
//                " Card(3C), Card(4H), Card(4D),"
//                " Card(4S), Card(4C), Card(5C),"
//                " Card(5D), Card(5S), Card(5H),"
//                " Card(6S), Card(6D), Card(6C),"
//                " Card(6H), Card(7H), Card(7S),"
//                " Card(7C), Card(7D), Card(8D),"
//                " Card(8S), Card(8C), Card(8H),"
//                " Card(9C), Card(9D), Card(9H),"
//                " Card(9S), Card(10H), Card(10C), "
//                "Card(10S), Card(10D), Card(11D), "
//                "Card(11H), Card(11S), Card(11C), "
//                "Card(12H), Card(12S), Card(12C), "
//                "Card(12D), Card(13H), Card(13D), "
//                "Card(13S), Card(13C), Card(14S), "
//                "Card(14D), Card(14H), Card(14C)]";
//    stringstream actual;
//    actual << deck;
//    ASSERT_EQ(expected.str(), actual.str());
//    Card expectedCard(2, "S");
//    bool ans = card == expectedCard;
//    ASSERT_TRUE(ans);
//}

TEST(DeckTests, IteratorTest) {
    Deck deck;
    std::vector<Card> cardVector;
    for (const Card &card : deck) {
        cardVector.push_back(card);
    }
    int expected = 52;
    int actual = cardVector.size();
    ASSERT_EQ(expected, actual);
}

TEST(DeckTests, GetOperatorTests) {
    Deck deck;
    deck.sort(); //unshuffle
    Card actual = deck[4]; // 5th element
    Card expected = Card(3, "S");
    ASSERT_TRUE(expected.rank == 3);
}
















