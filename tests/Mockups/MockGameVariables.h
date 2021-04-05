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

    MOCK_METHOD(Pot &, getPot, (), (override));

    MOCK_METHOD(float, getAmountToCall, (), (const));

    MOCK_METHOD(void, setAmountToCall, (float), (override));

    MOCK_METHOD(void, addToPot, (const Pot &), (override));

    MOCK_METHOD(bool, hasBetBeenPlaced, (), (const));

    MOCK_METHOD(void, setBetPlaced, (bool), (override));

    MOCK_METHOD(Street, getStreet, (), (const));

    MOCK_METHOD(void, setStreet, (Street), (override));

    MOCK_METHOD(float, getSmallBlind, (), (const));

    MOCK_METHOD(void, setSmallBlind, (float), (override));

    MOCK_METHOD(float, getBigBlind, (), (const));

    MOCK_METHOD(void, setBigBlind, (float), (override));

    MOCK_METHOD(Deck &, getDeck, (), (override));

    MOCK_METHOD(void, setDeck, (const Deck &), (override));

    MOCK_METHOD(CardCollection, getCommunityCards, (), (const));

    MOCK_METHOD(void, setCommunityCards, (CardCollection), (override));

    MOCK_METHOD(unsigned int, getN, (), (const));

    MOCK_METHOD(void, setN, (unsigned int), (override));

    MOCK_METHOD(unsigned int, numGamesPlayed, (), (const));

    MOCK_METHOD(void, setGamesPlayed, (unsigned int), (override));

    MOCK_METHOD(void, reset, (), (override));

    MOCK_METHOD(bool, isDone, (), (const, override));

    MOCK_METHOD(void, setDone, (bool), (override));

    MOCK_METHOD(std::string, getCurrencySymbol, (), (const, override));

    MOCK_METHOD(void, setCurrencySymbol, (const std::string& symbol), (override));

    MOCK_METHOD(void, setSeed, (unsigned long long seed), (override));

    MOCK_METHOD(void, injectCommunityCards, (const std::vector<std::string> &cards), (override));

    MOCK_METHOD(std::vector<ICardPtr> &, getInjectedCommunityCards, (), (const, override));


};

#endif //POKERX_MOCKGAMEVARIABLES_H
