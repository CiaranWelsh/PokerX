//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

//class HandTestFixture : testing::Test{
//public:
////    ranks = {1..13};
//};


TEST(HandTests, test){
    Deck deck = Deck();
    HoleCards hole = HoleCards();
    hole.card1 = deck.pop();
    hole.card2 = deck.pop();
    CommunityCards comm = CommunityCards(deck.pop(), deck.pop(), deck.pop());
    ASSERT_EQ(47, deck.size());
    Hand hand = Hand(hole, comm);

//    cout << std::get<0>(hole) << endl;
//    Hand hand = Hand()
}