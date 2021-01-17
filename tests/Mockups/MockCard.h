//
// Created by Ciaran on 02/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_MOCKCARD_H
#define POKERSIMULATIONSINCPP_MOCKCARD_H

#include <utility>

#include "PokerX/engine/Card.h"
#include "gmock/gmock.h"

using namespace pokerx;
using namespace testing;

class MockCard : public ICard {
public:
    MockCard(int rank, std::string suit) : ICard(rank, std::move(suit)) {};

    MockCard() = default;

    MOCK_METHOD(int, getRank, (), (const, override));
    MOCK_METHOD(std::string, getSuit, (), (const, override));
    MOCK_METHOD(void, setRank, (int), (override));
    MOCK_METHOD(void, setSuit, (const std::string&), (override));
};

class MockCards {
public:
    MockCard lowAceOfSpades;
    MockCard twoOfSpades;
    MockCard threeOfSpades;
    MockCard fourOfSpades;
    MockCard fiveOfSpades;
    MockCard sixOfSpades;
    MockCard sevenOfSpades;
    MockCard eightOfSpades;
    MockCard nineOfSpades;
    MockCard tenOfSpades;
    MockCard jackOfSpades;
    MockCard queenOfSpades;
    MockCard kingOfSpades;
    MockCard aceOfSpades;

    MockCard lowAceOfDiamonds;
    MockCard twoOfDiamonds;
    MockCard threeOfDiamonds;
    MockCard fourOfDiamonds;
    MockCard fiveOfDiamonds;
    MockCard sixOfDiamonds;
    MockCard sevenOfDiamonds;
    MockCard eightOfDiamonds;
    MockCard nineOfDiamonds;
    MockCard tenOfDiamonds;
    MockCard jackOfDiamonds;
    MockCard queenOfDiamonds;
    MockCard kingOfDiamonds;
    MockCard aceOfDiamonds;

    MockCard lowAceOfClubs;
    MockCard twoOfClubs;
    MockCard threeOfClubs;
    MockCard fourOfClubs;
    MockCard fiveOfClubs;
    MockCard sixOfClubs;
    MockCard sevenOfClubs;
    MockCard eightOfClubs;
    MockCard nineOfClubs;
    MockCard tenOfClubs;
    MockCard jackOfClubs;
    MockCard queenOfClubs;
    MockCard kingOfClubs;
    MockCard aceOfClubs;

    MockCard lowAceOfHearts;
    MockCard twoOfHearts;
    MockCard threeOfHearts;
    MockCard fourOfHearts;
    MockCard fiveOfHearts;
    MockCard sixOfHearts;
    MockCard sevenOfHearts;
    MockCard eightOfHearts;
    MockCard nineOfHearts;
    MockCard tenOfHearts;
    MockCard jackOfHearts;
    MockCard queenOfHearts;
    MockCard kingOfHearts;
    MockCard aceOfHearts;

    MockCards() {

        ON_CALL(twoOfSpades, getRank()).WillByDefault(Return(2));
        ON_CALL(twoOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(threeOfSpades, getRank()).WillByDefault(Return(3));
        ON_CALL(threeOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(fourOfSpades, getRank()).WillByDefault(Return(4));
        ON_CALL(fourOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(fiveOfSpades, getRank()).WillByDefault(Return(5));
        ON_CALL(fiveOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(sixOfSpades, getRank()).WillByDefault(Return(6));
        ON_CALL(sixOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(sevenOfSpades, getRank()).WillByDefault(Return(7));
        ON_CALL(sevenOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(eightOfSpades, getRank()).WillByDefault(Return(8));
        ON_CALL(eightOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(nineOfSpades, getRank()).WillByDefault(Return(9));
        ON_CALL(nineOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(tenOfSpades, getRank()).WillByDefault(Return(10));
        ON_CALL(tenOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(jackOfSpades, getRank()).WillByDefault(Return(11));
        ON_CALL(jackOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(queenOfSpades, getRank()).WillByDefault(Return(12));
        ON_CALL(queenOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(kingOfSpades, getRank()).WillByDefault(Return(13));
        ON_CALL(kingOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(aceOfSpades, getRank()).WillByDefault(Return(14));
        ON_CALL(aceOfSpades, getSuit()).WillByDefault(Return("S"));
        ON_CALL(lowAceOfSpades, getRank()).WillByDefault(Return(1));
        ON_CALL(lowAceOfSpades, getSuit()).WillByDefault(Return("S"));

        ON_CALL(twoOfDiamonds, getRank()).WillByDefault(Return(2));
        ON_CALL(twoOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(threeOfDiamonds, getRank()).WillByDefault(Return(3));
        ON_CALL(threeOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(fourOfDiamonds, getRank()).WillByDefault(Return(4));
        ON_CALL(fourOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(fiveOfDiamonds, getRank()).WillByDefault(Return(5));
        ON_CALL(fiveOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(sixOfDiamonds, getRank()).WillByDefault(Return(6));
        ON_CALL(sixOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(sevenOfDiamonds, getRank()).WillByDefault(Return(7));
        ON_CALL(sevenOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(eightOfDiamonds, getRank()).WillByDefault(Return(8));
        ON_CALL(eightOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(nineOfDiamonds, getRank()).WillByDefault(Return(9));
        ON_CALL(nineOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(tenOfDiamonds, getRank()).WillByDefault(Return(10));
        ON_CALL(tenOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(jackOfDiamonds, getRank()).WillByDefault(Return(11));
        ON_CALL(jackOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(queenOfDiamonds, getRank()).WillByDefault(Return(12));
        ON_CALL(queenOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(kingOfDiamonds, getRank()).WillByDefault(Return(13));
        ON_CALL(kingOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(aceOfDiamonds, getRank()).WillByDefault(Return(14));
        ON_CALL(aceOfDiamonds, getSuit()).WillByDefault(Return("D"));
        ON_CALL(lowAceOfDiamonds, getRank()).WillByDefault(Return(1));
        ON_CALL(lowAceOfDiamonds, getSuit()).WillByDefault(Return("D"));

        ON_CALL(twoOfClubs, getRank()).WillByDefault(Return(2));
        ON_CALL(twoOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(threeOfClubs, getRank()).WillByDefault(Return(3));
        ON_CALL(threeOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(fourOfClubs, getRank()).WillByDefault(Return(4));
        ON_CALL(fourOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(fiveOfClubs, getRank()).WillByDefault(Return(5));
        ON_CALL(fiveOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(sixOfClubs, getRank()).WillByDefault(Return(6));
        ON_CALL(sixOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(sevenOfClubs, getRank()).WillByDefault(Return(7));
        ON_CALL(sevenOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(eightOfClubs, getRank()).WillByDefault(Return(8));
        ON_CALL(eightOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(nineOfClubs, getRank()).WillByDefault(Return(9));
        ON_CALL(nineOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(tenOfClubs, getRank()).WillByDefault(Return(10));
        ON_CALL(tenOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(jackOfClubs, getRank()).WillByDefault(Return(11));
        ON_CALL(jackOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(queenOfClubs, getRank()).WillByDefault(Return(12));
        ON_CALL(queenOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(kingOfClubs, getRank()).WillByDefault(Return(13));
        ON_CALL(kingOfClubs, getSuit()).WillByDefault(Return("C"));
        ON_CALL(aceOfClubs, getRank()).WillByDefault(Return(14));
        ON_CALL(aceOfClubs, getSuit()).WillByDefault(Return("H"));
        ON_CALL(lowAceOfClubs, getRank()).WillByDefault(Return(1));
        ON_CALL(lowAceOfClubs, getSuit()).WillByDefault(Return("H"));

        ON_CALL(twoOfHearts, getRank()).WillByDefault(Return(2));
        ON_CALL(twoOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(threeOfHearts, getRank()).WillByDefault(Return(3));
        ON_CALL(threeOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(fourOfHearts, getRank()).WillByDefault(Return(4));
        ON_CALL(fourOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(fiveOfHearts, getRank()).WillByDefault(Return(5));
        ON_CALL(fiveOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(sixOfHearts, getRank()).WillByDefault(Return(6));
        ON_CALL(sixOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(sevenOfHearts, getRank()).WillByDefault(Return(7));
        ON_CALL(sevenOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(eightOfHearts, getRank()).WillByDefault(Return(8));
        ON_CALL(eightOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(nineOfHearts, getRank()).WillByDefault(Return(9));
        ON_CALL(nineOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(tenOfHearts, getRank()).WillByDefault(Return(10));
        ON_CALL(tenOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(jackOfHearts, getRank()).WillByDefault(Return(11));
        ON_CALL(jackOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(queenOfHearts, getRank()).WillByDefault(Return(12));
        ON_CALL(queenOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(kingOfHearts, getRank()).WillByDefault(Return(13));
        ON_CALL(kingOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(aceOfHearts, getRank()).WillByDefault(Return(14));
        ON_CALL(aceOfHearts, getSuit()).WillByDefault(Return("H"));
        ON_CALL(lowAceOfHearts, getRank()).WillByDefault(Return(1));
        ON_CALL(lowAceOfHearts, getSuit()).WillByDefault(Return("H"));
    }

};


#endif //POKERSIMULATIONSINCPP_MOCKCARD_H
