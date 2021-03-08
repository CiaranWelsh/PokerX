//
// Created by Ciaran Welsh on 07/03/2021.
//

#ifndef POKERX_POKERENGINETESTS_H
#define POKERX_POKERENGINETESTS_H

#include <Mockups/MockGameVariables.h>
#include <Mockups/MockPlayerManager.h>
#include <Mockups/MockPlayer.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PokerX/engine/PokerEngine.h"

/**
 * Base test class for poker engine unit tests which are
 * slit into several, for the sake of clarity.
 */
class PokerEngineTests : public ::testing::Test {
public:
    MockGameVariables gameVariables;
    MockPlayerManager playerManager;
    std::shared_ptr<MockPlayer> btn;
    std::shared_ptr<MockPlayer> sb;
    std::shared_ptr<MockPlayer> bb;
    std::shared_ptr<MockPlayer> utg;
    std::shared_ptr<MockPlayer> hj; // hijack
    std::shared_ptr<MockPlayer> co;

    PokerEngineTests() {
        btn = makePlayer("DrLevty", 10.01);
        sb = makePlayer("OhhhJeee", 4.86);
        bb = makePlayer("gokudousan", 5.81);
        utg = makePlayer("aka_Kranv1ch", 10);
        hj = makePlayer("Malyar-88", 3.97);
        co = makePlayer("Lorn_Antoan", 10.25);

        // set the button
        ON_CALL(playerManager, getButton)
                .WillByDefault(Return(btn));
        ON_CALL(playerManager, getSmallBlind)
                .WillByDefault(Return(sb));
        ON_CALL(playerManager, getBigBlind)
                .WillByDefault(Return(bb));

        // define what playerManager returns when call to getPlayer
        ON_CALL(playerManager, getPlayer(1))
                .WillByDefault(Return(btn));
        ON_CALL(playerManager, getPlayer(2))
                .WillByDefault(Return(sb));
        ON_CALL(playerManager, getPlayer(3))
                .WillByDefault(Return(bb));
        ON_CALL(playerManager, getPlayer(4))
                .WillByDefault(Return(utg));
        ON_CALL(playerManager, getPlayer(5))
                .WillByDefault(Return(hj));
        ON_CALL(playerManager, getPlayer(6))
                .WillByDefault(Return(co));

        EXPECT_CALL(playerManager, watch)
                .Times(1); // always gets called once
        EXPECT_CALL(playerManager, nextPlayer)
                .Times(AnyNumber());

        ON_CALL(gameVariables, getCurrencySymbol)
            .WillByDefault(Return("$"));
    };

    std::shared_ptr<MockPlayer> makePlayer(const std::string &name, float stack) {
        std::shared_ptr<MockPlayer> p = std::make_shared<MockPlayer>();
        ON_CALL(*p, getName)
                .WillByDefault(ReturnRef(name));
        ON_CALL(*p, getStack)
                .WillByDefault(Return(stack));
        return p;
    }
};



#endif //POKERX_POKERENGINETESTS_H
