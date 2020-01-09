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

    Hand::Hand(CardCollection collection) {
        if (collection.size() != 7)
            throw std::invalid_argument("need 7 cards");
        this->_cards = collection.getCards();
    }

    /*
     * Hand implementation
     */
    Hand::Hand(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) {
        _holeCards = holeCards;
        _communityCards = communityCards;
        _cards = holeCards + communityCards;
        // and sort the concatonated cards
        _cards.sort();
    }

    Hand::~Hand() = default;

    Hand::Hand(const Hand &hand) {
        this->_holeCards = hand._holeCards;
        this->_communityCards = hand._communityCards;
        this->_cards = hand._cards;
        _cards.sort();
        this->type = hand.getHandType();
    }

    Hand::Hand(Hand *hand) {
        this->_holeCards = hand->_holeCards;
        this->_communityCards = hand->_communityCards;
        this->_cards = hand->_cards;
        _cards.sort();
        name = (string) typeid(this).name();
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

    CommunityCards Hand::getCards() {
        return CommunityCards(_cards);
    }


    Hand &Hand::operator=(Hand hand) {
        if ((*this) == hand)
            return *this;
        _cards = hand._cards;
        _communityCards = hand._communityCards;
        _holeCards = hand._holeCards;
        return (*this);
    }

    Hand &Hand::operator=(Hand &&hand) noexcept {
        if ((*this) == hand)
            return *this;
        _cards = hand._cards;
        _communityCards = hand._communityCards;
        _holeCards = hand._holeCards;
        return (*this);
    }

    bool Hand::operator==(Hand &hand) {
        return this->getCards() == hand.getCards();
    }

    bool Hand::operator!=(Hand &hand) {
        return !(*this == hand);
    }

    bool Hand::operator<(Hand &hand) {
        std::unique_ptr<Hand> mine = evaluate();
        std::unique_ptr<Hand> theirs = hand.evaluate();
        return *mine > *theirs;
    }
//    bool Hand::operator<(Hand &hand) {
//        HandType mine = evaluate()->type;
//        HandType theirs = hand.evaluate()->type;
//        if (mine == theirs) {
//            return sumBest5Ranks() < hand.sumBest5Ranks();
//        }
//        return mine < theirs;
//    }

    bool Hand::operator>(Hand &hand) {
        HandType mine = getHandType();
        HandType theirs = hand.getHandType();
        cout << "mine " << mine << " sumbest5 " << sumBest5Ranks() << endl;
        cout << "theirs " << theirs << " sum " << hand.sumBest5Ranks() << endl;
        if (mine == theirs) {
            return sumBest5Ranks() > hand.sumBest5Ranks();
        }
        return mine > theirs;
    }

//    bool Hand::operator<(Hand &hand) {
//        return sumBest5Ranks() > hand.sumBest5Ranks();
//    }

    int Hand::sumBest5Ranks() {
        Straight straight(_cards);
        StraightFlush straightFlush(_cards);
        std::vector<int> low_ranks = {2, 3, 4, 5, 14};
        CardCollection straight_best5 = straight.best5(_cards);
        std::vector<int> ranks_to_sum = _cards.getRanks();

        if (straight.isa() || straightFlush.isa()) {
            if (straight_best5.getRanks() == low_ranks) {
                ranks_to_sum = {1, 2, 3, 4, 5};
            }
        }
        int sum = 0;
        for (int rank : ranks_to_sum) {
            sum += rank;
        }
        return sum;
    }

    HandType Hand::getHandType() const {
        return type;
    }

    std::map<std::string, int> Hand::handHeirachy() {
        std::vector<std::string> ranks{
                "HighCard", "Pair", "TwoPair", "ThreeOfAKind",
                "Straight", "Flush", "FullHouse", "FourOfAKind",
                "StraightFlush", "RoyalFlush"
        };
        std::map<std::string, int> hand_heirachy;
        for (int i = 0; i < ranks.size(); i++) {
            hand_heirachy[ranks[i]] = i;
        }
        return hand_heirachy;
    }


/*
 * High card implementation
 *
 *
 */

    CardCollection HighCard::best5(CardCollection cards) {
        return _cards(2, cards.size());
    }

    bool HighCard::isa() {
        return true;
    }


    HighCard::HighCard(CardCollection collection) : Hand(collection) {
        type = HandType::Pair_;
    }

    HighCard::HighCard(Hand *hand) : Hand(hand) {
        type = HandType::Pair_;
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

    Pair::Pair(CardCollection collection) : Hand(collection) {
        type = HandType::Pair_;
    }

    Pair::Pair(Hand *hand) : Hand(hand) {
        type = HandType::Pair_;
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

    TwoPair::TwoPair(CardCollection collection) : Hand(collection) {
        type = HandType::TwoPair_;
    }

    TwoPair::TwoPair(Hand *hand) : Hand(hand) {
        type = HandType::TwoPair_;
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
    ThreeOfAKind::ThreeOfAKind(CardCollection collection) : Hand(collection) {
        type = HandType::ThreeOfAKind_;
    }

    ThreeOfAKind::ThreeOfAKind(Hand *hand) : Hand(hand) {
        type = HandType::ThreeOfAKind_;
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

    Straight::Straight(CardCollection collection) : Hand(collection) {
        type = HandType::Straight_;
    }

    Straight::Straight(Hand *hand) : Hand(hand) {
        type = HandType::Straight_;
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
        for (const Card &card : cards) {
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
    Flush::Flush(CardCollection collection) : Hand(collection) {
        type = HandType::Flush_;
    }

    Flush::Flush(Hand *hand) : Hand(hand) {
        type = HandType::Flush_;
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
        for (const Card& i : cards) {
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
        Pair pair((*this).getCards());
        ThreeOfAKind three_of_a_kind((*this).getCards());
        return pair.isa() && three_of_a_kind.isa();
    }
    FullHouse::FullHouse(CardCollection collection) : Hand(collection) {
        type = HandType::FullHouse_;
    }

    FullHouse::FullHouse(Hand *hand) : Hand(hand) {
        type = HandType::FullHouse_;
    }


    CardCollection FourOfAKind::best5(CardCollection cards) {
        return xOfAKindBest5<FourOfAKind>(4);
    }

    bool FourOfAKind::isa() {
        return xOfAKindIsA(4);
    }

    FourOfAKind::FourOfAKind(CardCollection collection) : Hand(collection) {
        type = HandType::FourOfAKind_;
    }

    FourOfAKind::FourOfAKind(Hand *hand) : Hand(hand) {
        type = HandType::FourOfAKind_;
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

    StraightFlush::StraightFlush(CardCollection collection) : Hand(collection) {
        type = HandType::StraightFlush_;
    }

    StraightFlush::StraightFlush(Hand *hand) : Hand(hand) {
        type = HandType::StraightFlush_;
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

    RoyalFlush::RoyalFlush(CardCollection collection) : Hand(collection) {
        type = HandType::RoyalFlush_;
    }

    RoyalFlush::RoyalFlush(Hand *hand) : Hand(hand) {
        type = HandType::RoyalFlush_;
    }

}




