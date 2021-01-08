//
// Created by CiaranWelsh on 07/12/2019.
//

#include <iostream>
#include "Card.h"
#include <iterator> //
#include <utility>

namespace cards {

    Card::Card(int r, std::string s) : ICard(r, std::move(s)){}

    std::ostream &operator<<(std::ostream &out, const ICard &c) {
        out << "Card(" << c.rank_ << c.suit_ << ")";
        return out;
    }

    bool ICard::operator<(const ICard &other) const {
        return this->rank_ < other.rank_;
    }

    bool ICard::operator<=(const ICard &other) const {
        return rank_ <= other.rank_;
    }

    bool ICard::operator>(const ICard &other) const {
        return this->rank_ > other.rank_;
    }

    bool ICard::operator>=(const ICard &other) const {
        return rank_ >= other.rank_;
    }

    bool ICard::operator==(const ICard &other) const {
        return (this->rank_ == other.rank_) && (this->suit_ == other.suit_);
    }

    bool ICard::operator!=(const ICard &other) const {
        return !(operator==(other));
    }

    int Card::getRank() const {
        return rank_;
    }

    std::string Card::getSuit() const {
        return suit_;
    }

}













