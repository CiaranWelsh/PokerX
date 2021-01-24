//
// Created by CiaranWelsh on 16/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTION_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTION_H

#include <vector>
#include "Card.h"

namespace pokerx {

    class CardCollection {

    protected:
        std::vector<ICard *> cards_;
    public:

        CardCollection() = default;

        virtual ~CardCollection() = default;

        explicit CardCollection(std::vector<ICard*> cards);

        friend std::ostream &operator<<(std::ostream &os, const CardCollection &c);

        ICard* operator[](int index);

        virtual void add(ICard* card);

        virtual void add(const std::vector<ICard*>& cards);

        CardCollection operator()(unsigned int start, unsigned int end);

        CardCollection operator+(CardCollection &other);

        CardCollection operator+=(CardCollection &other);

        CardCollection &operator=(const std::vector<ICard *> &c);

        CardCollection &operator=(const CardCollection &c);

        bool operator==(const CardCollection &other) const;

        bool operator!=(const CardCollection &other) const ;

        void erase(int index);

        [[nodiscard]] std::vector<ICard*>::const_iterator end() const;

        [[nodiscard]] std::vector<ICard*>::const_iterator begin() const;

        std::reverse_iterator<std::vector<ICard*>::iterator> rbegin();

        std::reverse_iterator<std::vector<ICard*>::iterator> rend();


        std::vector<ICard*> getCards();

        std::vector<int> getRanks();

        std::vector<std::string> getSuits();

        void pushBack(ICard* card);

        int size();

        void sort();

        CardCollection pop(int n);

        ICard* pop();

        [[nodiscard]] bool empty() const;

        CardCollection *shuffle();


        std::vector<int> getUniqueRanks();

        std::vector<std::string> getUniqueSuits();

        void add(const CardCollection& cards);

        bool contains(ICard* card);

        bool containsRank(int rank);

        bool containsSuit(const std::string& suit);

        ICard* findByRank(int i);

        void clear();

        CardCollection setDifference(CardCollection& other) const;

        CardCollection setIntersection(CardCollection& other) const;

        CardCollection copy();

        bool isUniqueSet();

    };
}

#include "Card.h"

#endif //POKERSIMULATIONSINCPP_CARDCOLLECTION_H
