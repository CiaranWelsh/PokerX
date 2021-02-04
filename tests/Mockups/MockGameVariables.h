//
// Created by Ciaran on 17/01/2021.
//

#ifndef POKERX_MOCKGAMEVARIABLES_H
#define POKERX_MOCKGAMEVARIABLES_H

#include "gmock/gmock.h"
#include "PokerX/engine/IGameVariables.h"

using namespace pokerx;
using namespace testing;

class MockGameVariables : public IGameVariables {
public:
    MockGameVariables() = default;

    ~MockGameVariables() override = default;

    MOCK_METHOD(Pot &, getPot, (), ());

    MOCK_METHOD(float, getAmountToCall, (), (const));

    MOCK_METHOD(void, setAmountToCall, (float), ());

    MOCK_METHOD(void, addToPot, (const Pot &), ());

    MOCK_METHOD(bool, hasBetBeenPlaced, (), (const));

    MOCK_METHOD(void, setBetPlaced, (bool), ());

    MOCK_METHOD(Street, getStreet, (), (const));

    MOCK_METHOD(void, setStreet, (Street), ());

    MOCK_METHOD(float, getSmallBlind, (), (const));

    MOCK_METHOD(void, setSmallBlind, (float), ());

    MOCK_METHOD(float, getBigBlind, (), (const));

    MOCK_METHOD(void, setBigBlind, (float), ());

    MOCK_METHOD(Deck &, getDeck, (), ());

    MOCK_METHOD(void, setDeck, (const Deck &), ());

    MOCK_METHOD( CardCollection, getCommunityCards, (), (const));

    MOCK_METHOD(void, setCommunityCards, (CardCollection), ());

    MOCK_METHOD(unsigned int, getN, (), (const));

    MOCK_METHOD(void, setN, (unsigned int), ());

    MOCK_METHOD(unsigned int, numGamesPlayed, (), (const));

    MOCK_METHOD(void, setGamesPlayed, (unsigned int), ());

    MOCK_METHOD(void, reset, (), ());

};

#endif //POKERX_MOCKGAMEVARIABLES_H
