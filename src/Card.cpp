//
// Created by CiaranWelsh on 07/12/2019.
//

#include <iostream>
#include <string>
#include "Card.h"
#include "CardCollection.h"
#include <algorithm> // for str::find
#include <iterator> // for str::begin, std::End
#include <vector>
#include <boost/lexical_cast.hpp>

namespace cards {

    Card::Card(const Card &other) {
        rank = other.rank;
        suit = other.suit;
    }

    Card::~Card() = default;

    Card::Card(int r, std::string s) {
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

    bool cards::Card::operator<(const Card &other) {
        return this->rank < other.rank;
    }

    bool cards::Card::operator<=(const Card &other) {
        if (this->rank == other.rank)
            return this->suit == other.suit;
        else
            return this->rank < other.rank;
    }

    bool cards::Card::operator>(const Card &other) {
        return this->rank > other.rank;
    }

    bool cards::Card::operator>=(const Card &other) {
        if (this->rank == other.rank)
            return this->suit == other.suit;
        else
            return this->rank > other.rank;
    }

    bool cards::Card::operator==(const Card &other) {
        return (this->rank == other.rank) && (this->suit == other.suit);
    }

    bool cards::Card::operator!=(const Card &other) {
        return !(this->operator==(other));
    }

}













