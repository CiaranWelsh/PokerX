//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HAND_H
#define POKERSIMULATIONSINCPP_HAND_H

#include <tuple>
#include <utility>
#include "Card.h"
#include "CardCollection.h"
#include "CommunityCards.h"
#include "HoleCards.h"


namespace Game {

    class Hand {
    private:
        HoleCards _holeCards;
        CommunityCards _communityCards;
    public:
        Hand(HoleCards &holeCards, CommunityCards &communityCards); //constructor
        ~Hand(); // destructor
        Hand(const Hand &hand); // copy constructor

//        Hand evaluate();

        std::vector<Card> getCards();
    };
};

#endif //POKERSIMULATIONSINCPP_HAND_H
