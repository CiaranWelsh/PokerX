//
// Created by CiaranWelsh on 08/12/2019.
//

#include <utility>
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

    Hand::Hand(CardCollection &collection) {
        if (collection.size() != 7)
            throw std::invalid_argument("need 7 cards");
        this->_cards = collection.getCards();
        setValue();
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
        setValue();
    }

    Hand::~Hand() = default;

    Hand::Hand(Hand &hand) {
        this->_holeCards = hand._holeCards;
        this->_communityCards = hand._communityCards;
        this->_cards = hand._cards;
        _cards.sort();
        this->type = hand.getHandType();
        this->value = hand.value;
    }

    Hand::Hand(const HandPtr& hand) {
        cout << "Here 1"<< endl;
        this->_holeCards = hand->_holeCards;
        cout << "Here 2"<< endl;
        this->_communityCards = hand->_communityCards;
        cout << "Here 3"<< endl;
        this->_cards = hand->_cards;
        cout << "Here 4"<< endl;
        _cards.sort();
        cout << "Here 5"<< endl;
        name = (string) typeid(this).name();
        cout << "Here 6"<< endl;
        this->value = hand->value;
        cout << "Here 7"<< endl;
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

    std::shared_ptr<Hand> Hand::evaluate() {

        cout << "checking for RoyalFlush" << endl;
        std::shared_ptr<RoyalFlush> royalFlush = std::make_shared<RoyalFlush>(_cards);
        if (royalFlush->isa()) {
            return royalFlush;
        }
        cout << "checking for StraightFlush" << endl;
        std::shared_ptr<StraightFlush> straightFlush = std::make_shared<StraightFlush>(_cards);
        if (straightFlush->isa()) {
            return straightFlush;
        }
        cout << "checking for FourOfAKind" << endl;

        std::shared_ptr<FourOfAKind> fourOfAKind = std::make_shared<FourOfAKind>(_cards);
        if (fourOfAKind->isa()) {
            return fourOfAKind;
        }
        cout << "checking for FullHouse" << endl;
        std::shared_ptr<FullHouse> fullHouse = std::make_shared<FullHouse>(_cards);
        if (fullHouse->isa()) {
            return fullHouse;
        }
        cout << "checking for Flush" << endl;

        std::shared_ptr<Flush> flush = std::make_shared<Flush>(_cards);
        if (flush->isa()) {
            return flush;
        }
        cout << "checking for Straight" << endl;


        std::shared_ptr<Straight> straight = std::make_shared<Straight>(_cards);
        if (straight->isa()) {
            return straight;
        }
        cout << "checking for ThreeOfAKind" << endl;

        std::shared_ptr<ThreeOfAKind> threeOfAKind = std::make_shared<ThreeOfAKind>(_cards);
        if (threeOfAKind->isa()) {
            return threeOfAKind;
        }
        cout << "checking for TwoPair" << endl;

        std::shared_ptr<TwoPair> twoPair = std::make_shared<TwoPair>(_cards);
        if (twoPair->isa()) {
            return twoPair;
        }
        cout << "checking for Pair" << endl;
        std::shared_ptr<Pair> pair = std::make_shared<Pair>(_cards);
        if (pair->isa()) {
            return pair;
        }
        cout << "checking for HighCard" << endl;

        std::shared_ptr<HighCard> highCard = std::make_shared<HighCard>(_cards);
        cout << "returning a hgh card" << endl;
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
        HandType mine = evaluate()->type;
        HandType theirs = hand.evaluate()->type;
        if (mine == theirs) {
            return sumBest5Ranks() < hand.sumBest5Ranks();
        }
        return mine < theirs;
    }

    bool Hand::operator>(Hand &hand) {
        HandType mine = evaluate()->getHandType();
        HandType theirs = hand.evaluate()->getHandType();
        if (mine == theirs) {
            return sumBest5Ranks() > hand.sumBest5Ranks();
        }
        return mine > theirs;
    }


    int Hand::sumBest5Ranks() {
        cout << "Here1" << endl;
        Straight straight(_cards);
        cout << "Here2" << endl;
        StraightFlush straightFlush(_cards);
        cout << "Here3" << endl;
        std::vector<int> low_ranks = {2, 3, 4, 5, 14};
        cout << "Here4" << endl;
        CardCollection straight_best5 = straight.best5(_cards);
        cout << "Here5" << endl;
        std::vector<int> ranks_to_sum = _cards.getRanks();
        cout << "Here6" << endl;

        if (straight.isa() || straightFlush.isa()) {
            if (straight_best5.getRanks() == low_ranks) {
                ranks_to_sum = {1, 2, 3, 4, 5};
            }
        }
        cout << "Here7" << endl;
        int sum = 0;
        for (int rank : ranks_to_sum) {
            sum += rank;
        }
        cout << "Here8" << endl;
        return sum;
    }

    HandType Hand::getHandType() const {
        return type;
    }


    int Hand::getValue() {
        return value;
    }

    void Hand::setValue() {
        value = 0;
    }

    /*
     * Returns the rank of the card that has x in the hand.
     * i.e. if x was 2 and there were two 6's, you would
     * expect 2
     *
     */
    int Hand::getValueOfXOfAKind(int x) {
        Counter<int> count = Counter<int>(this->getCards().getRanks());
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
                throw errors::ValueError("Should only have 1", __FILE__, __LINE__);
            }
            return val[0];
        }
    }

    int Hand::getLargestRank() {
        int max_val = 0;
        for (int &i : best5().getRanks()){
            if (i > max_val)
                max_val = i;
        }
        return max_val;
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


    HighCard::HighCard(CardCollection &collection) : Hand(collection) {
        type = HandType::Pair_;
        setValue();

    }

    HighCard::HighCard(const HandPtr& hand) : Hand(hand) {
        type = HandType::Pair_;
        setValue();
    }

    void HighCard::setValue() {
        value = *std::max_element(
                getCards().getRanks().begin(),
                getCards().getRanks().end()
        );
    }


/*
 * Pair implementation
 */

    CardCollection Pair::best5() {
        return xOfAKindBest5<Pair>(2);
    }

    bool Pair::isa() {
        return xOfAKindIsA(2);
    }

    Pair::Pair(CardCollection &collection) : Hand(collection) {
        type = HandType::Pair_;
        setValue();
    }

    Pair::Pair(const HandPtr& hand) : Hand(hand) {
        type = HandType::Pair_;
        setValue();
    }

    void Pair::setValue() {
        value = getValueOfXOfAKind(2);
    }

/*
 * Two pair implementation
 */
    CardCollection TwoPair::best5() {
        return xOfAKindBest5<TwoPair>(2);
    }

    bool TwoPair::isa() {
        return xOfAKindIsA(2, 2);
    }

    TwoPair::TwoPair(CardCollection &collection) : Hand(collection) {
        type = HandType::TwoPair_;
        setValue();
    }

    TwoPair::TwoPair(const HandPtr& hand) : Hand(hand) {
        type = HandType::TwoPair_;
        setValue();
    }


    void TwoPair::setValue() {
        value = getValueOfXOfAKind(2);
    }


/*
 * Three of a kind implementation
 */

    bool ThreeOfAKind::isa() {
        return xOfAKindIsA(3);
    }

    CardCollection ThreeOfAKind::best5() {
        return xOfAKindBest5<ThreeOfAKind>(3);
    }

    ThreeOfAKind::ThreeOfAKind(CardCollection &collection) : Hand(collection) {
        type = HandType::ThreeOfAKind_;
        setValue();

    }

    ThreeOfAKind::ThreeOfAKind(const HandPtr& hand) : Hand(hand) {
        type = HandType::ThreeOfAKind_;
        setValue();
    }


    void ThreeOfAKind::setValue() {
        value = getValueOfXOfAKind(3);
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
            for (size_t i = 0; i < ranks.size(); i++) {
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
            for (size_t i = 0; i < ranks.size(); i++) {

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

    Straight::Straight(CardCollection &collection) : Hand(collection) {
        type = HandType::Straight_;
        setValue();
    }

    Straight::Straight(const HandPtr& hand) : Hand(hand) {
        type = HandType::Straight_;
        setValue();
    }

    void Straight::setValue() {
        value = getLargestRank();
    }

    /*
     * Flush implementation
     */

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

    Flush::Flush(CardCollection &collection) : Hand(collection) {
        type = HandType::Flush_;
        setValue();
    }

    Flush::Flush(const HandPtr& hand) : Hand(hand) {
        type = HandType::Flush_;
        setValue();
    }

    CardCollection FullHouse::best5(CardCollection cards) {
        Counter<int> count(cards.getRanks());
        int theThree = 0, theTwo = 0;
        for (std::pair<const int, int> i: count.count()) {
            if (i.second == 2)
                theTwo = i.first;
            else if (i.second == 3)
                theThree = i.first;
        }
        CardCollection best5;
        for (const Card &i : cards) {
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


    void Flush::setValue() {
        value = getLargestRank();
    }

    /*
     * FullHouse implementation
     */
    bool FullHouse::isa() {
        //check if pair
        Pair pair(_cards);
        ThreeOfAKind three_of_a_kind(_cards);
        return pair.isa() && three_of_a_kind.isa();
    }

    FullHouse::FullHouse(CardCollection &collection) : Hand(collection) {
        setValue();
        type = HandType::FullHouse_;
    }

    FullHouse::FullHouse(const HandPtr& hand) : Hand(hand) {
        type = HandType::FullHouse_;
        setValue();
    }

    void FullHouse::setValue() {
        value = getValueOfXOfAKind(3);
    }

    CardCollection FourOfAKind::best5() {
        return xOfAKindBest5<FourOfAKind>(4);
    }

    /*
     * Four of a kind implementation
     */
    bool FourOfAKind::isa() {
        return xOfAKindIsA(4);
    }

    FourOfAKind::FourOfAKind(CardCollection &collection) : Hand(collection) {
        type = HandType::FourOfAKind_;
        setValue();
    }

    FourOfAKind::FourOfAKind(const HandPtr& hand) : Hand(hand) {
        type = HandType::FourOfAKind_;
        setValue();
    }

    void FourOfAKind::setValue() {
        value = getValueOfXOfAKind(4);
    }


    /*
     * Straight flush implementation
     */

    CardCollection StraightFlush::best5() {
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

    StraightFlush::StraightFlush(CardCollection &collection) : Hand(collection) {
        type = HandType::StraightFlush_;
        setValue();
    }

    StraightFlush::StraightFlush(const HandPtr& hand) : Hand(hand) {
        setValue();
        type = HandType::StraightFlush_;
    }

    void StraightFlush::setValue() {
        value = getLargestRank();
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

    RoyalFlush::RoyalFlush(CardCollection &collection) : Hand(collection) {
        type = HandType::RoyalFlush_;
        setValue();
    }

    RoyalFlush::RoyalFlush(const HandPtr& hand) : Hand(hand) {
        setValue();
        type = HandType::RoyalFlush_;
    }

    /*
     * Technically this method is not necesasary because its
     * the highest hand you can have. If >1 player has royal flush,
     * its always a split pot
     */
    void RoyalFlush::setValue() {
        value = getLargestRank();
    }

}




