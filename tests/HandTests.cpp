//
// Created by CiaranWelsh on 08/12/2019.
//

#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Hand.h"



TEST(HandTests, test1){
    Deck deck;
    CardCollection cc = deck.pop(5);
    CommunityCards communityCards(cc);

    HoleCards hc = deck.pop(2);


//    int f = ih.integer;


}
