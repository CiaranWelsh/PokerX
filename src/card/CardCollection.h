//
// Created by CiaranWelsh on 16/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTION_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTION_H

#include <vector>
#include "Card.h"

namespace cards {

    class CardCollection {

    protected:
        vector<ICard *> cards_;
    public:

        CardCollection() = default;

        virtual ~CardCollection() = default;

        explicit CardCollection(vector<ICard*> cards);

        friend ostream &operator<<(ostream &os, const CardCollection &c);

        ICard* operator[](int index);

        virtual void add(ICard* card);

        virtual void add(const vector<ICard*>& cards);

        CardCollection operator()(unsigned int start, unsigned int end);

        CardCollection operator+(CardCollection &other);

        CardCollection operator+=(CardCollection &other);

        CardCollection &operator=(const vector<ICard *> &c);

        CardCollection &operator=(const CardCollection &c);

        bool operator==(const CardCollection &other) const;

        bool operator!=(const CardCollection &other) const ;

        void erase(int index);

        [[nodiscard]] std::vector<ICard*>::const_iterator end() const;

        [[nodiscard]] std::vector<ICard*>::const_iterator begin() const;

        reverse_iterator<vector<ICard*>::iterator> rbegin();

        reverse_iterator<vector<ICard*>::iterator> rend();


        vector<ICard*> getCards();

        vector<int> getRanks();

        vector<std::string> getSuits();

        void pushBack(ICard* card);

        int size();

        void sort();

        CardCollection pop(int n);

        ICard* pop();

        bool empty() const;

        CardCollection *shuffle();


        vector<int> getUniqueRanks();

        vector<std::string> getUniqueSuits();

        void add(const CardCollection& cards);

        bool contains(ICard* card);

        bool containsRank(int rank);

        bool containsSuit(std::string suit);

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
