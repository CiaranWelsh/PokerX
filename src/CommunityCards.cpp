//
// Created by CiaranWelsh on 18/12/2019.
//

#include <stdexcept>
#include "CommunityCards.h"


namespace Game {


    CommunityCards::CommunityCards(Card &flop1, Card &flop2, Card &flop3) {
        this->add(flop1);
        this->add(flop2);
        this->add(flop3);

    }

    CommunityCards::CommunityCards(Card &flop1, Card &flop2, Card &flop3, Card &turn) {
        this->add(flop1);
        this->add(flop2);
        this->add(flop3);
        this->add(turn);

    }

    CommunityCards::CommunityCards(Card &flop1, Card &flop2, Card &flop3, Card &turn, Card &river) {
        this->add(flop1);
        this->add(flop2);
        this->add(flop3);
        this->add(turn);
        this->add(river);

    }

    CommunityCards::CommunityCards(CardCollection container) : CardCollection(container){}

    CommunityCards::CommunityCards(std::vector<Card> &container) : CardCollection(container){};

    CommunityCards::CommunityCards() = default;

    CommunityCards::~CommunityCards() = default;



}