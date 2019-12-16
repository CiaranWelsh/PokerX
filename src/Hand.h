//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HAND_H
#define POKERSIMULATIONSINCPP_HAND_H

#include <tuple>
#include <utility>
#include "Card.h"

namespace Game {
    struct HoleCards {
        HoleCards(Card *card1, Card *card2) : card1(card1), card2(card2) {};

        Card *card1;
        Card *card2;
    };

    struct CommunityCards {
        Card *flop1;
        Card *flop2;
        Card *flop3;
        Card *turn;
        Card *river;

        CommunityCards() = default;

        CommunityCards(Card *card1, Card *card2, Card *card3);

        CommunityCards(Card *card1, Card *card2, Card *card3, Card *card4);

        CommunityCards(Card *card1, Card *card2, Card *card3, Card *card4, Card *card5);

        /*
         * When cards is a vector of cards we
         * unpack them into flop1-3 first, then the turn
         * and then the river
         */
        explicit CommunityCards(std::vector<Card> &cards);
    };

    class PlayerCards {
    private:
        HoleCards _holeCards;
        CommunityCards _comCards;
    public:
        PlayerCards() = default;
//        ~PlayerCards();
//        PlayerCards(HoleCards hCards);
//        PlayerCards(HoleCards hCards, CommunityCards commCards);
//        void setHoleCards(HoleCards hCards);
//        std::vector<Card> getHoleCards();
//        void setCommCards(CommunityCards commCards);
//        std::vector<Card> getcommCards();
    };

    class Hand {
    private:
        HoleCards _holeCards;
        CommunityCards _communityCards;
    public:
        Hand(HoleCards holeCards, CommunityCards communityCards); //constructor
        ~Hand(); // destructor
        Hand(const Hand &hand); // copy constructor

//        Hand evaluate();

        std::vector<Card> getCards();
    };
};

#endif //POKERSIMULATIONSINCPP_HAND_H
