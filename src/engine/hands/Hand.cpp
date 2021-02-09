//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "PokerX/engine/hands/Hand.h"
#include "PokerX/engine/hands/Flush.h"
#include "PokerX/engine/hands/FullHouse.h"
#include "PokerX/engine/hands/FourOfAKind.h"
#include "PokerX/engine/hands/HighCard.h"
#include "PokerX/engine/hands/Pair.h"
#include "PokerX/engine/hands/TwoPair.h"
#include "PokerX/engine/hands/ThreeOfAKind.h"
#include "PokerX/engine/hands/Straight.h"
#include "PokerX/engine/hands/StraightFlush.h"
#include "PokerX/engine/hands/RoyalFlush.h"
#include "PokerX/Error.h"

/*
 * think about cacheing so that some of these computations do not need
 * to be repeated.
 */
namespace pokerx {

    Hand::Hand() : RestrictedCardCollection(7) {}

    HandType Hand::getType() const {
        if (isRoyalFlush()) {
            return ROYAL_FLUSH;
        } else if (isStraightFlush()) {
            return STRAIGHT_FLUSH;
        } else if (isFourOfAKind()) {
            return FOUR_OF_A_KIND;
        } else if (isFullHouse()) {
            return FULL_HOUSE;
        } else if (isFlush()) {
            return FLUSH;
        } else if (isStraight()) {
            return STRAIGHT;
        } else if (isThreeOfAKind()) {
            return THREE_OF_A_KIND;
        } else if (isTwoPair()) {
            return TWO_PAIR;
        } else if (isPair()) {
            return PAIR;
        } else if (isHighCard()) {
            return HIGH_CARD;
        } else {
            LOGIC_ERROR << "Can't determine hand type. Weird" << std::endl;
        }
    }

    std::string Hand::getHandTypeStr(HandType type){
        std::string handTypeStrings[11] = {
                "No Hand",
                "High Card",
                "Pair",
                "Two Pair",
                "Three of a Kind",
                "Straight",
                "Flush",
                "Full House",
                "Four of a Kind",
                "Straight Flush",
                "Royal Flush",
        };
        return handTypeStrings[type];
    }

    bool Hand::isHighCard() const {
        return true;
    }

    bool Hand::isPair() const {
        Pair pair(cards_);
        return pair.isA();
    }

    bool Hand::isTwoPair() const {
        TwoPair twoPair(cards_);
        return twoPair.isA();
    }

    bool Hand::isThreeOfAKind() const {
        ThreeOfAKind threeOfAKind(cards_);
        return threeOfAKind.isA();
    }

    bool Hand::isStraight() const {
        Straight straight(cards_);
        return straight.isA();
    }

    bool Hand::isFlush() const {
        Flush flush(cards_);
        return flush.isA();
    }

    bool Hand::isFullHouse() const {
        FullHouse fullHouse(cards_);
        return fullHouse.isA();
    }

    bool Hand::isFourOfAKind() const {
        FourOfAKind fourOfAKind(cards_);
        return fourOfAKind.isA();
    }

    bool Hand::isStraightFlush() const {
        StraightFlush straightFlush(cards_);
        return straightFlush.isA();
    }

    bool Hand::isRoyalFlush() const {
        RoyalFlush royalFlush(cards_);
        return royalFlush.isA();
    }

    std::shared_ptr<CardCollection> Hand::bestFiveCards() {
        HandType type = getType();

        switch (type) {
            case NO_HAND:
                break;
            case HIGH_CARD:
                return HighCard(cards_).getBestFive();
            case PAIR:
                return Pair(cards_).getBestFive();
            case TWO_PAIR:
                return TwoPair(cards_).getBestFive();
            case THREE_OF_A_KIND:
                return ThreeOfAKind(cards_).getBestFive();
            case STRAIGHT:
                return Straight(cards_).getBestFive();
            case FLUSH:
                return Flush(cards_).getBestFive();
            case FULL_HOUSE:
                return FullHouse(cards_).getBestFive();
            case FOUR_OF_A_KIND:
                return FourOfAKind(cards_).getBestFive();
            case STRAIGHT_FLUSH:
                return StraightFlush(cards_).getBestFive();
            case ROYAL_FLUSH:
                return RoyalFlush(cards_).getBestFive();
        }
    }


    bool Hand::operator==(const Hand& other) const {
        HandType thisType = getType();
        HandType theirType = other.getType();
        if (thisType == theirType) {
            switch (thisType) {
                case NO_HAND:
                    break;
                case HIGH_CARD:
                    return HighCard(cards_).getValue() == HighCard(other).getValue();
                case PAIR:
                    return Pair(cards_).getValue() == Pair(other).getValue();
                case TWO_PAIR:
                    return TwoPair(cards_).getValue() == TwoPair(other).getValue();
                case THREE_OF_A_KIND:
                    return ThreeOfAKind(cards_).getValue() == ThreeOfAKind(other).getValue();
                case STRAIGHT:
                    return Straight(cards_).getValue() == Straight(other).getValue();
                case FLUSH:
                    return Flush(cards_).getValue() == Flush(other).getValue();
                case FULL_HOUSE:
                    return FullHouse(cards_).getValue() == FullHouse(other).getValue();
                case FOUR_OF_A_KIND:
                    return FourOfAKind(cards_).getValue() == FourOfAKind(other).getValue();
                case STRAIGHT_FLUSH:
                    return StraightFlush(cards_).getValue() == StraightFlush(other).getValue();
                case ROYAL_FLUSH:
                    return RoyalFlush(cards_).getValue() == RoyalFlush(other).getValue();
            }
        }
        return thisType == theirType;
    }

    bool Hand::operator!=(const Hand &other) const {
        return !(*this == other);
    }

    bool Hand::operator<(const Hand &other) const {
        HandType thisType = getType();
        HandType theirType = other.getType();
        if (thisType == theirType) {
            switch (thisType) {
                case NO_HAND:
                    break;
                case HIGH_CARD:
                    return HighCard(cards_).getValue() < HighCard(other).getValue();
                case PAIR:
                    return Pair(cards_).getValue() < Pair(other).getValue();
                case TWO_PAIR:
                    return TwoPair(cards_).getValue() < TwoPair(other).getValue();
                case THREE_OF_A_KIND:
                    return ThreeOfAKind(cards_).getValue() < ThreeOfAKind(other).getValue();
                case STRAIGHT:
                    return Straight(cards_).getValue() < Straight(other).getValue();
                case FLUSH:
                    return Flush(cards_).getValue() < Flush(other).getValue();
                case FULL_HOUSE:
                    return FullHouse(cards_).getValue() < FullHouse(other).getValue();
                case FOUR_OF_A_KIND:
                    return FourOfAKind(cards_).getValue() < FourOfAKind(other).getValue();
                case STRAIGHT_FLUSH:
                    return StraightFlush(cards_).getValue() < StraightFlush(other).getValue();
                case ROYAL_FLUSH:
                    return RoyalFlush(cards_).getValue() < RoyalFlush(other).getValue();
            }
        }
        return thisType == theirType;
    }

    bool Hand::operator>(const Hand &other) const {
        HandType thisType = getType();
        HandType theirType = other.getType();
        if (thisType == theirType) {
            switch (thisType) {
                case NO_HAND:
                    break;
                case HIGH_CARD:
                    return HighCard(cards_).getValue() > HighCard(other).getValue();
                case PAIR:
                    return Pair(cards_).getValue() > Pair(other).getValue();
                case TWO_PAIR:
                    return TwoPair(cards_).getValue() > TwoPair(other).getValue();
                case THREE_OF_A_KIND:
                    return ThreeOfAKind(cards_).getValue() > ThreeOfAKind(other).getValue();
                case STRAIGHT:
                    return Straight(cards_).getValue() > Straight(other).getValue();
                case FLUSH:
                    return Flush(cards_).getValue() > Flush(other).getValue();
                case FULL_HOUSE:
                    return FullHouse(cards_).getValue() > FullHouse(other).getValue();
                case FOUR_OF_A_KIND:
                    return FourOfAKind(cards_).getValue() > FourOfAKind(other).getValue();
                case STRAIGHT_FLUSH:
                    return StraightFlush(cards_).getValue() > StraightFlush(other).getValue();
                case ROYAL_FLUSH:
                    return RoyalFlush(cards_).getValue() > RoyalFlush(other).getValue();
            }
        }
        return thisType == theirType;
    }


}