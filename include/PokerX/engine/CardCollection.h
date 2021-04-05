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

        CardCollection(std::initializer_list<ICardPtr > init);

        CardCollection(std::initializer_list<std::string> cards);

        CardCollection(std::vector<std::string> vector);

        virtual ~CardCollection() = default;

        explicit CardCollection(std::vector<ICardPtr > cards);

        friend std::ostream &operator<<(std::ostream &os, const CardCollection &c);

        ICardPtr  operator[](unsigned int index);

        virtual void add(ICardPtr  card);

        virtual void add(const std::vector<ICardPtr > &cards);

        virtual void add(const CardCollection &cards);

        CardCollection operator()(unsigned int start, unsigned int end);

        CardCollection &operator+(CardCollection &other);

        CardCollection &operator+=(CardCollection &other);

        CardCollection &operator=(const std::vector<ICardPtr > &c);

        CardCollection &operator=(const CardCollection &c);

        bool operator==(const CardCollection &other) const;

        bool operator!=(const CardCollection &other) const;

        bool operator==(const std::vector<std::string> &other) const;

        bool operator!=(const std::vector<std::string> &other) const;

        void erase(int index);

        [[nodiscard]] std::vector<ICardPtr >::const_iterator end() const;

        [[nodiscard]] std::vector<ICardPtr >::const_iterator begin() const;

        std::reverse_iterator<std::vector<ICardPtr >::iterator> rbegin();

        std::reverse_iterator<std::vector<ICardPtr >::iterator> rend();

        [[nodiscard]] std::vector<ICardPtr > getCards() const;

        [[nodiscard]] std::vector<int> getRanks() const;

        std::vector<std::string> getSuits();

        virtual void pushBack(ICardPtr  card);

        [[nodiscard]] int size() const;

        void sort();

        CardCollection pop_back(int n);

        CardCollection pop(int n);

        ICardPtr  pop();

        ICardPtr  pop_back();

        void insert(std::vector<ICardPtr >::const_iterator position, ICardPtr  card);

        void insert(std::vector<ICardPtr>::const_iterator position, std::string card) ;

        void erase(const ICardPtr& card);

        void erase(const std::string& card);

        int findCard(ICardPtr  card);

        int findCard(const std::string& card);

        [[nodiscard]] bool empty() const;

        CardCollection *shuffle();

        std::vector<int> getUniqueRanks();

        std::set<std::string> getUniqueSuits();

        bool contains(std::string  card);

        bool contains(ICardPtr card);

        bool containsRank(int rank);

        bool containsSuit(const std::string &suit);

        ICardPtr  findByRank(int i);

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
        template<typename HandType>
        [[nodiscard]] CardCollection xOfAKindBest5(int x) const {
            CardCollection cards(getCards());
            HandType handType(cards_);
            if (!handType.isA())
                //  if not isa HandType, return empty CardCollection.
                return CardCollection();
            CardCollection best5;
            Counter<int> counter(cards.getRanks());
            std::unordered_map<int, int> count = counter.count();
            // get the rank of the card which has a pair/two pair etc.
            std::vector<int> ranks;
            for (auto[rank, count] : counter.count()) {
                if (count == x) {
                    ranks.push_back(rank);
                }
            }
            std::sort(ranks.begin(), ranks.end());
            // cater for special case when we have three pairs
            // when we have 3 pairs, sort in ascending order and erase first element
            if (x == 2 && ranks.size() == 3) {
                ranks.erase(ranks.begin());
            }

            // note: ordering is very important for this to work.
            // but CardCollections are always maintained in order anyway.
            std::vector<int> idx_for_delete;
            for (int rank : ranks) {
                for (int j = 0; j < cards.size(); j++) {
                    if (getCards()[j]->getRank() == rank) {
                        ICardPtr  card = cards[j];
                        best5.add(card);
                        idx_for_delete.push_back(j);
                    }
                }
            }
            for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
                cards.erase(*it);
            }
            best5.add(cards(2, cards.size()));
            return best5;
        }


    protected:
        std::vector<ICardPtr > cards_;

        int getValueOfXOfAKind(int x);
    };

    using SharedCardCollection = std::shared_ptr<CardCollection>;
}

#include "Card.h"

#endif //POKERSIMULATIONSINCPP_CARDCOLLECTION_H
