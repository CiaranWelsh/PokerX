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


namespace pokerx {

    Hand::Hand() : RestrictedCardCollection(7) {}

    HandType Hand::getType() {
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
        } else{
            LOGIC_ERROR << "Can't determine hand type. Weird" << std::endl;
        }
    }

    bool Hand::isHighCard() {
        return true;
    }

    bool Hand::isPair() {
        Pair pair(cards_);
        return pair.isA();
    }

    bool Hand::isTwoPair() {
        TwoPair twoPair(cards_);
        return twoPair.isA();
    }

    bool Hand::isThreeOfAKind() {
        ThreeOfAKind threeOfAKind(cards_);
        return threeOfAKind.isA();
    }

    bool Hand::isStraight() {
        Straight straight(cards_);
        return straight.isA();
    }

    bool Hand::isFlush() {
        Flush flush(cards_);
        return flush.isA();
    }

    bool Hand::isFullHouse() {
        FullHouse fullHouse(cards_);
        return fullHouse.isA();
    }

    bool Hand::isFourOfAKind() {
        FourOfAKind fourOfAKind(cards_);
        return fourOfAKind.isA();
    }

    bool Hand::isStraightFlush() {
        StraightFlush straightFlush(cards_);
        return straightFlush.isA();
    }

    bool Hand::isRoyalFlush() {
        RoyalFlush royalFlush(cards_);
        return royalFlush.isA();
    }

    Best5 *Hand::bestFive() {
        return nullptr;
    }


}