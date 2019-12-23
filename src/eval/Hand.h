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

        bool xOfAKind(int x, int how_many = 1);

        /*
         * Defined in .h file because templates wont compile in separate implementation
         * file. HandType can only be Pair, TwoPair, ThreeOfAKind or FourOfAKind
         */
        template<class HandType>
        CardCollection xOfAKindBest5(int x) {
            CardCollection cards = getCards();
            HandType handType(*this);
            if (!handType.isa())
                // if not isa HandType, return empty CardCollection.
                return CardCollection();
            CardCollection best5;
            Counter<int> counter(cards.getRanks());
            std::unordered_map<int, int> count = counter.count();
            // get the rank of the card which has a pair
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

            if (ranks.size() != 1)
                throw std::invalid_argument("Unhelpful error message");
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
            cout << idx_for_delete.size() << endl;
            for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
                cards.erase(*it);
            }
            cards.sort();
            best5.add(cards(2, cards.size()));
            return best5;
        }


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