//
// Created by CiaranWelsh on 08/12/2019.
//

#include <vector>
#include <memory>
#include "Hand.h"
#include "iostream"
#include "cards/CommunityCards.h"
#include "cards/HoleCards.h"
#include "Errors.h"
#include <typeinfo>

#define quote(x) #x

using namespace std;

template<typename T>
const char *getClassName(T) {
    return typeid(T).name();
}


namespace eval {

    /*
     * Hand implementation
     */
    Hand::Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) {
        _holeCards = holeCards;
        _communityCards = communityCards;
        _cards = holeCards + communityCards;
        // and sort the concatonated cards
        _cards.sort();
        name = (string) typeid(this).name();
    }

    Hand::~Hand() = default;

    Hand::Hand(const Hand &hand) {
        this->_holeCards = hand._holeCards;
        this->_communityCards = hand._communityCards;
        this->_cards = hand._cards;
        name = (string) typeid(this).name();
    }

    CommunityCards Hand::getCards() {
        return CommunityCards(_cards);
    }

    std::ostream &operator<<(std::ostream &os, const Hand &hand) {
        CardCollection best5 = hand._cards;
        os << best5;
        return os;
    }

    void Hand::shuffle() {
        _cards.shuffle();
    }

    CardCollection Hand::best5() {
        return _cards;
    }

    bool Hand::isa() {
        throw errors::NotImplementedException();
    }

    std::unique_ptr<Hand> Hand::evaluate() {
        unique_ptr<RoyalFlush> royalFlush = std::make_unique<RoyalFlush>(*this);
        if (royalFlush->isa()) {
            return royalFlush;
        }
        unique_ptr<StraightFlush> straightFlush = std::make_unique<StraightFlush>(*this);
        if (straightFlush->isa()) {
            return straightFlush;
        }
        unique_ptr<FourOfAKind> fourOfAKind = std::make_unique<FourOfAKind>(*this);
        if (fourOfAKind->isa()) {
            return fourOfAKind;
        }
        unique_ptr<FullHouse> fullHouse = std::make_unique<FullHouse>(*this);
        if (fullHouse->isa()) {
            return fullHouse;
        }
        unique_ptr<Flush> flush = std::make_unique<Flush>(*this);
        if (flush->isa()) {
            return flush;
        }
        unique_ptr<Straight> straight = std::make_unique<Straight>(*this);
        if (straight->isa()) {
            return straight;
        }
        unique_ptr<ThreeOfAKind> threeOfAKind = std::make_unique<ThreeOfAKind>(*this);
        if (threeOfAKind->isa()) {
            return threeOfAKind;
        }
        unique_ptr<Pair> pair = std::make_unique<Pair>(*this);
        if (pair->isa()) {
            return pair;
        }
        unique_ptr<HighCard> highCard = std::make_unique<HighCard>(*this);
        return highCard;
    }

    HighCard::HighCard(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {}

    CardCollection HighCard::best5() {
        return _cards(0, 5);
    }

    bool HighCard::isa() {
        return true;
    }

    HighCard::HighCard(const Hand &hand) : Hand(hand) {

    }

    Pair::Pair(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection Pair::best5() {
        if (!isa())
            return _cards(0, 5);
        cout << _cards<<endl;
        return CardCollection();
    }

    bool Pair::isa() {
        std::vector<int> ranks = _cards.getUniqueRanks();
        return ranks.size() == 6;
    }

    Pair::Pair(const Hand &hand) : Hand(hand) {

    }

    TwoPair::TwoPair(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection TwoPair::best5() {
        return CardCollection();
    }

    bool TwoPair::isa() {
        return false;
    }

    TwoPair::TwoPair(const Hand &hand) : Hand(hand) {

    }

    ThreeOfAKind::ThreeOfAKind(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection ThreeOfAKind::best5() {
        return CardCollection();
    }

    bool ThreeOfAKind::isa() {
        return false;
    }

    ThreeOfAKind::ThreeOfAKind(const Hand &hand) : Hand(hand) {

    }

    Straight::Straight(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection Straight::best5() {
        return CardCollection();
    }

    bool Straight::isa() {
        return false;
    }

    Straight::Straight(const Hand &hand) : Hand(hand) {

    }

    Flush::Flush(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection Flush::best5() {
        return CardCollection();
    }

    bool Flush::isa() {
        return false;
    }

    Flush::Flush(const Hand &hand) : Hand(hand) {

    }

    FullHouse::FullHouse(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection FullHouse::best5() {
        return CardCollection();
    }

    bool FullHouse::isa() {
        return false;
    }

    FullHouse::FullHouse(const Hand &hand) : Hand(hand) {

    }

    FourOfAKind::FourOfAKind(HoleCards &holeCards,
                             CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection FourOfAKind::best5() {
        return CardCollection();
    }

    bool FourOfAKind::isa() {
        return false;
    }

    FourOfAKind::FourOfAKind(const Hand &hand) : Hand(hand) {

    }

    StraightFlush::StraightFlush(HoleCards &holeCards,
                                 CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection StraightFlush::best5() {
        return CardCollection();
    }

    bool StraightFlush::isa() {
        return false;
    }

    StraightFlush::StraightFlush(const Hand &hand) : Hand(hand) {

    }

    RoyalFlush::RoyalFlush(HoleCards &holeCards, CommunityCards &communityCards)
            : Hand(holeCards, communityCards) {}

    CardCollection RoyalFlush::best5() {
        return CardCollection();
    }

    bool RoyalFlush::isa() {
        return false;
    }

    RoyalFlush::RoyalFlush(const Hand &hand1) : Hand(hand1) {}
}




