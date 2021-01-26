//
// Created by CiaranWelsh on 08/12/2019.
//

#include <utility>
#include <vector>
#include <memory>
#include "PokerX/engine/hands/Hand.old.h"
#include "iostream"
#include "PokerX/engine/CommunityCards.h"
#include "PokerX/engine/HoleCards.h"
#include "PokerX/Error.h"
#include "PokerX/engine/Counter.h"

using namespace std;

namespace pokerx {

//    Hand::Hand() : RestrictedCardCollection(7) {}
//
//    const CardCollection &Hand::getCards() const {
//        return cards_;
//    }
//
//    void Hand::setCards(const CardCollection &cards) {
//        cards_ = cards;
//    }

//    Hand.old::Hand.old(CardCollection &collection) {
//        if (collection.size() != 7) {
//            throw std::invalid_argument("need 7 cards");
//        }
//        this->cards_ = collection.getCards();
//        setValue();
//    }
//
//    /*
//     * Hand.old implementation
//     */
//    Hand.old::Hand.old(HoleCards holeCards, cards::CommunityCards &communityCards) {
//        holeCards = holeCards;
//        communityCards = communityCards;
//        cards_ = holeCards + communityCards;
//        // and sort the concatonated cards
//        cards_.sort();
//        setValue();
//    }
//
//    Hand.old::Hand.old.old() = default;
//
//    Hand.old::Hand.old(Hand.old &hand) {
//        holeCards = hand.holeCards;
//        communityCards = hand.communityCards;
//        cards_ = hand.cards_;
//        cards_.sort();
//        type = hand.getHandType();
//        value = hand.value;
//    }
//
//    Hand.old::Hand.old(Hand.old *hand) {
//
//        this->holeCards = hand->holeCards;
//        this->communityCards = hand->communityCards;
//        this->cards_ = hand->cards_;
//        cards_.sort();
//        name = (string) typeid(this).name();
//        this->value = hand->value;
//    }
//
//
//    std::ostream &operator<<(std::ostream &os, const Hand.old &hand) {
//        CardCollection best5 = hand.cards_;
//        os << best5;
//        return os;
//    }
//
//    void Hand.old::shuffle() {
//        cards_.shuffle();
//    }
//
//    CardCollection Hand.old::best5() {
//        return cards_(2, cards_.size());
//    }
//
//    bool Hand.old::isa() {
//        throw errors::NotImplementedException("Member function Hand.old::isa is not implemented", __FILE__, __LINE__);
//    }
//
//    /*
//     * Check for two, three and four of a kind.
//     * @x is one of 2, 3 or 4 and @how_many should
//     * be 1 for @x=2, @x=3 and @x=4 for pair, three of a
//     * kind and four of a kind and @how_many=2 for two pair.
//     */
//    bool Hand.old::xOfAKindIsA(int x, int how_many) {
//        Counter<int> counter(getCards().getRanks());
//        // counter for number of cards with x copies, i.e. 2 for pair, 3 for three of a kind.
//        std::vector<int> num_x;
//        for (pair<const int, int> i : counter.count()) {
//            if (i.second == x)
//                num_x.push_back(i.first);
//        }
//        // caters for situation where you have three pairs
//        if (x == 2 && how_many == 2 && num_x.size() == 3)
//            return true;
//        return num_x.size() == how_many;
//    }
//
//    std::shared_ptr<Hand.old> Hand.old::evaluate() {
////        cout << "checking for RoyalFlush" << endl;
//        CardCollection cards = getCards();
//        RoyalFlush royalFlush(cards);
//        std::shared_ptr<RoyalFlush> royalFlushPtr = std::make_shared<RoyalFlush>(&royalFlush);
//        if (royalFlushPtr->isa()) {
//            return royalFlushPtr;
//        }
////        cout << "checking for StraightFlush" << endl;
//        std::shared_ptr<StraightFlush> straightFlush = std::make_shared<StraightFlush>(cards_);
//        if (straightFlush->isa()) {
//            return straightFlush;
//        }
////        cout << "checking for FourOfAKind" << endl;
//
//        std::shared_ptr<FourOfAKind> fourOfAKind = std::make_shared<FourOfAKind>(cards_);
//        if (fourOfAKind->isa()) {
//            return fourOfAKind;
//        }
////        cout << "checking for FullHouse" << endl;
//        std::shared_ptr<FullHouse> fullHouse = std::make_shared<FullHouse>(cards_);
//        if (fullHouse->isa()) {
//            return fullHouse;
//        }
////        cout << "checking for Flush" << endl;
//
//        std::shared_ptr<Flush> flush = std::make_shared<Flush>(cards_);
//        if (flush->isa()) {
//            return flush;
//        }
////        cout << "checking for Straight" << endl;
//
//
//        std::shared_ptr<Straight> straight = std::make_shared<Straight>(cards_);
//        if (straight->isa()) {
//            return straight;
//        }
////        cout << "checking for ThreeOfAKind" << endl;
//
//        std::shared_ptr<ThreeOfAKind> threeOfAKind = std::make_shared<ThreeOfAKind>(cards_);
//        if (threeOfAKind->isa()) {
//            return threeOfAKind;
//        }
////        cout << "checking for TwoPair" << endl;
//
//        std::shared_ptr<TwoPair> twoPair = std::make_shared<TwoPair>(cards_);
//        if (twoPair->isa()) {
//            return twoPair;
//        }
////        cout << "checking for Pair" << endl;
//        std::shared_ptr<Pair> pair = std::make_shared<Pair>(cards_);
//        if (pair->isa()) {
//            return pair;
//        }
////        cout << "checking for HighCard" << endl;
//
//        std::shared_ptr<HighCard> highCard = std::make_shared<HighCard>(cards_);
////        cout << "returning a high card" << endl;
//        return highCard;
//    }
//
//    CommunityCards Hand.old::getCards() {
//        return CommunityCards(cards_);
//    }
//
//
//    Hand.old &Hand.old::operator=(Hand.old hand) {
//        if ((*this) == hand)
//            return *this;
//        cards_ = hand.cards_;
//        communityCards = hand.communityCards;
//        holeCards = hand.holeCards;
//        value = hand.value;
//        return (*this);
//    }
//
//    Hand.old &Hand.old::operator=(Hand.old &&hand) noexcept {
//        if ((*this) == hand)
//            return *this;
//        cards_ = hand.cards_;
//        communityCards = hand.communityCards;
//        holeCards = hand.holeCards;
//        value = hand.value;
//        type = hand.type;
//        return (*this);
//    }
//
//    Hand.old::Hand.old(Hand.old &&hand) noexcept {
//        cards_ = hand.cards_;
//        communityCards = hand.communityCards;
//        holeCards = hand.holeCards;
//        value = hand.value;
//        type = hand.type;
//    }
//
//    bool Hand.old::operator==(Hand.old &hand) {
//        return this->getCards() == hand.getCards();
//    }
//
//    bool Hand.old::operator!=(Hand.old &hand) {
//        return !(*this == hand);
//    }
//
//    bool Hand.old::operator<(Hand.old &hand) {
//        eHandType mine = evaluate()->type;
//        eHandType theirs = hand.evaluate()->type;
//        if (mine == theirs) {
//            return value < hand.value;
//        }
//        return mine < theirs;
//    }
//
//    bool Hand.old::operator>(Hand.old &hand) {
//        eHandType mine = evaluate()->getHandType();
//        eHandType theirs = hand.evaluate()->getHandType();
//        if (mine == theirs) {
//            return value > hand.value;
//        }
//        return mine > theirs;
//    }
//
//
//    int Hand.old::sumBest5Ranks() {
//        Straight straight(cards_);
//        StraightFlush straightFlush(cards_);
//        std::vector<int> low_ranks = {2, 3, 4, 5, 14};
//        CardCollection straight_best5 = straight.best5();
//        std::vector<int> ranks_to_sum = cards_.getRanks();
//
//        if (straight.isa() || straightFlush.isa()) {
//            if (straight_best5.getRanks() == low_ranks) {
//                ranks_to_sum = {1, 2, 3, 4, 5};
//            }
//        }
//        int sum = 0;
//        for (int rank : ranks_to_sum) {
//            sum += rank;
//        }
//        return sum;
//    }
//
//    eHandType Hand.old::getHandType() const {
//        return type;
//    }
//
//
//    int Hand.old::getValue() {
//        return value;
//    }
//
//    void Hand.old::setValue() {
//        value = 0;
//    }
//
//    /*
//     * Returns the rank of the card that has x in the hand.
//     * i.e. if x was 2 and there were two 6's, you would
//     * expect 2
//     *
//     */
//    int Hand.old::getValueOfXOfAKind(int x) {
//        Counter<int> count = Counter<int>(this->getCards().getRanks());
//        std::vector<int> val;
//        for (std::pair<int, int> i : count.count()) {
//            if (i.second == x) {
//                val.push_back(i.first);
//            }
//        }
//        // protect against not finding any x
//        if (val.empty()) {
//            return 0;
//        }
//        // when we have 2 pair, return the largest rank
//        if (val.size() > 1) {
//            return *std::max_element(val.begin(), val.end());
//        } else {
//            if (val.size() != 1) {
//                throw errors::ValueError("Should only have 1", __FILE__, __LINE__);
//            }
//            return val[0];
//        }
//    }
//
//    int Hand.old::getLargestRank() {
//        int max_val = 0;
//        for (int &i : best5().getRanks()) {
//            if (i > max_val)
//                max_val = i;
//        }
//        return max_val;
//    }
//
//
///*
// * High card implementation
// *
// *
// */
//
//    HighCard::HighCard(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                                  communityCards) {
//        setValue();
//        type = eHandType::HighCard_;
//    }
//
//    HighCard::HighCard(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::HighCard_;
//    }
//
//    HighCard::HighCard(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::HighCard_;
//    }
//
//    HighCard::HighCard(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::HighCard_;
//    }
//
//    HighCard::HighCard(Hand.old &&hand) noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::HighCard_;
//    }
//
//
//    CardCollection HighCard::best5() {
//        return cards_(2, cards_.size());
//    }
//
//    bool HighCard::isa() {
//        return true;
//    }
//
//    void HighCard::setValue() {
//        int max = 0;
//        for (auto i: getCards().getRanks()){
//            if (i > max)
//                i = max;
//        }
//        value = max;
//    }
//
//    Pair::Pair(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards, communityCards) {
//        setValue();
//        type = eHandType::Pair_;
//    }
//
//    Pair::Pair(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::Pair_;
//    }
//
//    Pair::Pair(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::Pair_;
//    }
//
//    Pair::Pair(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::Pair_;
//    }
//
//    Pair::Pair(Hand.old &&hand) noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::Pair_;
//    }
//
//    void Pair::setValue() {
//        value = getValueOfXOfAKind(2);
//    }
//
//    bool Pair::isa() {
//        return xOfAKindIsA(2);
//    }
//
//    CardCollection Pair::best5() {
//        return xOfAKindBest5<Pair>(2);
//    }
//
//
///*
// * Two pair implementation
// */
//
//
//
//
//    TwoPair::TwoPair(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                                communityCards) {
//        setValue();
//        type = eHandType::TwoPair_;
//    }
//
//    TwoPair::TwoPair(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::TwoPair_;
//    }
//
//    TwoPair::TwoPair(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::TwoPair_;
//    }
//
//    TwoPair::TwoPair(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::TwoPair_;
//    }
//
//
//    TwoPair::TwoPair(Hand.old &&hand) noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::TwoPair_;
//    }
//
//    CardCollection TwoPair::best5() {
//        return xOfAKindBest5<TwoPair>(2);
//    }
//
//    bool TwoPair::isa() {
//        return xOfAKindIsA(2, 2);
//    }
//
//    void TwoPair::setValue() {
//        value = getValueOfXOfAKind(2);
//    }
//
//
///*
// * Three of a kind implementation
// */
//    ThreeOfAKind::ThreeOfAKind(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                                          communityCards) {
//        setValue();
//        type = eHandType::ThreeOfAKind_;
//    }
//
//    ThreeOfAKind::ThreeOfAKind(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::ThreeOfAKind_;
//    }
//
//    ThreeOfAKind::ThreeOfAKind(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::ThreeOfAKind_;
//    }
//
//    ThreeOfAKind::ThreeOfAKind(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::ThreeOfAKind_;
//    }
//
//
//    ThreeOfAKind::ThreeOfAKind(Hand.old &&hand) noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::ThreeOfAKind_;
//    }
//
//    bool ThreeOfAKind::isa() {
//        return xOfAKindIsA(3);
//    }
//
//    CardCollection ThreeOfAKind::best5() {
//        return xOfAKindBest5<ThreeOfAKind>(3);
//    }
//
//    void ThreeOfAKind::setValue() {
//        value = getValueOfXOfAKind(3);
//    }
//
//
///*
// * Straight Implementation
// */
//
//    Straight::Straight(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                                  communityCards) {
//        setValue();
//        type = eHandType::Straight_;
//    }
//
//    Straight::Straight(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::Straight_;
//    }
//
//    Straight::Straight(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::Straight_;
//    }
//
//    Straight::Straight(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::Straight_;
//    }
//
//
//    Straight::Straight(Hand.old &&hand) noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::Straight_;
//    }
//
//    CardCollection Straight::best5() {
//        if (!isa()) {
//            return CardCollection();
//        }
//        std::vector<int> ranks = cards_.getRanks();
//        // three frames are possible with 5 consequative numbers in 7
//        int frames[] = {0, 1, 2};
//
//        // Deal with low aces straights
//        CardCollection best5_ace_low;
//        if (cards_[0].getRank() == 2 && cards_[1].getRank() == 3 && cards_[2].getRank() == 4 &&
//            cards_[3].getRank() == 5 && cards_[6].getRank() == 14) {
//            for (int i : {0, 1, 2, 3, 6}) {
//                best5_ace_low.add(cards_[i]);
//            }
//        }
//
//        CardCollection best5;
//        for (int frame : frames) {
//            CardCollection best5_temp;
//            best5_temp.clear();
//            int current_rank = ranks[frame];
//            for (size_t i = 0; i < ranks.size(); i++) {
//                int rank = ranks[i];
//                if (current_rank == rank) {
//                    best5_temp.add(cards_[i]);
//                    current_rank++;
//                }
//                if (best5_temp.size() == 5) {
//                    best5 = best5_temp.copy(); // will be replaced with a higher ranking straight if necessary
//                }
//            }
//        }
//        if (best5.size() == 5 && best5_ace_low.size() != 5) {
//            return best5;
//        } else if (best5.size() != 5 && best5_ace_low.size() == 5)
//            return best5_ace_low;
//        else if (best5.size() == 5 && best5_ace_low.size() == 5) {
//            return best5; // every other type of straight will beat an Ace low straight
//        } else {
//            throw errors::BadError("You did a bad", __FILE__, __LINE__);
//        }
//    }
//
//    bool Straight::isa() {
//        CardCollection cards = cards_;
//        std::vector<int> ranks = cards.getRanks();
//        // three frames are possible with 5 consequative numbers in 7
//        int frames[] = {0, 1, 2};
//
//        // deal with low aces
//        if (cards[0].getRank() == 2 && cards[1].getRank() == 3 && cards[2].getRank() == 4 &&
//            cards[3].getRank() == 5 && cards[6].getRank() == 14) {
//            return true;
//        }
//
//        CardCollection matches;
//        for (int frame : frames) {
//            matches.clear();
//            int current_rank = ranks[frame];
//            for (size_t i = 0; i < ranks.size(); i++) {
//
//                int rank = ranks[i];
//                if (current_rank == rank) {
//                    matches.add(cards[i]);
//                    current_rank++;
//                }
//                if (matches.size() == 5)
//                    return true;
//            }
//        }
//        return false;
//    }
//
//    void Straight::setValue() {
//        // protect against trying to access empty CardCollection
//        if (best5().empty()) {
//            value = 0;
//        } else {
//            // when we have a low straight, replace ace with value 1
//            std::vector<int> ranks = best5().getRanks();
//            if (
//                    ranks[0] == 2 &&
//                    ranks[1] == 3 &&
//                    ranks[2] == 4 &&
//                    ranks[3] == 5 &&
//                    ranks[4] == 14) {
//                value = 5;
//            } else {
//                value = getLargestRank();
//            }
//        }
//    }
//
//    /*
//     * Flush implementation
//     */
//    Flush::Flush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                            communityCards) {
//        setValue();
//        type = eHandType::Flush_;
//    }
//
//    Flush::Flush(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::Flush_;
//    }
//
//    Flush::Flush(Hand.old
//                 *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::Flush_;
//    }
//
//    Flush::Flush(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::Flush_;
//    }
//
//    Flush::Flush(Hand.old &&hand)
//    noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::Flush_;
//    }
//
//    CardCollection Flush::best5() {
//        if (!isa())
//            return CardCollection();
//        Counter<std::string> count(cards_.getSuits());
//        CardCollection best5;
//        std::string which_suit;
//        for (const std::pair<const std::string, int> &i : count.count()) {
//            if (i.second >= 5) {
//                which_suit = i.first;
//            }
//        }
//        for (const Card &card : cards_) {
//            if (card.getSuit() == which_suit)
//                best5.add(card);
//        }
//        if (best5.size() > 5) {
//            best5 = best5(best5.size() - 5, best5.size());
//        }
//        return best5;
//    }
//
//    bool Flush::isa() {
//        Counter<std::string> count(cards_.getSuits());
//        bool x = false;
//        for (const std::pair<const std::string, int> &i : count.count()) {
//            if (i.second >= 5)
//                x = true;
//        }
//        return x;
//    }
//
//    void Flush::setValue() {
//        value = getLargestRank();
//    }
//
//
//    FullHouse::FullHouse(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                                    communityCards) {
//        setValue();
//        type = eHandType::FullHouse_;
//    }
//
//    FullHouse::FullHouse(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::FullHouse_;
//    }
//
//    FullHouse::FullHouse(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::FullHouse_;
//    }
//
//    FullHouse::FullHouse(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::FullHouse_;
//    }
//
//    FullHouse::FullHouse(Hand.old &&hand)
//    noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::FullHouse_;
//    }
//
//    CardCollection FullHouse::best5() {
//        Counter<int> count(cards_.getRanks());
//        int theThree = 0, theTwo = 0;
//        for (std::pair<const int, int> i: count.count()) {
//            if (i.second == 2)
//                theTwo = i.first;
//            else if (i.second == 3)
//                theThree = i.first;
//        }
//        CardCollection best5;
//        for (const Card &i : cards_) {
//            if (i.getRank() == theThree)
//                best5.add(i);
//            else if (i.getRank() == theTwo)
//                best5.add(i);
//        }
//        if (best5.size() != 5)
//            throw errors::BadError("The best 5 cards do not have 5 cards in the "
//                                   "CardCollection", __FILE__, __LINE__);
//
//        return best5;
//    }
//
//    void FullHouse::setValue() {
//        value = getValueOfXOfAKind(3);
//    }
//
//    bool FullHouse::isa() {
//        //check if pair
//        Pair pair(cards_);
//        ThreeOfAKind three_of_a_kind(cards_);
//        return pair.isa() && three_of_a_kind.isa();
//    }
//
//
//    FourOfAKind::FourOfAKind(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                                        communityCards) {
//        setValue();
//        type = eHandType::FourOfAKind_;
//    }
//
//
//    FourOfAKind::FourOfAKind(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::FourOfAKind_;
//    }
//
//    FourOfAKind::FourOfAKind(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::FourOfAKind_;
//    }
//
//    FourOfAKind::FourOfAKind(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::FourOfAKind_;
//    }
//
////    FourOfAKind &FourOfAKind::operator=(Hand.old hand) {
////        setValue();
////        type = hand.type;
////    }
//
//    FourOfAKind::FourOfAKind(Hand.old &&hand)
//    noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::FourOfAKind_;
//    }
//
//    bool FourOfAKind::isa() {
//        return xOfAKindIsA(4);
//    }
//
//    CardCollection FourOfAKind::best5() {
//        return xOfAKindBest5<FourOfAKind>(4);
//    }
//
//    void FourOfAKind::setValue() {
//        value = getValueOfXOfAKind(4);
//    }
//
//
//    /*
//     * Straight flush implementation
//     */
//    StraightFlush::StraightFlush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(
//            holeCards, communityCards) {
//        setValue();
//        type = eHandType::StraightFlush_;
//    }
//
//    StraightFlush::StraightFlush(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::StraightFlush_;
//    }
//
//    StraightFlush::StraightFlush(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::StraightFlush_;
//    }
//
//    StraightFlush::StraightFlush(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::StraightFlush_;
//    }
//
//    StraightFlush::StraightFlush(Hand.old &&hand)
//    noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::StraightFlush_;
//    }
//
//    CardCollection StraightFlush::best5() {
//        if (!isa())
//            return CardCollection();
//        Straight straight(cards_);
//        /*
//         * we can directly return the straight here, since we have already checked
//         * that we have a straight flush. The straight returns the highest 5 cards
//         * in a row and all must be the same suit or we would have already returned empty CardCollection
//         */
//        return straight.best5();
//    }
//
//    bool StraightFlush::isa() {
//        bool straight = Straight(cards_).isa();
//        bool flush = Flush(cards_).isa();
//        return straight && flush;
//    }
//
//    void StraightFlush::setValue() {
//        value = getLargestRank();
//    }
//
//
//    RoyalFlush::RoyalFlush(cards::HoleCards &holeCards, cards::CommunityCards &communityCards) : Hand.old(holeCards,
//                                                                                                      communityCards) {
//        setValue();
//        type = eHandType::RoyalFlush_;
//    }
//
//    RoyalFlush::RoyalFlush(CardCollection &collection) : Hand.old(collection) {
//        setValue();
//        type = eHandType::RoyalFlush_;
//    }
//
//    RoyalFlush::RoyalFlush(Hand.old *hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::RoyalFlush_;
//    }
//
//    RoyalFlush::RoyalFlush(Hand.old &hand) : Hand.old(hand) {
//        setValue();
//        type = eHandType::RoyalFlush_;
//    }
//
////    RoyalFlush &RoyalFlush::operator=(Hand.old hand) {
////        setValue();
////        type = hand.type;
////    }
//
//    RoyalFlush::RoyalFlush(Hand.old &&hand)
//    noexcept : Hand.old(hand) {
//        setValue();
//        type = eHandType::RoyalFlush_;
//    }
//
//    CardCollection RoyalFlush::best5() {
//        if (!isa())
//            return CardCollection();
//        StraightFlush straight_flush(cards_);
//        return straight_flush.best5();
//    }
//
//    bool RoyalFlush::isa() {
//        StraightFlush sflush(cards_);
//        CardCollection sflushcards = sflush.best5();
//        return sflush.isa() && sflushcards[0].getRank() == 10
//               && sflushcards[1].getRank() == 11
//               && sflushcards[2].getRank() == 12
//               && sflushcards[3].getRank() == 13
//               && sflushcards[4].getRank() == 14;
//    }
//
//    /*
//     * Technically this method is not necesasary because its
//     * the highest hand you can have. If >1 player has royal flush,
//     * its always a split pot
//     */
//    void RoyalFlush::setValue() {
//        value = getLargestRank();
//    }

}




