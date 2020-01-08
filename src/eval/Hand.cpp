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
        return best5(_cards);
    }

    bool Hand::isa() {
        throw errors::NotImplementedException("Member function Hand::isa is not implemented", __FILE__, __LINE__);
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
        unique_ptr<RoyalFlush> royalFlush = std::make_unique<RoyalFlush>(_cards);
        if (royalFlush->isa()) {
            return royalFlush;
        }
        cout << "checking for StraightFlush" << endl;
        unique_ptr<StraightFlush> straightFlush = std::make_unique<StraightFlush>(_cards);
        if (straightFlush->isa()) {
            return straightFlush;
        }
        cout << "checking for FourOfAKind" << endl;

        unique_ptr<FourOfAKind> fourOfAKind = std::make_unique<FourOfAKind>(_cards);
        if (fourOfAKind->isa()) {
            return fourOfAKind;
        }
        cout << "checking for FullHouse" << endl;
        unique_ptr<FullHouse> fullHouse = std::make_unique<FullHouse>(_cards);
        if (fullHouse->isa()) {
            return fullHouse;
        }
        cout << "checking for Flush" << endl;

        unique_ptr<Flush> flush = std::make_unique<Flush>(_cards);
        if (flush->isa()) {
            return flush;
        }
        cout << "checking for Straight" << endl;


        unique_ptr<Straight> straight = std::make_unique<Straight>(_cards);
        if (straight->isa()) {
            return straight;
        }
        cout << "checking for ThreeOfAKind" << endl;

        unique_ptr<ThreeOfAKind> threeOfAKind = std::make_unique<ThreeOfAKind>(_cards);
        if (threeOfAKind->isa()) {
            return threeOfAKind;
        }
        cout << "checking for TwoPair" << endl;

        unique_ptr<TwoPair> twoPair = std::make_unique<TwoPair>(_cards);
        if (twoPair->isa()) {
            return twoPair;
        }
        cout << "checking for Pair" << endl;
        unique_ptr<Pair> pair = std::make_unique<Pair>(_cards);
        if (pair->isa()) {
            return pair;
        }
        cout << "checking for HighCard" << endl;

        unique_ptr<HighCard> highCard = std::make_unique<HighCard>(_cards);
        return highCard;
    }

//    Hand Hand::evaluate(const std::vector<Hand>& hands) {
//        return ;
//    }

    Hand::Hand(CardCollection collection) {
        if (collection.size() != 7)
            throw std::invalid_argument("need 7 cards");
        this->_cards = collection.getCards();
    }

    Hand &Hand::operator=(Hand &hand) {
        if ((*this) == hand)
            return *this;
        _cards = hand._cards;
        _communityCards = hand._communityCards;
        _holeCards = hand._holeCards;
        return (*this);
    }

    Hand::Hand(Hand *hand) {
        _cards = hand->_cards;
        _communityCards = hand->_communityCards;
        _holeCards = hand->_holeCards;
    }

    bool Hand::operator==(Hand &hand) {
        return this->getCards() == hand.getCards();
    }

    bool Hand::operator!=(Hand &hand) {
        return !(*this == hand);
    }

    /*
     * High card implementation
     */

    CardCollection HighCard::best5(CardCollection cards) {
        return _cards(2, cards.size());
    }

    bool HighCard::isa() {
        return true;
    }

    /*
     * Pair implementation
     */

    CardCollection Pair::best5(CardCollection cards) {
        return xOfAKindBest5<Pair>(2);
    }

    bool Pair::isa() {
        return xOfAKindIsA(2);
    }

    /*
     * Two pair implementation
     */
    CardCollection TwoPair::best5(CardCollection cards) {
        return xOfAKindBest5<TwoPair>(2);
    }

    bool TwoPair::isa() {
        return xOfAKindIsA(2, 2);
    }

    /*
     * Three of a kind implementation
     */

    bool ThreeOfAKind::isa() {
        return xOfAKindIsA(3);
    }

    CardCollection ThreeOfAKind::best5(CardCollection cards) {
        return xOfAKindBest5<ThreeOfAKind>(3);
    }

    /*
     * Straight Implementation
     */

    CardCollection Straight::best5(CardCollection cards) {
        if (!isa()) {
            return CardCollection();
        }
        std::vector<int> ranks = _cards.getRanks();
        // three frames are possible with 5 consequative numbers in 7
        int frames[] = {0, 1, 2};

        // Deal with low aces straights
        CardCollection best5_ace_low;
        if (cards[0].rank == 2 && cards[1].rank == 3 && cards[2].rank == 4 &&
            cards[3].rank == 5 && cards[6].rank == 14) {
            for (int i : {0, 1, 2, 3, 6}) {
                best5_ace_low.add(cards[i]);
            }
        }

        CardCollection best5;
        for (int frame : frames) {
            CardCollection best5_temp;
            best5_temp.clear();
            int current_rank = ranks[frame];
            for (int i = 0; i < ranks.size(); i++) {
                int rank = ranks[i];
                if (current_rank == rank) {
                    best5_temp.add(cards[i]);
                    current_rank++;
                }
                if (best5_temp.size() == 5) {
                    best5 = best5_temp.copy(); // will be replaced with a higher ranking straight if necessary
                }
            }
        }
//        cout << "All cards: " << _cards << endl;
//        cout << "best5 ace low: " << best5_ace_low << endl;
//        cout << "best5: " << best5 << endl;
        if (best5.size() == 5 && best5_ace_low.size() != 5) {
//            cout << "here1: " <<  best5 << "here" << best5_ace_low << endl;
            return best5;
        } else if (best5.size() != 5 && best5_ace_low.size() == 5)
            return best5_ace_low;
        else if (best5.size() == 5 && best5_ace_low.size() == 5) {
            return best5; // every other type of straight will beat an Ace low straight
        } else {
            throw errors::BadError("You did a bad", __FILE__, __LINE__);
        }
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

    CardCollection Flush::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
        Counter<std::string> count(cards.getSuits());
        CardCollection best5;
        std::string which_suit;
        for (const std::pair<const std::string, int> &i : count.count()) {
            if (i.second >= 5) {
                which_suit = i.first;
            }
        }
        for (const Card& card : cards) {
            if (card.suit == which_suit)
                best5.add(card);
        }
        if (best5.size() > 5) {
            best5 = best5(best5.size() - 5, best5.size());
        }
        return best5;
    }

    bool Flush::isa() {
        Counter<std::string> count(_cards.getSuits());
        bool x = false;
        for (const std::pair<const std::string, int> &i : count.count()) {
            if (i.second >= 5)
                x = true;
        }
        return x;
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
            throw errors::BadError("The best 5 cards do not have 5 cards in the "
                                   "CardCollection", __FILE__, __LINE__);

        return best5;
    }

    bool FullHouse::isa() {
        //check if pair
        Pair pair = Pair((*this).getCards());
        ThreeOfAKind three_of_a_kind = ThreeOfAKind((*this).getCards());
        return pair.isa() && three_of_a_kind.isa();
    }


    CardCollection FourOfAKind::best5(CardCollection cards) {
        return xOfAKindBest5<FourOfAKind>(4);
    }

    bool FourOfAKind::isa() {
        return xOfAKindIsA(4);
    }

    CardCollection StraightFlush::best5(CardCollection cards) {
        if (!isa())
            return CardCollection();
        Straight straight(_cards);
        /*
         * we can directly return the straight here, since we have already checked
         * that we have a straight flush. The straight returns the highest 5 cards
         * in a row and all must be the same suit or we would have already returned empty CardCollection
         */
        return straight.Hand::best5();
    }

    bool StraightFlush::isa() {
        bool straight = Straight(_cards).isa();
        bool flush = Flush(_cards).isa();
//        cout << "Straight: "<< straight << " flush: " << flush << endl;
        return straight && flush;
    }

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
}




