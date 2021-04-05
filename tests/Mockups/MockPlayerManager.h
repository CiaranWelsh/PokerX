//
// Created by Ciaran Welsh on 21/01/2021.
//

#ifndef POKERX_MOCKPLAYERMANAGER_H
#define POKERX_MOCKPLAYERMANAGER_H

#include <PokerX/engine/IPlayerManager.h>
#include "gmock/gmock.h"
//#include "PokerX/engine/GameVariables.h"
//#include "PokerX/engine/RotatoryContainer.h"
//#include "PokerX/engine/Player.h"

using namespace pokerx;
using namespace testing;


class MockPlayerManager : public IPlayerManager {
public:
    MockPlayerManager() = default;

    ~MockPlayerManager() override = default;

    MOCK_METHOD(bool, allPlayersEqual, (), (override));
    MOCK_METHOD(SharedIPlayerPtr, getCurrentPlayer, (), (const, override));
    MOCK_METHOD(void, watch, (IGameVariables * variables), (override));
    MOCK_METHOD(void, moveButton, (), (override));
    MOCK_METHOD(void, nextPlayer, (), (override));
    MOCK_METHOD(SharedIPlayerPtr, getPlayer, (unsigned int n), (override));
    MOCK_METHOD(int, getCurrentPlayerIdx, (), (const, override));
    MOCK_METHOD(void, setCurrentPlayerIdx, (int currentPlayerIdx));
    MOCK_METHOD(void, setCurrentPlayerByName, (const std::string &name));
    MOCK_METHOD(SharedIPlayerPtr, getPlayerByName, (const std::string &name), (override));
    MOCK_METHOD(SharedIPlayerPtr, getButton, (), (override));
    MOCK_METHOD(void, setButton, (std::string playerName), (override));
    MOCK_METHOD(int, getIndexOfPlayer, (const SharedIPlayerPtr &player), (override));
    MOCK_METHOD(void, setStackSizeTo, (float amount), (override));
    MOCK_METHOD(void, enumeratePlayerNames, (), (override));
    MOCK_METHOD(void, enumerateEmptyPlayerNames, (), (override));
    MOCK_METHOD(std::vector<std::string>, getPlayerNames, (), (override));
    MOCK_METHOD(void, resetAmountContribThisStreet, (), (override));
    MOCK_METHOD(std::vector<Hand>, getPlayerHands, (), (override));
    MOCK_METHOD(void, reset, (), (override));
    MOCK_METHOD(SharedIPlayerPtr, getSmallBlind, (), (override));
    MOCK_METHOD(SharedIPlayerPtr, getBigBlind, (), (override));
    MOCK_METHOD(bool, allPlayersTakenAtLeastOneTurn, (), (override));
    MOCK_METHOD(int, getNumPlayersStillInPot, (), (override));

};

#endif //POKERX_MOCKPLAYERMANAGER_H
