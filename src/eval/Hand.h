//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HAND_H
#define POKERSIMULATIONSINCPP_HAND_H

#include <tuple>
#include <utility>
#include "cards/Card.h"
#include "cards/CardCollection.h"
#include "cards/CommunityCards.h"
#include "cards/HoleCards.h"
#include <memory>

#define quote(x) #x

using namespace cards;

namespace eval {

    class HandInterface {
    public:
        virtual CardCollection best5(CardCollection cards) = 0;

        virtual bool isa() = 0;

    };

    class Hand : HandInterface {
    protected:
        Hand(CardCollection collection);

        HoleCards _holeCards;
        CommunityCards _communityCards;
        CardCollection _cards = _holeCards + _communityCards;
    private:
        friend std::ostream &operator<<(std::ostream &os, const Hand &hand);

        std::string name;
    public:
        Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        ~Hand(); // destructor

        Hand(const Hand &hand); // copy constructor

        CommunityCards getCards();

        void shuffle();

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

        std::unique_ptr<Hand> evaluate();

        bool checkIfNRanksInHand(int n);

        static CardCollection xOfAKind(CardCollection cards, int x);
    };

    class HighCard : public Hand {
    public:
        HighCard(HoleCards &holeCards, CommunityCards &communityCards);

        explicit HighCard(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class Pair : public Hand {
    public:
        Pair(HoleCards &holeCards, CommunityCards &communityCards);

        explicit Pair(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class TwoPair : public Hand {
    public:
        TwoPair(HoleCards &holeCards, CommunityCards &communityCards);

        explicit TwoPair(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class ThreeOfAKind : public Hand {
    public:
        ThreeOfAKind(HoleCards &holeCards, CommunityCards &communityCards);

        explicit ThreeOfAKind(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class Straight : public Hand {
    public:
        Straight(HoleCards &holeCards, CommunityCards &communityCards);

        explicit Straight(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class Flush : public Hand {
    public:
        Flush(HoleCards &holeCards, CommunityCards &communityCards);

        explicit Flush(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class FullHouse : public Hand {
    public:
        FullHouse(HoleCards &holeCards, CommunityCards &communityCards);

        explicit FullHouse(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class FourOfAKind : public Hand {
    public:
        FourOfAKind(HoleCards &holeCards,
                    CommunityCards &communityCards);

        explicit FourOfAKind(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class StraightFlush : public Hand {
    public:
        StraightFlush(HoleCards &holeCards,
                      CommunityCards &communityCards);

        explicit StraightFlush(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class RoyalFlush : public Hand {
    public:
        RoyalFlush(HoleCards &holeCards, CommunityCards &communityCards);

        explicit RoyalFlush(const Hand &hand);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


};

#endif //POKERSIMULATIONSINCPP_HAND_H