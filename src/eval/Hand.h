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
        virtual CardCollection best5(CardCollection cards) = 0;

        virtual bool isa() = 0;

    };


    class Hand : IHand {
    protected:
        HoleCards _holeCards;
        CommunityCards _communityCards;
        CardCollection _cards = _holeCards + _communityCards;
        int value = 0;

    private:

        friend std::ostream &operator<<(std::ostream &os, const Hand &hand);

        std::string name;

    public:
        HandType type = HandType::Hand_;

        explicit Hand(CardCollection &collection);

        explicit Hand(const shared_ptr<Hand>& hand);

        Hand(Hand &hand);

        Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        Hand(Hand &&) = default;

        ~Hand(); // destructor

        Hand &operator=(Hand hand); //copy assignment

        Hand &operator=(Hand &&) noexcept; //copy assignment

        bool operator==(Hand &hand);

        bool operator!=(Hand &hand);

        bool operator>(Hand &hand);

        bool operator<(Hand &hand);

        CommunityCards getCards();

        void shuffle();

        CardCollection best5(CardCollection cards) override;

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
            HandType handType(_cards);
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

        virtual CardCollection best5();

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
        using Hand::Hand;

        explicit HighCard(const HandPtr& hand);

        explicit HighCard(CardCollection &collection);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

        void setValue() override;
    };


    class Pair : public Hand {
    public:
        using Hand::Hand;

        explicit Pair(const HandPtr& hand);

        explicit Pair(CardCollection &collection);

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };


    class TwoPair : public Hand {
    public:
        explicit TwoPair(const HandPtr& hand);

        explicit TwoPair(CardCollection &collection);

        using Hand::Hand;

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };


    class ThreeOfAKind : public Hand {
    public:
        explicit ThreeOfAKind(const HandPtr& hand);

        using Hand::Hand;

        explicit ThreeOfAKind(CardCollection &collection);

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };


    class Straight : public Hand {
    public:
        explicit Straight(const HandPtr& hand);

        using Hand::Hand;

        explicit Straight(CardCollection &collection);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

        void setValue() override;
    };


    class Flush : public Hand {
    public:
        explicit Flush(const HandPtr& hand);

        using Hand::Hand;

        explicit Flush(CardCollection &collection);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

        void setValue() override;
    };

    class FullHouse : public Hand {
    public:
        explicit FullHouse(const HandPtr& hand);

        using Hand::Hand;

        explicit FullHouse(CardCollection &collection);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

        void setValue() override;
    };

    class FourOfAKind : public Hand {
    public:
        explicit FourOfAKind(const HandPtr& hand);

        using Hand::Hand;

        explicit FourOfAKind(CardCollection &collection);

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };

    class StraightFlush : public Hand {
    public:
        explicit StraightFlush(const HandPtr& hand);

        using Hand::Hand;

        explicit StraightFlush(CardCollection &collection);

        CardCollection best5() override;

        bool isa() override;

        void setValue() override;
    };

    class RoyalFlush : public Hand {
    public:
        explicit RoyalFlush(const HandPtr& hand);

        using Hand::Hand;

        explicit RoyalFlush(CardCollection &collection);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

        void setValue() override;
    };


}

#endif //POKERSIMULATIONSINCPP_HAND_H