//
// Created by CiaranWelsh on 16/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTION_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTION_H

#include <vector>
#include <set>
#include "PokerX/engine/Card.h"
#include "PokerX/engine/Counter.h"

namespace pokerx {

    class CardCollection {

    public:

        CardCollection() = default;

        virtual ~CardCollection() = default;

        CardCollection(const CardCollection &cardCollection);

        CardCollection(CardCollection &&cardCollection) noexcept;

        CardCollection &operator=(const CardCollection &c);

        CardCollection &operator=(CardCollection &&c) noexcept;

        explicit CardCollection(std::vector<ICardPtr> cards);

        explicit CardCollection(ICardPtr &card);

        friend std::ostream &operator<<(std::ostream &os, const CardCollection &c);

        ICardPtr operator[](unsigned int index);

        virtual void add(const ICard &card);

        virtual void add(ICardPtr &card);

        virtual void add(std::vector<ICardPtr> &cards);

        virtual void add(CardCollection &cards);

        CardCollection operator()(unsigned int start, unsigned int end);

//        CardCollection &operator+(CardCollection &other);
//
//        CardCollection &operator+=(CardCollection &other);
//
        bool operator==(const CardCollection &other) const;

        bool operator!=(const CardCollection &other) const;

        void erase(int index);

        [[nodiscard]] std::vector<ICardPtr>::const_iterator end() const;

        [[nodiscard]] std::vector<ICardPtr>::const_iterator begin() const;

        std::reverse_iterator<std::vector<ICardPtr>::iterator> rbegin();

        std::reverse_iterator<std::vector<ICardPtr>::iterator> rend();

        [[nodiscard]] std::vector<ICardPtr> &getCards();

        [[nodiscard]] std::vector<int> getRanks() const;

        std::vector<std::string> getSuits();

        void pushBack(ICardPtr &card);

        [[nodiscard]] int size() const;

        void sort();

        CardCollection pop_back(int n);

        CardCollection pop(int n);

        ICardPtr pop();

        ICardPtr pop_back();

        void insert(std::vector<ICardPtr>::const_iterator position, ICardPtr &card);

        int findCard(ICardPtr &card);

        [[nodiscard]] bool empty() const;

        CardCollection *shuffle();

        [[nodiscard]] std::vector<int> getUniqueRanks() const;

        std::set<std::string> getUniqueSuits();

        bool contains(ICardPtr &card);

        [[nodiscard]] bool containsRank(int rank) const;

        bool containsSuit(const std::string &suit);

        ICardPtr findByRank(int i);

        void clear();

        CardCollection setDifference(CardCollection &other);

        CardCollection setIntersection(CardCollection &other);

//        CardCollection copy();

        bool isUniqueSet();

        /**
         * @brief computes whether card collection is a
         * x of a kind where @param x is two three or four
         * @param how_many is 1 for all cases except two pair
         * when it becomes 1. Can also be 3 for special case
         * of checking whether two pair is 3 pair
         * @note This method currently violate SRP refactor
         *
         */
        [[nodiscard]] bool xOfAKindIsA(int x, int how_many = 1) const;

        /**
         * @brief returns the 5 best cards for x of a kind
         * where @param x is 2, 3, or 4.
         * @details template parameter @param HandType
         * must be Pair, TwoPair, ThreeOfAKind or FourOfAKind
         *
         */
        template<typename HandType>
        [[nodiscard]] CardCollection xOfAKindBest5(int x) {
            HandType handType(cards_);
            if (!handType.isA())
                //  if not isa HandType, return empty CardCollection.
                return CardCollection();
            CardCollection best5;
            Counter<int> counter(getRanks());
            std::unordered_map<int, int> count = counter.count();
            // get the rank of the card which has a pair/two pair etc.
            std::vector<int> ranks;
            for (auto[rank, count] : counter.count()) {
                if (count == x) {
                    ranks.push_back(rank);
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
                for (int j = 0; j < size(); j++) {
                    if (getCards()[j]->getRank() == rank) {
                        // dont steal the pointer
                        ICardPtr card = std::make_unique<Card>((*getCards()[j]).getRank(), (*getCards()[j]).getSuit());
                        best5.add(card);
                        idx_for_delete.push_back(j);
                    }
                }
            }
            for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
                erase(*it);
            }
            sort();
            CardCollection sliced = operator()(2, size());
            best5.add(sliced);
            return best5;
        }


    protected:
        std::vector<ICardPtr> cards_;

        int getValueOfXOfAKind(int x);
    };

    using SharedCardCollection = std::shared_ptr<CardCollection>;
}

#include "Card.h"

#endif //POKERSIMULATIONSINCPP_CARDCOLLECTION_H
