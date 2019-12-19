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

using namespace cards;

namespace eval {

    class HandInterface{
    public:
        virtual CardCollection best5() = 0;

        virtual bool isa() = 0;

    };

    class Hand : HandInterface {
    protected:
        HoleCards _holeCards;
        CommunityCards _communityCards;
        CardCollection _cards = _holeCards + _communityCards;
    private:
        friend std::ostream &operator<<(std::ostream &os, const Hand &hand);

    public:
        Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
        ~Hand(); // destructor

        Hand(const Hand &hand); // copy constructor

        CommunityCards getCards();

        void shuffle();

        CardCollection best5() override;

        bool isa() override;
    };

    class HighCard : public HandInterface {
    public:
        HighCard(HoleCards &holeCards, CommunityCards &communityCards);

        CardCollection best5() override;

        bool isa() override;

    };


};

#endif //POKERSIMULATIONSINCPP_HAND_H
