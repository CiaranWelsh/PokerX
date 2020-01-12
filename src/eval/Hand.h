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
#include <utils/Counter.h>
#include <map>

using namespace cards;

namespace eval {



    enum HandType {
        Hand_, HighCard_, Pair_, TwoPair_, ThreeOfAKind_, Straight_, Flush_,
        FullHouse_, FourOfAKind_, StraightFlush_, RoyalFlush_
    };

    class IHand {
    public:
        virtual CardCollection best5() = 0;

        virtual bool isa() = 0;

    };


    class Hand : IHand {
    protected:
        HoleCards holeCards;
        CommunityCards communityCards;
        CardCollection cards_ = holeCards + communityCards;
        int value = 0;

    private:

        friend std::ostream &operator<<(std::ostream &os, const Hand &hand);

        std::string name;

    public:
        HandType type = HandType::Hand_;

        Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit Hand(CardCollection &collection);

        explicit Hand(Hand* hand);

        Hand(Hand &hand);

        ~Hand(); // destructor

        Hand &operator=(Hand hand); //copy assignment

        Hand(Hand&& hand) noexcept ;    // move constructor

        Hand &operator=(Hand &&hand) noexcept; //Move assignment

        bool operator==(Hand &hand);

        bool operator!=(Hand &hand);

        bool operator>(Hand &hand);

        bool operator<(Hand &hand);

        CommunityCards getCards();

        void shuffle();

        bool isa() override;

        HandType getHandType() const;

        bool xOfAKindIsA(int x, int how_many = 1);

        /*
         * Defined in .h file because templates wont compile in separate implementation
         * file. HandType can only be Pair, TwoPair, ThreeOfAKind or FourOfAKind
         */
        template<class HandType>
        CardCollection xOfAKindBest5(int x) {
            CardCollection cards = getCards();
            HandType handType(cards_);
            if (!handType.isa())
                // if not isa HandType, return empty CardCollection.
                return CardCollection();
            CardCollection best5;
            Counter<int> counter(cards.getRanks());
            std::unordered_map<int, int> count = counter.count();
            // get the rank of the card which has a pair/two pair etc.
            std::vector<int> ranks;
            for (pair<const int, int> i : counter.count()) {
                if (i.second == x) {
                    ranks.push_back(i.first);
                }
            }
            // cater for special case when we have three pairs
            // when we have 3 pairs, sort in ascending order and remove first element
            if (x == 2 && ranks.size() == 3) {
                std::sort(ranks.begin(), ranks.end());
                ranks.erase(ranks.begin());
            }
            std::vector<int> idx_for_delete;
            for (int rank : ranks) {
                for (int j = 0; j < cards.size(); j++) {
                    if (getCards()[j].rank == rank) {
                        Card card = cards[j];
                        best5.add(card);
                        idx_for_delete.push_back(j);
                    }
                }
            }
            for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
                cards.erase(*it);
            }
            cards.sort();
            best5.add(cards(2, cards.size()));
            return best5;
        }

        virtual CardCollection best5() override ;

        std::shared_ptr<Hand> evaluate();

        int sumBest5Ranks();

        int getValueOfXOfAKind(int x);

        int getLargestRank();

        virtual void setValue();

        int getValue();

    };

    typedef std::shared_ptr<Hand> HandPtr;

    class HighCard : public Hand {
    public:
        HighCard(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit HighCard(CardCollection &collection);

        explicit HighCard(Hand* hand);

        HighCard(Hand &hand);

//        HighCard &operator=(Hand hand); //copy assignment

        HighCard(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        bool isa() override;

        void setValue() override;

        CardCollection best5() override ;
    };


    class Pair : public Hand {
    public:

        Pair(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit Pair(CardCollection &collection);

        explicit Pair(Hand* hand);

        Pair(Hand &hand);

        Pair(Hand&& hand) noexcept ;    // move constructor

        void setValue() override;

        bool isa() override;

        CardCollection best5() override;
    };


    class TwoPair : public Hand {
    public:

        TwoPair(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit TwoPair(CardCollection &collection);

        explicit TwoPair(Hand* hand);

        TwoPair(Hand &hand);

//        TwoPair &operator=(Hand hand); //copy assignment

        TwoPair(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };


    class ThreeOfAKind : public Hand {
    public:

        ThreeOfAKind(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit ThreeOfAKind(CardCollection &collection);

        explicit ThreeOfAKind(Hand* hand);

        ThreeOfAKind(Hand &hand);

        ThreeOfAKind(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };


    class Straight : public Hand {
    public:

        Straight(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit Straight(CardCollection &collection);

        explicit Straight(Hand* hand);

        Straight(Hand &hand);

        Straight(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };


    class Flush : public Hand {
    public:
        Flush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit Flush(CardCollection &collection);

        explicit Flush(Hand* hand);

        Flush(Hand &hand);

//        Flush &operator=(Hand hand); //copy assignment

        Flush(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };

    class FullHouse : public Hand {
    public:

        FullHouse(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit FullHouse(CardCollection &collection);

        explicit FullHouse(Hand* hand);

        FullHouse(Hand &hand);

        FullHouse(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };

    class FourOfAKind : public Hand {
    public:

        FourOfAKind(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit FourOfAKind(CardCollection &collection);

        explicit FourOfAKind(Hand* hand);

        FourOfAKind(Hand &hand);

        FourOfAKind &operator=(Hand hand); //copy assignment

        FourOfAKind(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };

    class StraightFlush : public Hand {
    public:

        StraightFlush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit StraightFlush(CardCollection &collection);

        explicit StraightFlush(Hand* hand);

        StraightFlush(Hand &hand);

//        StraightFlush &operator=(Hand hand); //copy assignment

        StraightFlush(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };

    class RoyalFlush : public Hand {
    public:

        RoyalFlush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        explicit RoyalFlush(CardCollection &collection);

        explicit RoyalFlush(Hand* hand);

        RoyalFlush(Hand &hand);

//        RoyalFlush &operator=(Hand hand); //copy assignment

        RoyalFlush(Hand&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };


}

#endif //POKERSIMULATIONSINCPP_HAND_H