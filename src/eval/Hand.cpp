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
#include "utils/Counter.h"

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

    CardCollection Hand::best5(CardCollection cards) {
        return cards(2, cards.size());
    }

    bool Hand::isa() {
        throw errors::NotImplementedException();
    }

    std::unique_ptr<Hand> Hand::evaluate() {
        cout << "checking for RoyalFlush" << endl;
        unique_ptr<RoyalFlush> royalFlush = std::make_unique<RoyalFlush>(*this);
        if (royalFlush->isa()) {
            return royalFlush;
        }
        cout << "checking for StraightFlush" << endl;
        unique_ptr<StraightFlush> straightFlush = std::make_unique<StraightFlush>(*this);
        if (straightFlush->isa()) {
            return straightFlush;
        }
        cout << "checking for FourOfAKind" << endl;

        unique_ptr<FourOfAKind> fourOfAKind = std::make_unique<FourOfAKind>(*this);
        if (fourOfAKind->isa()) {
            return fourOfAKind;
        }
        cout << "checking for FullHouse" << endl;
        unique_ptr<FullHouse> fullHouse = std::make_unique<FullHouse>(*this);
        if (fullHouse->isa()) {
            return fullHouse;
        }
        cout << "checking for Flush" << endl;

        unique_ptr<Flush> flush = std::make_unique<Flush>(*this);
        if (flush->isa()) {
            return flush;
        }
        cout << "checking for Straight" << endl;

        unique_ptr<Straight> straight = std::make_unique<Straight>(*this);
        if (straight->isa()) {
            return straight;
        }
        cout << "checking for ThreeOfAKind" << endl;

        unique_ptr<ThreeOfAKind> threeOfAKind = std::make_unique<ThreeOfAKind>(*this);
        if (threeOfAKind->isa()) {
            return threeOfAKind;
        }
        cout << "checking for TwoPair" << endl;

        unique_ptr<TwoPair> twoPair = std::make_unique<TwoPair>(*this);
        if (twoPair->isa()) {
            return twoPair;
        }
        cout << "checking for Pair" << endl;
        unique_ptr<Pair> pair = std::make_unique<Pair>(*this);
        if (pair->isa()) {
            return pair;
        }
        cout << "checking for HighCard" << endl;

        unique_ptr<HighCard> highCard = std::make_unique<HighCard>(*this);
        return highCard;
    }

    /*
     * Returns true when there are @n or more
     * cards in the @Hand with the same rank.
     */
    bool Hand::checkIfNRanksInHand(int n) {
        Counter<int> counter(_cards.getRanks());
        cout << counter << endl;
        int num_greater_than_n = 0;
        for (pair<const int, int> i : counter.count()) {
            if (i.second == n)
                num_greater_than_n += 1;
        }
        return num_greater_than_n >= n;
    }


    /*
     * High card implementation
     */
    HighCard::HighCard(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {}

    CardCollection HighCard::best5(CardCollection cards) {
        return _cards(2, cards.size());
    }

    bool HighCard::isa() {
        return true;
    }

    HighCard::HighCard(const Hand &hand) : Hand(hand) {};

    /*
     * Pair implementation
     */
    Pair::Pair(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {};

    Pair::Pair(const Hand &hand) : Hand(hand) {}

    CardCollection Pair::best5(CardCollection cards) {
        if (!isa())
            return cards(0, 5);
        CardCollection best5;
        Counter<int> counter(cards.getRanks());
        std::unordered_map<int, int> count = counter.count();
        // get the rank of the card which has a pair
        int rank_of_pair = 0;

        for (pair<const int, int> i : counter.count()) {
            if (i.second == 2) {
                rank_of_pair = i.first;
                break;
            }
        }
        cout << rank_of_pair << endl;
        if (rank_of_pair == 0)
            throw std::invalid_argument("Unhelpful error message");
        std::vector<int> idx_for_delete;
        for (int i = 0; i < cards.size(); i++) {
            if (cards[i].rank == rank_of_pair) {
                Card x = cards[i];
                best5.add(x);
                idx_for_delete.push_back(i);
            }
        }
        for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
            cards.erase(*it);
        }
        cards.sort();
        best5.add(cards(2, cards.size()));
        return best5;
    }

    bool Pair::isa() {
        vector<int> x = _cards.getUniqueRanks();
        return x.size() == 6;
    }

    /*
     * Two pair implementation
     */
    TwoPair::TwoPair(const Hand &hand) : Hand(hand) {}

    TwoPair::TwoPair(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {};

    CardCollection TwoPair::best5(CardCollection cards) {
        if (!isa())
            return cards(0, 5);
        CardCollection best5;
        Counter<int> counter(cards.getRanks());
        std::unordered_map<int, int> count = counter.count();
        // get the rank of the card which has a pair
        std::vector<int> rank_of_pairs;
        for (pair<const int, int> i : counter.count()) {
            if (i.second == 2) {
                rank_of_pairs.push_back(i.first);
            }
        }
        // when we have 3 pairs, sort in ascending order and remove first element
        if (rank_of_pairs.size() == 3) {
            std::sort(rank_of_pairs.begin(), rank_of_pairs.end());
            rank_of_pairs.erase(rank_of_pairs.begin());
        }
        // Should now always have 2 pairs
        if (rank_of_pairs.size() != 2)
            throw std::invalid_argument("Unhelpful error message");
        std::vector<int> idx_for_delete;
        for (int i1 = 0; i1 < rank_of_pairs.size(); i1++) {
            for (int j = 0; j < cards.size(); j++) {
                if (cards[j].rank == rank_of_pairs[i1]) {
                    Card x = cards[j];
                    best5.add(x);
                    idx_for_delete.push_back(j);
                }
            }
        }
        cout << idx_for_delete.size() << endl;
        for (auto it = idx_for_delete.rbegin(); it != idx_for_delete.rend(); ++it) {
            cards.erase(*it);
        }
        cards.sort();
        best5.add(cards(2, cards.size()));
        return best5;
    }

    bool TwoPair::isa() {
        Counter<int> counter(_cards.getRanks());
        int num_pairs = 0;
        for (pair<const int, int> i : counter.count()) {
            if (i.second == 2)
                num_pairs += 1;
        }
        return num_pairs >= 2;
    }

    /*
     * Three of a kind implementation
     */
    ThreeOfAKind::ThreeOfAKind(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards,
                                                                                            communityCards) {};

    bool ThreeOfAKind::isa() {
        Counter<int> counter(_cards.getRanks());
        int num_trips = 0;
        for (pair<const int, int> i : counter.count()) {
            if (i.second == 3)
                num_trips += 1;
        }
        return num_trips >= 1;
    }


    CardCollection ThreeOfAKind::best5(CardCollection cards) {
        return CardCollection();
    }

    ThreeOfAKind::ThreeOfAKind(const Hand &hand) : Hand(hand) {

    }

    Straight::Straight(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection Straight::best5(CardCollection cards) {
        return CardCollection();
    }

    bool Straight::isa() {
        return false;
    }

    Straight::Straight(const Hand &hand) : Hand(hand) {

    }

    Flush::Flush(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection Flush::best5(CardCollection cards) {
        return CardCollection();
    }

    bool Flush::isa() {
        return false;
    }

    Flush::Flush(const Hand &hand) : Hand(hand) {

    }

    FullHouse::FullHouse(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection FullHouse::best5(CardCollection cards) {
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

    CardCollection FourOfAKind::best5(CardCollection cards) {
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

    CardCollection StraightFlush::best5(CardCollection cards) {
        return CardCollection();
    }

    bool StraightFlush::isa() {
        return false;
    }

    StraightFlush::StraightFlush(const Hand &hand) : Hand(hand) {

    }

    RoyalFlush::RoyalFlush(HoleCards &holeCards, CommunityCards &communityCards)
            : Hand(holeCards, communityCards) {}

    CardCollection RoyalFlush::best5(CardCollection cards) {
        return CardCollection();
    }

    bool RoyalFlush::isa() {
        return false;
    }

    RoyalFlush::RoyalFlush(const Hand &hand1) : Hand(hand1) {}

}




