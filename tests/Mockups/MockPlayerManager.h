//
// Created by Ciaran Welsh on 21/01/2021.
//

#ifndef POKERX_MOCKPLAYERMANAGER_H
#define POKERX_MOCKPLAYERMANAGER_H

#include "gmock/gmock.h"
#include "PokerX/engine/GameVariables.h"
#include "PokerX/engine/RotatoryContainer.h"
#include "PokerX/engine/Player.h"

using namespace pokerx;
using namespace testing;


class MockPlayerManager : public IPlayerManager {
public:

    MOCK_METHOD(void, rotateContainerContents, (), ());

    MOCK_METHOD(bool, checkAllPlayersEqual, (), (const));

    MOCK_METHOD(SharedPlayerPtr, getButton, (), ());

    MOCK_METHOD(const SharedPlayerPtr &, getCurrentPlayer, (), (const));

    MOCK_METHOD(void, watch, (GameVariables * ), ());

    MOCK_METHOD(void, moveButton, (), ());

    MOCK_METHOD(void, nextPlayer, (), ());

    MOCK_METHOD(int, getButtonIdx, (), (const));

    MOCK_METHOD(void, setButtonIdx, (int), ());

    MOCK_METHOD(int, getCurrentPlayerIdx, (), (const));

    MOCK_METHOD(void, setCurrentPlayerIdx, (int), ());

    MOCK_METHOD(void, moveCurrentPlayer, (), ());

};

#endif //POKERX_MOCKPLAYERMANAGER_H
