//
// Created by CiaranWelsh on 18/12/2019.
//

#include "gtest/gtest.h"
#include "cards/Card.h"
#include "eval/Hand.h"
#include "cards/Deck.h"


TEST(HoleCardTests, HoleCardTests) {
    Deck deck = Deck();
    Card card1 = deck.pop();
    Card card2 = deck.pop();
    HoleCards h(card1, card2);
    Card expected(2, "S");
    ASSERT_TRUE(card1 == expected);
}

