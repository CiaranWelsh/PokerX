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

using namespace std;

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

    /*
     * Check for two, three and four of a kind.
     * @x is one of 2, 3 or 4 and @how_many should
     * be 1 for @x=2, @x=3 and @x=4 for pair, three of a
     * kind and four of a kind and @how_many=2 for two pair.
     */
    bool Hand::xOfAKind(int x, int how_many) {
        Counter<int> counter(getCards().getRanks());
        // counter for number of cards with x copies, i.e. 2 for pair, 3 for three of a kind.
        int num_x = 0;
        for (pair<const int, int> i : counter.count()) {
            if (i.second == x)
                num_x += 1;
        }
        return num_x == how_many;
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

    Hand::Hand(CardCollection collection) {
        if (collection.size() != 7)
            throw std::invalid_argument("need 7 cards");
        this->_cards = collection.getCards();
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
            return CardCollection();
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
        return xOfAKind(2);
    }

    /*
     * Two pair implementation
     */
    TwoPair::TwoPair(const Hand &hand) : Hand(hand) {}

    TwoPair::TwoPair(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {};

    CardCollection TwoPair::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
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
        return xOfAKind(2, 2);
    }

    /*
     * Three of a kind implementation
     */
    ThreeOfAKind::ThreeOfAKind(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards,
                                                                                            communityCards) {};

    ThreeOfAKind::ThreeOfAKind(const Hand &hand) : Hand(hand) {}

    bool ThreeOfAKind::isa() {
        return xOfAKind(3);
    }

    CardCollection ThreeOfAKind::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
        CardCollection best5;
        Counter<int> counter(cards.getRanks());
        std::unordered_map<int, int> count = counter.count();
        // get the rank of the card which has a pair
        std::vector<int> rank_of_trips;
        for (pair<const int, int> i : counter.count()) {
            if (i.second == 3) {
                rank_of_trips.push_back(i.first);
            }
        }
        if (rank_of_trips.size() != 1)
            throw std::invalid_argument("Unhelpful error message");
        std::vector<int> idx_for_delete;
        for (int i1 = 0; i1 < rank_of_trips.size(); i1++) {
            for (int j = 0; j < cards.size(); j++) {
                if (cards[j].rank == rank_of_trips[i1]) {
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


    Straight::Straight(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {}

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
        //check if pair
        Pair pair = Pair(*this);
        cout << "pair isa: " << pair.isa() << endl;
        ThreeOfAKind three_of_a_kind = ThreeOfAKind(*this);
        cout << "toak isa: " << three_of_a_kind.isa() << endl;
        return pair.isa() && three_of_a_kind.isa();
    }

    FullHouse::FullHouse(const Hand &hand) : Hand(hand) {

    }

    FourOfAKind::FourOfAKind(HoleCards &holeCards,
                             CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection FourOfAKind::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
        CardCollection best5;
        Counter<int> counter(cards.getRanks());
        std::unordered_map<int, int> count = counter.count();
        // get the rank of the card which has a pair
        std::vector<int> rank_of_trips;
        for (pair<const int, int> i : counter.count()) {
            if (i.second == 4) {
                rank_of_trips.push_back(i.first);
            }
        }
        if (rank_of_trips.size() != 1)
            throw std::invalid_argument("Unhelpful error message");
        std::vector<int> idx_for_delete;
        for (int i1 = 0; i1 < rank_of_trips.size(); i1++) {
            for (int j = 0; j < cards.size(); j++) {
                if (cards[j].rank == rank_of_trips[i1]) {
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

    bool FourOfAKind::isa() {
        return xOfAKind(2);
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
//        return Straight(_cards).isa() && Flush(_cards).isa();
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




