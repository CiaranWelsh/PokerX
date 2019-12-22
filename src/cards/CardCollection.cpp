//
// Created by CiaranWelsh on 16/12/2019.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "CardCollection.h"
#include "NumCpp/Random/randInt.hpp"
#include <array>
#include <chrono>
#include <ctime>
#include <valarray>
#include "Card.h"
#include <valarray>


namespace cards {

    CardCollection::CardCollection(const CardCollection &other) = default;

    CardCollection::CardCollection() = default;

    CardCollection::~CardCollection() = default;

    CardCollection::CardCollection(std::vector<Card> &cards) {
        _cards = cards;
    }


    /*
     * Constructor that takes an int @n between 1 and 52 and
     * returns a CardCollection of unique cards of size @n.
     */
    CardCollection::CardCollection(int n) {
        // error if n not between 1 and 52
        if (n < 1 || n > 52) {
            throw std::invalid_argument("n should be between "
                                        "1 and 52. Got +\"" + std::to_string(n) + "\"");
        }

        std::vector<Card> deck = CardCollection::buildDeck();
        std::vector<Card> cards;
        for (int i = 0; i < n; i++) {
            nc::NdArray<int> pick_a_card = nc::random::randInt<int>(nc::Shape(1, 1), 0, deck.size());
            Card card = deck[pick_a_card[0, 0]];
            cards.push_back(card);
            deck.erase(deck.begin() + pick_a_card[0, 0]);
        }
        this->_cards = cards;
    }

    /*
    * Select n random cards from the other cc and create new
    * CardCollection from it. Function also removes the selected cards
    * from other CardCollection
    */
    CardCollection::CardCollection(CardCollection &other, int n) {
        // error if n not between 1 and 52
        if (n < 1 || n > 52) {
            throw std::invalid_argument("n should be between "
                                        "1 and 52. Got +\"" + std::to_string(n) + "\"");
        }

        std::vector<Card> cards;
        for (int i = 0; i < n; i++) {
            nc::NdArray<int> pick_a_card = nc::random::randInt<int>(nc::Shape(1, 1), 0, other.size());
            Card card = other[pick_a_card[0, 0]];
            cards.push_back(card);
            other._cards.erase(other.begin() + pick_a_card[0, 0]);
        }
        this->_cards = cards;
    }


    void CardCollection::add(Card &card) {
        this->_cards.push_back(card);
    }

    void CardCollection::add(std::vector<Card> &cards) {
        for (const Card &c : cards) {
            this->_cards.push_back(c);
        }
    }

    std::ostream &operator<<(std::ostream &os, const CardCollection &cards) {
        if (cards.empty())
            return os << "";
        os << "[";
        for (int i = 0; i < cards._cards.size(); i++) {
            if (i == cards._cards.size() - 1)
                os << cards._cards[i] << "]";
            else
                os << cards._cards[i] << ", ";
        }
        return os;
    }

    std::vector<Card>::iterator CardCollection::end() {
        return _cards.end();
    }

    std::vector<Card>::iterator CardCollection::begin() {
        return _cards.begin();
    }

    Card CardCollection::operator[](int index) {
        return _cards[index];
    }

//    Card CardCollection::operator[](std::slice slice) {
//        return _cards[_cards.begin() + from, _cards.begin() + from + to];
//    }

    bool CardCollection::operator==(const CardCollection &other) {
        if (this->_cards.size() != other._cards.size()) {
            return false;
        }
        bool equal = true;
        for (int i = 0; i < other._cards.size(); i++) {
            if (this->_cards[i] != other._cards[i])
                equal = false;
        }
        return equal;
    }

    int CardCollection::size() {
        return _cards.size();
    }

    std::vector<Card> CardCollection::getCards() {
        return _cards;
    }

    void CardCollection::pushBack(Card &card) {
        _cards.push_back(card);

    }

    CardCollection &CardCollection::operator=(const CardCollection &c) {
        _cards = c._cards;
        return *this;
    }

    bool CardCollection::operator!=(const CardCollection &other) {
        return !(*this == other);
    }

    void CardCollection::sort() {
        std::sort(_cards.begin(), _cards.end());
    }

    vector<Card> CardCollection::buildDeck() {
        std::vector<Card> cards;
        for (int r : cards::RANKS) {
            for (const auto &s : cards::SUITS) {
                Card card = Card(r, s);
                cards.push_back(card);
            }
        }
        return cards;
    }

/*
 * Remove top card (index 0) from deck
 * and return it
 */
    CardCollection CardCollection::pop(int n) {
        CardCollection cc;
        // add cards to collection
        for (int i = 0; i < n; i++) {
            Card card = _cards[i];
            cc.add(card);
        }
        // then remove cards. Must be done this way to preserve ordering
        // that we expect.
        for (int i = 0; i < n; i++) {
            _cards.erase(_cards.begin());

        }
        return cc;
    }

/*
 * Remove top card (index 0) from deck
 * and return it
 */
    Card CardCollection::pop() {
        Card card = _cards[0];
        _cards.erase(_cards.begin());
        return card;
    }

    cards::CardCollection CardCollection::operator+(CardCollection &other) {
        for (Card card : other._cards)
            _cards.push_back(card);
        return cards::CardCollection(_cards);
    }

    cards::CardCollection CardCollection::operator+=(CardCollection &other) {
        return *this + other;
    }

    bool CardCollection::empty() const {
        return _cards.empty();
    }

    CardCollection *CardCollection::shuffle() {
        // obtain a time-based seed:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle(std::begin(_cards), std::end(_cards), e);
        return this;
    }

    CardCollection &CardCollection::operator()(unsigned int start, unsigned int end) {
        std::vector<Card> sliced = std::vector<Card>(_cards.begin() + start, _cards.begin() + start + end);
        this->_cards = sliced;
        return *this;
    }

    vector<int> CardCollection::getRanks() {
        vector<int> ranks;
        for (const Card &card: _cards) {
            int r = card.rank;
            ranks.push_back(r);
        }
        return ranks;
    }

    vector<std::string> CardCollection::getSuits() {
        vector<std::string> suits;
        for (const Card &card: _cards) {
            suits.push_back(card.suit);
        }
        return suits;

    }

    vector<int> CardCollection::getUniqueRanks() {
        vector<int> ranks = this->getRanks();
        vector<int>::iterator ip;
        ip = std::unique(ranks.begin(), ranks.begin() + ranks.size());
        ranks.resize(std::distance(ranks.begin(), ip));
        return ranks;
    }

    vector<std::string> CardCollection::getUniqueSuits() {
        vector<std::string> suits = this->getSuits();
        vector<std::string>::iterator ip;
        ip = std::unique(suits.begin(), suits.begin() + suits.size());
        suits.resize(std::distance(suits.begin(), ip));
        return suits;
    }

}








