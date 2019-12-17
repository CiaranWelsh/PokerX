//
// Created by CiaranWelsh on 16/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTION_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTION_H

#include <vector>
#include "Card.h"

namespace Game {

    class CardCollection {
    private:
        vector<Game::Card> _cards;

    public:
        CardCollection();

        ~CardCollection();

        CardCollection(CardCollection &other);

        explicit CardCollection(int n);

        explicit CardCollection(vector<Game::Card> &cards);

        void add(Game::Card &card);

        void add(vector<Game::Card> &cards);

        vector<Game::Card>::iterator end();

        vector<Game::Card>::iterator begin();

        friend ostream &operator<<(ostream &os, const CardCollection &c);

        Game::Card operator[](int index);

        vector<Game::Card> getCards();

//
        void pushBack(Game::Card &card);

//
        int size();

        void sort();

        CardCollection &operator=(const CardCollection &c);

        bool operator==(const CardCollection &other);

        bool operator!=(const CardCollection &other);

        static vector<Card> buildDeck();
    };
}

#include "Card.h"

#endif //POKERSIMULATIONSINCPP_CARDCOLLECTION_H
