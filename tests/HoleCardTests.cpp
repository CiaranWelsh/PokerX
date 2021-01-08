//
// Created by CiaranWelsh on 18/12/2019.
//

#include "gtest/gtest.h"
#include "card/Card.h"
#include "eval/Hand.h"
#include "card/Deck.h"


TEST(HoleCardTests, HoleCardTests) {
    Deck deck = Deck();
    deck.sort();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    HoleCards h(card1, card2);
    ASSERT_TRUE(card1.rank == 2);
}

