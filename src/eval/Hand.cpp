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
    CardCollection Hand::best5() {
        CardCollection cards = _cards;
        return best5(cards);
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
    bool Hand::xOfAKindIsA(int x, int how_many) {
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
        return xOfAKindBest5<Pair>(2);
    }

    bool Pair::isa() {
        return xOfAKindIsA(2);
    }

    /*
     * Two pair implementation
     */
    TwoPair::TwoPair(const Hand &hand) : Hand(hand) {}

    TwoPair::TwoPair(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {};

    CardCollection TwoPair::best5(CardCollection cards) {
        return xOfAKindBest5<TwoPair>(2);
    }

    bool TwoPair::isa() {
        return xOfAKindIsA(2, 2);
    }

    /*
     * Three of a kind implementation
     */
    ThreeOfAKind::ThreeOfAKind(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards,
                                                                                            communityCards) {};

    ThreeOfAKind::ThreeOfAKind(const Hand &hand) : Hand(hand) {}

    bool ThreeOfAKind::isa() {
        return xOfAKindIsA(3);
    }

    CardCollection ThreeOfAKind::best5(CardCollection cards) {
        return xOfAKindBest5<ThreeOfAKind>(3);
    }

    /*
     * Straight Implementation
     */
    Straight::Straight(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {}

    CardCollection Straight::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
        std::vector<int> ranks = _cards.getRanks();
        // three frames are possible with 5 consequative numbers in 7
        int frames[] = {0, 1, 2};

        // Deal with low aces straights
        CardCollection best5;
        if (cards[0].rank == 2 && cards[1].rank == 3 && cards[2].rank == 4 &&
            cards[3].rank == 5 && cards[6].rank == 14) {
            for (int i : {0, 1, 2, 3, 7}) {
                best5.add(cards[i]);
            }
        }

        for (int frame : frames) {
            best5.clear();
            int current_rank = ranks[frame];
            for (int i = 0; i < ranks.size(); i++) {
                int rank = ranks[i];
                if (current_rank == rank) {
                    best5.add(cards[i]);
                    current_rank++;
                }
                if (best5.size() == 5)
                    return best5;
            }
        }
        return best5;
    }

    bool Straight::isa() {
        CardCollection cards = _cards;
        std::vector<int> ranks = cards.getRanks();
        // three frames are possible with 5 consequative numbers in 7
        int frames[] = {0, 1, 2};

        // deal with low aces
        if (cards[0].rank == 2 && cards[1].rank == 3 && cards[2].rank == 4 &&
            cards[3].rank == 5 && cards[6].rank == 14) {
            return true;
        }

        CardCollection matches;
        for (int frame : frames) {
            matches.clear();
            int current_rank = ranks[frame];
            for (int i = 0; i < ranks.size(); i++) {

                int rank = ranks[i];
                if (current_rank == rank) {
                    matches.add(cards[i]);
                    current_rank++;
                }
                if (matches.size() == 5)
                    return true;
            }
        }
        return false;
    }

    Straight::Straight(const Hand &hand) : Hand(hand) {}

    Flush::Flush(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {}

    CardCollection Flush::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
        Counter<std::string> count(cards.getSuits());
        CardCollection best5;
        std::string which_suit;
        for (const std::pair<const std::string, int> &i : count.count()) {
            if (i.second == 5) {
                which_suit = i.first;
            }
        }
        for (Card card : cards)
            if (card.suit == which_suit)
                best5.add(card);
        return best5;
    }

    bool Flush::isa() {
        Counter<std::string> count(_cards.getSuits());
        bool x = false;
        for (const std::pair<const std::string, int> &i : count.count()) {
            if (i.second == 5)
                x = true;
        }
        return x;
    }

    Flush::Flush(const Hand &hand) : Hand(hand) {}

    FullHouse::FullHouse(HoleCards &holeCards, CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection FullHouse::best5(CardCollection cards) {
        Counter<int> count(cards.getRanks());
        int theThree, theTwo;
        for (std::pair<const int, int> i: count.count()) {
            if (i.second == 2)
                theTwo = i.first;
            else if (i.second == 3)
                theThree = i.first;
        }
        CardCollection best5;
        for (Card i : cards) {
            if (i.rank == theThree)
                best5.add(i);
            else if (i.rank == theTwo)
                best5.add(i);
        }
        if (best5.size() != 5)
            throw errors::BadError();

        return best5;
    }

    bool FullHouse::isa() {
        //check if pair
        Pair pair = Pair(*this);
        ThreeOfAKind three_of_a_kind = ThreeOfAKind(*this);
        return pair.isa() && three_of_a_kind.isa();
    }

    FullHouse::FullHouse(const Hand &hand) : Hand(hand) {

    }

    FourOfAKind::FourOfAKind(HoleCards &holeCards,
                             CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection FourOfAKind::best5(CardCollection cards) {
        return xOfAKindBest5<FourOfAKind>(4);
    }

    bool FourOfAKind::isa() {
        return xOfAKindIsA(4);
    }

    FourOfAKind::FourOfAKind(const Hand &hand) : Hand(hand) {

    }

    StraightFlush::StraightFlush(HoleCards &holeCards,
                                 CommunityCards &communityCards) : Hand(holeCards, communityCards) {

    }

    CardCollection StraightFlush::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();

        Counter<std::string> suit_count(_cards.getSuits());
        Counter<int> rank_count(_cards.getRanks());
        Straight straight(_cards);
        Flush flush(_cards);
        CardCollection best5 = straight.Hand::best5().set_intersection(flush.Hand::best5());
        return best5;
    }

    bool StraightFlush::isa() {
        return Straight(_cards).isa() && Flush(_cards).isa();
    }

    StraightFlush::StraightFlush(const Hand &hand) : Hand(hand) {}

    RoyalFlush::RoyalFlush(HoleCards &holeCards, CommunityCards &communityCards)
            : Hand(holeCards, communityCards) {}

    CardCollection RoyalFlush::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
        StraightFlush straight_flush(cards);
        return straight_flush.Hand::best5();
    }

    bool RoyalFlush::isa() {
        StraightFlush sflush(_cards);
        CardCollection sflushcards = sflush.Hand::best5();
        return sflush.isa() && sflushcards[0].rank == 10
               && sflushcards[1].rank == 11
               && sflushcards[2].rank == 12
               && sflushcards[3].rank == 13
               && sflushcards[4].rank == 14;
    }

    RoyalFlush::RoyalFlush(const Hand &hand1) : Hand(hand1) {}

}




