#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Mockups/MockCard.h"

#include "PokerX/engine/GameVariables.h"

using namespace pokerx;

class GameVariablesTests : public ::testing::Test {
public:
    MockCards mockCards;

    GameVariablesTests() = default;
};


TEST_F(GameVariablesTests, CheckDeckHas52Cards) {
    GameVariables variables;
    const Deck &deck = variables.getDeck();
    ASSERT_EQ(52, deck.size());

}

TEST_F(GameVariablesTests, CheckWeCanInjectCards) {

    GameVariables variables;

    Card c1(4, "H");
    Card c2(7, "C");
    Card c3(6, "D");
    Card c4(11, "S");
    //Card c5(3, "C");

    std::vector<ICardPtr  > cards({&c1, &c2, &c3, &c4});//, &c5});

    variables.injectCommunityCards(cards);

//    ASSERT_EQ(4, variables.getDeck()[0]->getRank());
//    ASSERT_EQ("H", variables.getDeck()[0]->getSuit());
//
//    ASSERT_EQ(7, variables.getDeck()[1]->getRank());
//    ASSERT_EQ("C", variables.getDeck()[1]->getSuit());
//
//    ASSERT_EQ(6, variables.getDeck()[2]->getRank());
//    ASSERT_EQ("D", variables.getDeck()[2]->getSuit());
//
//    ASSERT_EQ(11, variables.getDeck()[3]->getRank());
//    ASSERT_EQ("S", variables.getDeck()[3]->getSuit());
//
//    ASSERT_EQ(3, variables.getDeck()[4]->getRank());
//    ASSERT_EQ("C", variables.getDeck()[4]->getSuit());

}


















