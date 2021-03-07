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

    MOCK_METHOD(pokerx::Action, selectAction, (StateMachine * ), (override));

    MOCK_METHOD(const std::string&, getName, (), (const override));

    MOCK_METHOD(void, setName, (const std::string &), (override));

    MOCK_METHOD(float, getStack, (), (const, override));

    MOCK_METHOD(void, setStack, (float), (override));

    MOCK_METHOD(bool, isAllIn, (), (const, override));

    MOCK_METHOD(void, setIsAllIn, (bool), (override));

    MOCK_METHOD(bool, hasFolded, (), (const, override));

    MOCK_METHOD(void, setHasFolded, (bool hasFolded), (override));

    MOCK_METHOD(HoleCards &, getHoleCards, (), (override));

    MOCK_METHOD(void, watch, (IGameVariables * ), (override));

    MOCK_METHOD(void, fold, (), (override));

    MOCK_METHOD(void, check, (), (override));

    MOCK_METHOD(void, call, (), (override));

    MOCK_METHOD(float, raise, (), (override));

    MOCK_METHOD(void, allIn, (), (override));

    MOCK_METHOD(IGameVariables *, getGameVariables, (), (const, override));

    MOCK_METHOD(void, postSmallBlind, (), (override));

    MOCK_METHOD(void, postBigBlind, (), (override));

    MOCK_METHOD(void, checkGameVariablesNotNull, (), (const, override));

    MOCK_METHOD(bool, isSittingOut, (), (const, override));
    MOCK_METHOD(void, setSittingOut, (bool), (override));
    MOCK_METHOD(float, getAmountContrib, (), (const, override));
    MOCK_METHOD(void, setAmountContrib, (float), (override));
    MOCK_METHOD(Hand, getHand, (), (override));
    MOCK_METHOD(void, reset, (), (override));
    MOCK_METHOD(void, doRaise, (float), (override));
    MOCK_METHOD(Policy *, getPolicy, (), (override));
    MOCK_METHOD(void, setPolicy, (const Policy &), (override));
    MOCK_METHOD(unsigned int, getNumActionsThisStreet, (), (const, override));
    MOCK_METHOD(void, setNumActionsThisStreet, (unsigned int), (override));

};

#endif //POKERX_MOCKPLAYER_H
