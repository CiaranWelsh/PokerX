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


TEST(HandTests, HoleCardTests) {
    Deck deck = Deck();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    HoleCards hole = HoleCards(&card1, &card2);
    Card expected = Card(2, 'S');
    ASSERT_TRUE(card1 == expected);
}

TEST(HandTests, CommCardsTests) {
    Deck deck = Deck();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    Card card3 = deck.pop();
    Card card4 = deck.pop();
    Card card5 = deck.pop();
    CommunityCards comm = CommunityCards(
            &card1, &card2, &card3);
    Card expected = Card(2, 'S');
    ASSERT_TRUE(comm.flop1 == expected);
}

TEST(HandTests, CommCardsTestsTurn) {
    Deck deck = Deck();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    Card card3 = deck.pop();
    Card card4 = deck.pop();
    CommunityCards comm = CommunityCards(
            &card1, &card2, &card3, &card4 );
    Card expected = Card(2, 'H');
    ASSERT_TRUE(card1 == expected);
}

TEST(HandTests, CommunityCardTests) {
    Deck deck = Deck();
//    cout << deck[3].suit << endl;
    int i = 5;
    std::vector<Card> cards;
    while (i > 0){
        cards.push_back(deck.pop());
        i--;
    }
    cout << cards[0].suit << endl;
//    CommunityCards commCards = CommunityCards(cards);
//    cout << commCards.flop1->suit << endl;
//    Card *card = commCards.turn;
//    cout << card->rank << card->suit<<endl;
}

TEST(HandTests, getCardsTests) {
    Deck deck = Deck();
    int i = 3;
    std::vector<Card> cards;
    while (i > 0){
        cards.push_back(deck.pop());
        i--;
    }
    CommunityCards commCards = CommunityCards(cards);
    Card *card = commCards.turn;
    cout << *card<<endl;
}

//    HoleCards hole = HoleCards();
//    hole.card1 = deck.pop();
//    hole.card2 = deck.pop();
//    CommunityCards comm = CommunityCards(deck.pop(), deck.pop(), deck.pop());
//    ASSERT_EQ(47, deck.size());
//    Hand hand = Hand(hole, comm);

//    cout << std::get<0>(hole) << endl;
//    Hand hand = Hand()
//}