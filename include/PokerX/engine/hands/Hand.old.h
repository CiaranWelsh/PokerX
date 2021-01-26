//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_HAND_H
#define POKERSIMULATIONSINCPP_HAND_H

#include <tuple>
#include <memory>
#include <map>
#include "PokerX/engine/Card.h"
#include "PokerX/engine/CardCollection.h"
#include "PokerX/engine/CommunityCards.h"
#include "PokerX/engine/HoleCards.h"
#include <PokerX/engine/Counter.h>

using namespace pokerx;

namespace pokerx {

    enum eHandType {
        Hand_,
        HighCard_,
        Pair_,
        TwoPair_,
        ThreeOfAKind_,
        Straight_,
        Flush_,
        FullHouse_,
        FourOfAKind_,
        StraightFlush_,
        RoyalFlush_
    };


//class Hand.old : public RestrictedCardCollection{
//    public:
//        Hand.old.old() override = default;
//
//        Hand.old();
//
//        virtual CardCollection best5() = 0;
//
//        virtual bool isa() = 0;
//
//private:
//    const HoleCards& holeCards_;
//
//    const CommunityCards &communityCards_;


//class Hand : public RestrictedCardCollection{
//    public:
//        Hand) override = default;
//
//        Hand();
//
//        virtual CardCollection best5() = 0;
//
//        virtual bool isa() = 0;
//
//        eHandType type = eHandType::Hand_;
//
//        Hand.old(HoleCards holeCards, cards::CommunityCards &communityCards);
//
//        explicit Hand.old(CardCollection &collection);
//
//        explicit Hand.old(Hand.old* hand);
//
//        Hand.old(Hand.old &hand);
//
//
//        bool operator==(Hand.old &hand);
//
//        bool operator!=(Hand.old &hand);
//
//        bool operator>(Hand.old &hand);
//
//        bool operator<(Hand.old &hand);
//
//        CommunityCards getCards();
//
//        void shuffle();
//
//        bool isa() override;
//
//        eHandType getHandType() const;
//
//        bool xOfAKindIsA(int x, int how_many = 1);
//
//        /*
//         * Defined in .h file because templates wont compile in separate implementation
//         * file. HandType can only be Pair, TwoPair, ThreeOfAKind or FourOfAKind
//         */
//        template<class HandType>
//        CardCollection xOfAKindBest5(int x) {
//            CardCollection cards = getCards();
//            HandType handType(cards_);
//            if (!handType.isa())
//                // if not isa HandType, return empty CardCollection.
//                return CardCollection();
//            CardCollection best5;
//            Counter<int> counter(cards.getRanks());
//            std::unordered_map<int, int> count = counter.count();
//            // get the rank of the card which has a pair/two pair etc.
//            std::vector<int> ranks;
//            for (pair<const int, int> i : counter.count()) {
//                if (i.second == x) {
//                    ranks.push_back(i.first);
//                }
//            }
//            // cater for special case when we have three pairs
//            // when we have 3 pairs, sort in ascending order and remove first element
//            if (x == 2 && ranks.size() == 3) {
//                std::sort(ranks.begin(), ranks.end());
//                ranks.erase(ranks.begin());
//            }
//            std::vector<int> idx_for_delete;
//            for (int rank : ranks) {
//                for (int j = 0; j < cards.size(); j++) {
//                    if (getCards()[j]->getRank() == rank) {
//                        Card card = cards[j];
//                        best5.add(card);
//                        idx_for_delete.push_back(j);
//                    }
//                }
//            }
//            for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
//                cards.erase(*it);
//            }
//            cards.sort();
//            best5.add(cards(2, cards.size()));
//            return best5;
//        }
//
//        virtual CardCollection best5() override ;
//
//        std::shared_ptr<Hand.old> evaluate();
//
//        int sumBest5Ranks();
//
//        int getValueOfXOfAKind(int x);
//
//        int getLargestRank();
//
//        virtual void setValue();
//
//        int getValue();
//    const CardCollection getCards() const;
//
//    void setCards(const CardCollection &cards);
//
//protected:
//        HoleCards holeCards;
//        CommunityCards communityCards;
//        CardCollection cards_;
//        int value = 0;
//
//private:
//
//        friend std::ostream &operator<<(std::ostream &os, const Hand &hand);
//
//        std::string name;
//    };

//    typedef std::shared_ptr<Hand.old> HandPtr;
//
//    class HighCard : public Hand.old {
//    public:
//        HighCard(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit HighCard(CardCollection &collection);
//
//        explicit HighCard(Hand.old* hand);
//
//        HighCard(Hand.old &hand);
//
////        HighCard &operator=(Hand.old hand); //copy assignment
//
//        HighCard(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        bool isa() override;
//
//        void setValue() override;
//
//        CardCollection best5() override ;
//    };
//
//
//    class Pair : public Hand.old {
//    public:
//
//        Pair(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit Pair(CardCollection &collection);
//
//        explicit Pair(Hand.old* hand);
//
//        Pair(Hand.old &hand);
//
//        Pair(Hand.old&& hand) noexcept ;    // move constructor
//
//        void setValue() override;
//
//        bool isa() override;
//
//        CardCollection best5() override;
//    };
//
//
//    class TwoPair : public Hand.old {
//    public:
//
//        TwoPair(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit TwoPair(CardCollection &collection);
//
//        explicit TwoPair(Hand.old* hand);
//
//        TwoPair(Hand.old &hand);
//
////        TwoPair &operator=(Hand.old hand); //copy assignment
//
//        TwoPair(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };
//
//
//    class ThreeOfAKind : public Hand.old {
//    public:
//
//        ThreeOfAKind(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit ThreeOfAKind(CardCollection &collection);
//
//        explicit ThreeOfAKind(Hand.old* hand);
//
//        ThreeOfAKind(Hand.old &hand);
//
//        ThreeOfAKind(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };
//
//
//    class Straight : public Hand.old {
//    public:
//
//        Straight(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit Straight(CardCollection &collection);
//
//        explicit Straight(Hand.old* hand);
//
//        Straight(Hand.old &hand);
//
//        Straight(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };
//
//
//    class Flush : public Hand.old {
//    public:
//        Flush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit Flush(CardCollection &collection);
//
//        explicit Flush(Hand.old* hand);
//
//        Flush(Hand.old &hand);
//
////        Flush &operator=(Hand.old hand); //copy assignment
//
//        Flush(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };
//
//    class FullHouse : public Hand.old {
//    public:
//
//        FullHouse(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit FullHouse(CardCollection &collection);
//
//        explicit FullHouse(Hand.old* hand);
//
//        FullHouse(Hand.old &hand);
//
//        FullHouse(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };
//
//    class FourOfAKind : public Hand.old {
//    public:
//
//        FourOfAKind(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit FourOfAKind(CardCollection &collection);
//
//        explicit FourOfAKind(Hand.old* hand);
//
//        FourOfAKind(Hand.old &hand);
//
//        FourOfAKind &operator=(Hand.old hand); //copy assignment
//
//        FourOfAKind(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };
//
//    class StraightFlush : public Hand.old {
//    public:
//
//        StraightFlush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit StraightFlush(CardCollection &collection);
//
//        explicit StraightFlush(Hand.old* hand);
//
//        StraightFlush(Hand.old &hand);
//
////        StraightFlush &operator=(Hand.old hand); //copy assignment
//
//        StraightFlush(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };
//
//    class RoyalFlush : public Hand.old {
//    public:
//
//        RoyalFlush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards);
//
//        explicit RoyalFlush(CardCollection &collection);
//
//        explicit RoyalFlush(Hand.old* hand);
//
//        RoyalFlush(Hand.old &hand);
//
////        RoyalFlush &operator=(Hand.old hand); //copy assignment
//
//        RoyalFlush(Hand.old&& hand) noexcept ;    // move constructor        CardCollection best5(CardCollection cards) override;
//
//        CardCollection best5() override;
//
//        bool isa() override;
//
//        void setValue() override;
//    };


}

#endif //POKERSIMULATIONSINCPP_HAND_H