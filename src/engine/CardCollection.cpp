//
// Created by CiaranWelsh on 16/12/2019.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <chrono>
#include <valarray>
#include <random>
#include <set>
#include "PokerX/engine/CardCollection.h"
#include "PokerX/engine/RandomNumberGenerator.h"
#include "PokerX/Error.h"
#include "pokerx_export.h"


namespace pokerx {


    CardCollection::CardCollection(std::initializer_list<ICardPtr> init)
            : cards_(init) {
        sort();
    }

    CardCollection::CardCollection(std::initializer_list<std::string> cards)
        : CardCollection(std::vector<std::string>(cards.begin(), cards.end())){
        sort();
    };


    CardCollection::CardCollection(std::vector<std::string> cards) {
        for (const auto &c: cards) {
            cards_.push_back(CardFactory(c));
        }
        sort();
    }

    CardCollection::CardCollection(std::vector<ICardPtr> cards) :
            cards_(std::move(cards)) {
        sort();
    }

//    CardCollection::CardCollection(std::initializer_list<std::string> init) {
//        for (const auto& it: init){
//            auto [rank, suit] = ICard::parseString(it);
//
//        }
//
//    }

    std::ostream &operator<<(std::ostream &os, const CardCollection &cards) {
        if (cards.empty())
            return os << "";
        os << "[";
        for (int i = 0; i < cards.cards_.size(); i++) {
            if (i == cards.cards_.size() - 1)
                os << *cards.cards_[i] << "]";
            else
                os << *cards.cards_[i] << ", ";
        }
        return os;
    }

    ICardPtr CardCollection::operator[](unsigned int index) {
        return cards_[index];
    }


    void CardCollection::add(ICardPtr card) {
        if (empty()) {
            cards_.push_back(card);
            return;
        }
        // insert into right spot to maintain ordered vector
        auto first_index_smaller_than_card = std::find_if(cards_.begin(), cards_.end(), [card](ICardPtr s) {
            return s->getRank() > card->getRank();
        });
        if (first_index_smaller_than_card == cards_.end()) // element not found
            cards_.push_back(card);
        else
            cards_.insert(first_index_smaller_than_card, card);
    }

    void CardCollection::add(const std::vector<ICardPtr> &cards) {
        for (auto &c : cards) {
            add(c);
        }
    }

    void CardCollection::add(const CardCollection &cards) {
        for (auto &c : cards) {
            add(c);
        }
    }

    std::vector<ICardPtr>::const_iterator CardCollection::end() const {
        return cards_.end();
    }

    std::vector<ICardPtr>::const_iterator CardCollection::begin() const {
        return cards_.begin();
    }


    bool CardCollection::operator==(const CardCollection &other) const {
        if (this->cards_.size() != other.cards_.size()) {
            return false;
        }
        for (int i = 0; i < other.cards_.size(); i++) {
            if (*cards_[i] != *other.cards_[i])
                return false;
        }
        return true;
    }


    bool CardCollection::operator==(const std::vector<std::string> &other) const {
        if (cards_.size() != other.size()) {
            return false;
        }
        for (int i = 0; i < size(); i++) {
            ICardPtr c = cards_[i];
            const std::string &otherCard = other[i];
            if (*c != otherCard) {
                return false;
            }
        }
        return true;
    }

    bool CardCollection::operator!=(const std::vector<std::string> &other) const {
        return !(*this == other);
    }


    int CardCollection::size() const {
        return cards_.size();
    }

    std::vector<ICardPtr> CardCollection::getCards() const {
        return cards_;
    }

    void CardCollection::pushBack(ICardPtr card) {
        cards_.push_back(card);

    }

    CardCollection &CardCollection::operator=(const CardCollection &c) = default;

    CardCollection &CardCollection::operator=(const std::vector<ICardPtr> &c) {
        cards_ = c;
        return *this;
    }

    bool CardCollection::operator!=(const CardCollection &other) const {
        return !(*this == other);
    }

    /**
     * Private, hidden, used for sorting function
     */
    bool compareCardPtrs(ICardPtr a, ICardPtr b) {
        std::unordered_map<std::string, int> suit_values;
        suit_values["C"] = 1;
        suit_values["D"] = 2;
        suit_values["H"] = 3;
        suit_values["S"] = 4;
        if (a->getRank() == b->getRank())
            return suit_values[a->getSuit()] < suit_values[b->getSuit()];
        else
            return (a->getRank() < b->getRank());
    }

    void CardCollection::sort() {
        std::sort(cards_.begin(), cards_.end(), compareCardPtrs);
    }

    CardCollection CardCollection::pop_back(int n) {
        if (n > size()) {
            const int &s = size();
            LOGIC_ERROR << "Can't pop more than " << s << " cards." << std::endl;
        }
        CardCollection cc;
        // add cards to collection
        for (int i = 0; i < n; i++) {
            cc.add(pop_back());
        }
        return cc;
    }

    CardCollection CardCollection::pop(int n) {
        if (n > size()) {
            const int &s = size();
            LOGIC_ERROR << "Can't pop more than " << s << " cards." << std::endl;
        }
        CardCollection cc;
        // add cards to collection
        int count = 0;
        while (count != n) {
            cc.add(pop());
            count++;
        }
        return cc;
    }

    ICardPtr CardCollection::pop() {
        ICardPtr card = cards_[size() - 1];
        cards_.erase(cards_.end() - 1);
        return card;
    }

    ICardPtr CardCollection::pop_back() {
        ICardPtr card = cards_[0];
        cards_.erase(cards_.begin());
        return card;
    }

    CardCollection &CardCollection::operator+(CardCollection &other) {
        for (const ICardPtr card : other.cards_)
            cards_.push_back(const_cast<ICardPtr &&>(card));
        return *this;
    }

    CardCollection &CardCollection::operator+=(CardCollection &other) {
        return *this + other;
    }

    bool CardCollection::empty() const {
        return cards_.empty();
    }

    CardCollection *CardCollection::shuffle() {
        std::shuffle(std::begin(cards_), std::end(cards_), RandomNumberGenerator::getInstance().getGenerator());
        return this;
    }

    CardCollection CardCollection::operator()(unsigned int start, unsigned int end) {
        std::vector<ICardPtr> sliced = std::vector<ICardPtr>(cards_.begin() + start, cards_.begin() + end);
        return CardCollection(sliced);
    }

    std::vector<int> CardCollection::getRanks() const {
        std::vector<int> ranks;
        for (const ICardPtr card: cards_) {
            int r = card->getRank();
            ranks.push_back(r);
        }
        return ranks;
    }

    std::vector<std::string> CardCollection::getSuits() {
        std::vector<std::string> suits;
        for (const ICardPtr card: cards_) {
            suits.push_back(card->getSuit());
        }
        return suits;
    }

    std::vector<int> CardCollection::getUniqueRanks() {
        std::vector<int> ranks = this->getRanks();
        std::vector<int>::iterator ip;
        ip = std::unique(ranks.begin(), ranks.begin() + ranks.size());
        ranks.resize(std::distance(ranks.begin(), ip));
        return ranks;
    }

    std::set<std::string> CardCollection::getUniqueSuits() {
        auto all_suits = getSuits();
        std::set suits(all_suits.begin(), all_suits.end());
        return suits;
    }

    void CardCollection::erase(int index) {
        cards_.erase(cards_.begin() + index);
    }

    std::reverse_iterator<std::vector<ICardPtr>::iterator> CardCollection::rend() {
        return cards_.rend();
    }

    std::reverse_iterator<std::vector<ICardPtr>::iterator> CardCollection::rbegin() {
        return cards_.rbegin();
    }


    bool CardCollection::contains(std::string card) {
        for (auto i : cards_) {
            if (*i == card)
                return true;
        }
        return false;
    }

    bool CardCollection::contains(ICardPtr card) {
        for (auto i : cards_) {
            if (*i == *card)
                return true;
        }
        return false;
    }

    bool CardCollection::containsRank(int rank) {
        for (auto i : getRanks()) {
            if (i == rank)
                return true;
        }
        return false;
    }

    bool CardCollection::containsSuit(const std::string &suit) {
        for (const auto &i : getSuits()) {
            if (i == suit)
                return true;
        }
        return false;
    }

    POKERX_DEPRECATED ICardPtr CardCollection::findByRank(int rank) {
        ICardPtr ptr = nullptr;
        for (auto card : cards_) {
            if (card->getRank() == rank) {
                ptr = card;
                return card;
            }
        }
        return ptr;
    };

    void CardCollection::clear() {
        cards_.clear();
    }

    CardCollection CardCollection::setDifference(CardCollection &other) const {
        other.sort();
        std::vector<ICardPtr> diff;
        std::set_difference(cards_.begin(), cards_.end(), other.begin(), other.end(),
                            std::inserter(diff, diff.begin()), compareCardPtrs);

        return CardCollection(diff);
    }

    CardCollection CardCollection::setIntersection(CardCollection &other) const {
        other.sort();
        std::vector<ICardPtr> intersect;
        std::set_intersection(begin(), end(), other.begin(), other.end(),
                              std::inserter(intersect, intersect.begin()), compareCardPtrs);
        return CardCollection(intersect);
    }

    CardCollection CardCollection::copy() {
        return CardCollection(cards_);
    }

    bool CardCollection::isUniqueSet() {
        /**
         * We cannot use the adjacent_find algorithm directly on the pointers
         * since this would check whether the pointer themselves are unique,
         * not the values being pointed to. Instead, we extract the values
         * into a vector of tuples for checking.
         */
        sort();
        using Tuple = std::tuple<int, std::string>;
        using VectorOfTuples = std::vector<Tuple>;
        VectorOfTuples vectorOfTuples;
        for (auto &i: getCards()) {
            Tuple x(i->getRank(), i->getSuit());
            vectorOfTuples.push_back(x);
        }
        bool unique = std::adjacent_find(vectorOfTuples.begin(), vectorOfTuples.end()) == vectorOfTuples.end();
        return unique;

    }

    bool CardCollection::xOfAKindIsA(int x, int how_many) const {
        CardCollection cc(getCards());
        Counter<int> counter(cc.getRanks());
        // counter for number of cards with x copies, i.e. 2 for pair, 3 for three of a kind.
        std::vector<int> num_x;
        for (auto i : counter.count()) {
            if (i.second == x)
                num_x.push_back(i.first);
        }
        // caters for situation where you have three pairs
        if (x == 2 && how_many == 2 && num_x.size() == 3)
            return true;
        return num_x.size() == how_many;
    }

    int CardCollection::getValueOfXOfAKind(int x) {
        CardCollection cc(cards_);
        Counter<int> count = Counter<int>(cc.getRanks());
        std::vector<int> val;
        for (std::pair<int, int> i : count.count()) {
            if (i.second == x) {
                val.push_back(i.first);
            }
        }
        // protect against not finding any x
        if (val.empty()) {
            return 0;
        }
        // when we have 2 pair, return the largest rank
        if (val.size() > 1) {
            return *std::max_element(val.begin(), val.end());
        } else {
            if (val.size() != 1) {
                LOGIC_ERROR << "Should only have 1" << std::endl;
            }
            return val[0];
        }
    }

    void CardCollection::insert(std::vector<ICardPtr>::const_iterator position, ICardPtr card) {
        cards_.insert(position, card);
    }

    void CardCollection::insert(std::vector<ICardPtr>::const_iterator position, std::string card) {
        cards_.insert(position, CardFactory(card));
    }

    void CardCollection::erase(const ICardPtr& card){
        int cardIdx = findCard(card);
        if (cardIdx < 0){
            return;
        } else {
            erase(cardIdx);
        }
    }

    void CardCollection::erase(const std::string& card){
        erase(CardFactory(card));
    }

    int CardCollection::findCard(ICardPtr card) {
        const std::string &suit = card->getSuit();
        const int &rank = card->getRank();
        for (int i = 0; i < size(); i++) {
            ICardPtr thisCard = cards_[i];
            if (thisCard->getSuit() == suit && thisCard->getRank() == rank) {
                return i;
            }
        }
        return -1;
    }

    int CardCollection::findCard(const std::string& card) {
        return findCard(CardFactory(card));
    }


}








