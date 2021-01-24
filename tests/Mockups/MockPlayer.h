//
// Created by Ciaran Welsh on 23/01/2021.
//

#ifndef POKERX_MOCKPLAYER_H
#define POKERX_MOCKPLAYER_H


#include "gmock/gmock.h"
#include "PokerX/engine/IPlayer.h"
#include "PokerX/engine/Action.h"

using namespace pokerx;
using namespace testing;


class MockPlayer : public IPlayer {
public:

    using IPlayer::IPlayer;

    ~MockPlayer() override = default;

    MOCK_METHOD(pokerx::Action, selectAction, (StateMachine * ), ());

    MOCK_METHOD(const std::string&, getName, (), (const));

    MOCK_METHOD(void, setName, (const std::string &), ());

    MOCK_METHOD(float, getStack, (), (const));

    MOCK_METHOD(void, setStack, (float), ());

    MOCK_METHOD(bool, isAllIn, (), (const));

    MOCK_METHOD(void, setIsAllIn, (bool), ());

    MOCK_METHOD(bool, isInPlay, (), (const));

    MOCK_METHOD(void, setIsInPlay, (bool isInPlay), ());

    MOCK_METHOD(HoleCards &, getHoleCards, (), (const));

    MOCK_METHOD(void, watch, (IGameVariables * ), ());

    MOCK_METHOD(void, fold, (), ());

    MOCK_METHOD(void, check, (), ());

    MOCK_METHOD(float, call, (), ());

    MOCK_METHOD(float, raise, (), ());

    MOCK_METHOD(float, allIn, (), ());

    MOCK_METHOD(IGameVariables *, getGameVariables, (), (const));

    MOCK_METHOD(void, postSmallBlind, (), ());

    MOCK_METHOD(void, postBigBlind, (), ());

    MOCK_METHOD(void, checkGameVariablesNotNull, (), (const));


};

#endif //POKERX_MOCKPLAYER_H
