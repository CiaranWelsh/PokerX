//
// Created by CiaranWelsh on 16/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTION_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTION_H

#include <vector>
#include "PokerX/engine/Card.h"
#include "PokerX/engine/Counter.h"
//#include "PokerX/engine/hands/Best5.h"

namespace pokerx {

    class CardCollection {

    public:

        CardCollection() = default;

        CardCollection(std::initializer_list<ICard*> init);

        virtual ~CardCollection() = default;

        explicit CardCollection(std::vector<ICard *> cards);

        friend std::ostream &operator<<(std::ostream &os, const CardCollection &c);

        ICard *operator[](int index);

        virtual void add(ICard *card);

        virtual void add(const std::vector<ICard *> &cards);

        CardCollection& operator()(unsigned int start, unsigned int end);

        CardCollection &operator+(CardCollection &other);

        CardCollection &operator+=(CardCollection &other);

        CardCollection &operator=(const std::vector<ICard *> &c);

        CardCollection &operator=(const CardCollection &c);

        bool operator==(const CardCollection &other) const;

        bool operator!=(const CardCollection &other) const;

        void erase(int index);

        [[nodiscard]] std::vector<ICard *>::const_iterator end() const;

        [[nodiscard]] std::vector<ICard *>::const_iterator begin() const;

        std::reverse_iterator<std::vector<ICard *>::iterator> rbegin();

        std::reverse_iterator<std::vector<ICard *>::iterator> rend();

        [[nodiscard]] std::vector<ICard *> getCards() const;

        [[nodiscard]] std::vector<int> getRanks() const;

        std::vector<std::string> getSuits();

        void pushBack(ICard *card);

        [[nodiscard]] int size() const;

        void sort();

        CardCollection pop(int n);

        ICard *pop();

        [[nodiscard]] bool empty() const;

        CardCollection *shuffle();

        std::vector<int> getUniqueRanks();

        std::vector<std::string> getUniqueSuits();

        void add(const CardCollection &cards);

        bool contains(ICard *card);

        bool containsRank(int rank);

        bool containsSuit(const std::string &suit);

        ICard *findByRank(int i);

        void clear();

        CardCollection setDifference(CardCollection &other) const;

        CardCollection setIntersection(CardCollection &other) const;

        CardCollection copy();

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
        template<class HandType>
        [[nodiscard]] CardCollection xOfAKindBest5(int x) const {
            if (size() > 7 ) {
                return CardCollection();
            }
            HandType handType(cards_);
            if (!handType.isA())
                // if not isa HandType, return empty CardCollection.
                return CardCollection();
            CardCollection best5;
            Counter<int> counter(getRanks());

            // rank: number
            std::unordered_map<int, int> count = counter.count();

            // get the rank of the card which has a pair/two pair etc.
            std::vector<int> ranks;
            for (std::pair<const int, int> i : count) {
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
//            std::vector<int> idx_for_delete;
//            for (int rank : ranks) {
//                for (int j = 0; j < size(); j++) {
//                    if (getCards()[j]->getRank() == rank) {
//                        best5.add(cards_[j]);
//                        idx_for_delete.push_back(j);
//                    }
//                }
//            }
//            for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
//                cards.erase(*it);
//            }
//            cards.sort();
//            best5.add(cards(2, cards.size()));
            return best5;
        }


    protected:
        std::vector<ICard *> cards_;
    };

    using SharedCardCollection = std::shared_ptr<CardCollection>;
}

#include "Card.h"

#endif //POKERSIMULATIONSINCPP_CARDCOLLECTION_H
