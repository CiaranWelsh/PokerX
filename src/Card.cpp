//
// Created by CiaranWelsh on 07/12/2019.
//

#include <iostream>
#include "Card.h"
#include <algorithm> // for str::find
#include <iterator> // for str::begin, std::End

namespace Game {


    Card::Card(const Card &other) {
        rank = other.rank;
        suit = other.suit;
    }

    Card::~Card() {
    }

    Card::Card(int r, char s) {

        bool validRank = std::any_of(std::begin(this->ranks), std::end(this->ranks), [&](int i) { return i == r; });
        bool validSuit = std::any_of(std::begin(this->suits), std::end(this->suits), [&](char i) { return i == s; });
//        if (!validRank || !validSuit)
//            throw std::invalid_argument("Invalid argument " << this->ranks);

        this->suit = s;
        this->rank = r;

    }

    Card &Card::operator=(const Card &c) {
        if (this == &c)
            return *this;
        rank = c.rank;
        suit = c.suit;
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const Card &c) {
        out << "Card(" << c.rank << c.suit << ")";
        return out;
    }

    bool Game::Card::operator<(const Card &other) {
        return this->rank < other.rank;
    }

    bool Game::Card::operator<=(const Card &other) {
        if (this->rank == other.rank)
            return this->suit == other.suit;
        else
            return this->rank < other.rank;
    }

    bool Game::Card::operator>(const Card &other) {
        return this->rank > other.rank;
    }

    bool Game::Card::operator>=(const Card &other) {
        if (this->rank == other.rank)
            return this->suit == other.suit;
        else
            return this->rank > other.rank;
    }

    bool Game::Card::operator==(const Card &other) {
        return (this->rank == other.rank) && (this->suit == other.suit);
    }

    bool Game::Card::operator!=(const Card &other) {
        return !(this->operator==(other));
    }

}













