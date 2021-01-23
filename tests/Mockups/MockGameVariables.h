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

    MOCK_METHOD(Pot, getPot, (), (const));

    MOCK_METHOD(float, getAmountToCall, (), (const));

    MOCK_METHOD(void, setAmountToCall, (float), ());

    MOCK_METHOD(void, addToPot, (const Pot &), ());

    MOCK_METHOD(bool, isCheckAvailable, (), (const));

    MOCK_METHOD(void, setCheckAvailable, (bool), ());

    MOCK_METHOD(Street, getStreet, (), (const));

    MOCK_METHOD(void, setStreet, (Street), ());

    MOCK_METHOD(float, getSmallBlind, (), (const));

    MOCK_METHOD(void, setSmallBlind, (float), ());

    MOCK_METHOD(float, getBigBlind, (), (const));

    MOCK_METHOD(void, setBigBlind, (float), ())

};

#endif //POKERX_MOCKGAMEVARIABLES_H
