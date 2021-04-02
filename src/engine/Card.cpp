//
// Created by CiaranWelsh on 07/12/2019.
//

#include <iostream>
#include "PokerX/engine/Card.h"

namespace pokerx {

    ICard::ICard(const ICard &iCard) {
        rank_ = iCard.rank_;
        suit_ = iCard.suit_;
    }

    ICard::ICard(ICard &&iCard) noexcept {
        rank_ = std::move(iCard.rank_);
        suit_ = std::move(iCard.suit_);
    }

    ICard &ICard::operator=(const ICard &iCard) {
        if (*this != iCard){
            rank_ = iCard.rank_;
            suit_ = iCard.suit_;
        }
        return *this;
    }

    ICard &ICard::operator=(ICard &&icard) noexcept {
        if (*this != icard){
            rank_ = std::move(icard.rank_);
            suit_ = std::move(icard.suit_);
        }
        return *this;
    }

    void Card::setRank(int rank) {
        rank_ = rank;
    }

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

    void Card::setSuit(const std::string &suit) {
        suit_ = suit;
    }

    int Card::getRank() const {
        return rank_;
    }

    std::string Card::getSuit() const {
        return suit_;
    }

    ICardPtr CardFactory(std::string cardString) {
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
        auto card = std::make_unique<Card>(rank, suit);
        return card;
    }

}













