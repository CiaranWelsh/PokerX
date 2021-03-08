//
// Created by CiaranWelsh on 07/12/2019.
//

#include <iostream>
#include "PokerX/engine/Card.h"

namespace pokerx {

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

    void Card::setRank(int rank) {
        rank_ = rank;
    }

    void Card::setSuit(const std::string &suit) {
        suit_ = suit;
    }

    int Card::getRank() const {
        return rank_;
    }

    std::string Card::getSuit() const {
        return suit_;
    }

    ICard* CardFactory(std::string cardString) {
        char c = cardString[cardString.size()-1];
        std::string suit = {static_cast<char>(std::toupper((int)(c)))};
        cardString.pop_back();
        int rank;
        try {
            // for numbers, we can convert to int
            rank = std::stoi(cardString);
        } catch (std::exception &e) { // not sure which
            // for Q, K, J, A, we need different strategy
            if (cardString == "A" || cardString == "a") {
                rank = 14;
            } else if (cardString == "K" || cardString == "k") {
                rank = 13;
            } else if (cardString == "Q" || cardString == "q") {
                rank = 12;
            } else if (cardString == "J" || cardString == "j") {
                rank = 11;
            } else if (cardString == "T" || cardString == "t") {
                rank = 10;
            }
        }
        return new Card(rank, suit);
    }

}













