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

#define quote(x) #x

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
        std::map<std::string, int> hand_types;
        HoleCards _holeCards;
        CommunityCards _communityCards;
        CardCollection _cards = _holeCards + _communityCards;
        std::string type_fake = "BaseHandClass";

        std::map<std::string, int> handHeirachy();

    private:

        friend std::ostream &operator<<(std::ostream &os, const Hand &hand);

        std::string name;

    public:

        HandType type = HandType::Hand_;

        explicit Hand(CardCollection collection);

        explicit Hand(Hand *hand);

        Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);

        Hand(Hand &hand); // copy constructor

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

        HandType getHandType();

        std::string getTypeFake();

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
            for (int i = 0; i < ranks.size(); i++) {
                for (int j = 0; j < cards.size(); j++) {
                    if (getCards()[j].rank == ranks[i]) {
                        Card x = cards[j];
                        best5.add(x);
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

        CardCollection best5();

        std::unique_ptr<Hand> evaluate();

        /*
         * This is for determining which is the best hand.
         * Not yet implemented as not needed until gameplay
         * is ready.
         */
        static Hand evaluate(const vector<Hand> &hands);

        int sumBest5Ranks();

    };

    class HighCard : public Hand {
    public:
        using Hand::Hand;

        explicit HighCard(Hand *hand);

        explicit HighCard(CardCollection collection);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class Pair : public Hand {
    public:
        using Hand::Hand;


        explicit Pair(Hand *hand);

        explicit Pair(CardCollection collection);

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class TwoPair : public Hand {
    private:
    public:
        explicit TwoPair(Hand *hand);

        explicit TwoPair(CardCollection collection);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;
    };


    class ThreeOfAKind : public Hand {

    private:
    public:
        explicit ThreeOfAKind(Hand *hand);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class Straight : public Hand {
    private:
    public:
        explicit Straight(Hand *hand);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


    class Flush : public Hand {
    private:
    public:
        explicit Flush(Hand *hand);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class FullHouse : public Hand {
    private:
    public:
        explicit FullHouse(Hand *hand);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class FourOfAKind : public Hand {
    private:
    public:
        explicit FourOfAKind(Hand *hand);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class StraightFlush : public Hand {

    private:
    public:
        explicit StraightFlush(Hand *hand);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };

    class RoyalFlush : public Hand {

    private:
    public:
        explicit RoyalFlush(Hand *hand);

        using Hand::Hand;

        CardCollection best5(CardCollection cards) override;

        bool isa() override;

    };


};

#endif //POKERSIMULATIONSINCPP_HAND_H