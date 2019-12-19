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
        vector<cards::Card> _cards;
    public:
        CardCollection();

        ~CardCollection();

        CardCollection(const CardCollection &other);

        explicit CardCollection(int n);

        CardCollection(CardCollection &other, int n);

        explicit CardCollection(vector<cards::Card> &cards);

        void add(cards::Card &card);

        void add(vector<cards::Card> &cards);

        vector<cards::Card>::iterator end();

        vector<cards::Card>::iterator begin();

        friend ostream &operator<<(ostream &os, const CardCollection &c);

        cards::Card operator[](int index);

        cards::CardCollection operator+(CardCollection &other);

        cards::CardCollection operator+=(CardCollection &other);

        vector<cards::Card> getCards();

        void pushBack(cards::Card &card);

        int size();

        void sort();

        CardCollection &operator=(const CardCollection &c);

        bool operator==(const CardCollection &other);

        bool operator!=(const CardCollection &other);

        static vector<Card> buildDeck();

        CardCollection pop(int n);

        Card pop();

        bool empty() const;

        CardCollection *shuffle();


    };
}

#include "Card.h"

#endif //POKERSIMULATIONSINCPP_CARDCOLLECTION_H
