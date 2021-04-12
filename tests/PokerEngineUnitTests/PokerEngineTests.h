//
// Created by Ciaran Welsh on 07/03/2021.
//

#ifndef POKERX_POKERENGINETESTS_H
#define POKERX_POKERENGINETESTS_H

#include <Mockups/MockGameVariables.h>
#include <Mockups/MockPlayerManager.h>
#include <Mockups/MockPlayer.h>
#include <Mockups/MockDeck.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PokerX/engine/PokerEngine.h"

/**
 * Base test class for poker engine unit tests which are
 * slit into several, for the sake of clarity.
 */
class PokerEngineTests : public ::testing::Test {
public:
    Deck deck;
    std::vector<ICardPtr> injCommunityCards;
    CardCollection cc;
    MockGameVariables gameVariables;
    MockPlayerManager playerManager;
    std::shared_ptr<MockPlayer> btn;
    std::shared_ptr<MockPlayer> sb;
    std::shared_ptr<MockPlayer> bb;
    std::shared_ptr<MockPlayer> utg;
    std::shared_ptr<MockPlayer> hj; // hijack
    std::shared_ptr<MockPlayer> co;

    std::string btn_name = "DrLevty";
    std::string sb_name = "OhhhJeee";
    std::string bb_name = "gokudousan";
    std::string utg_name = "aka_Kranv1ch";
    std::string hj_name = "Malyar-88";
    std::string co_name = "Lorn_Antoan";

    PokerEngineTests() {
        btn = makePlayer(btn_name, 10.01);
        sb = makePlayer(sb_name, 4.86);
        bb = makePlayer(bb_name, 5.81);
        utg = makePlayer(utg_name, 10);
        hj = makePlayer(hj_name, 3.97);
        co = makePlayer(co_name, 10.25);

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

        // give players access to game variables
        ON_CALL(*btn, getGameVariables)
            .WillByDefault(Return(&gameVariables));
        ON_CALL(*sb, getGameVariables)
            .WillByDefault(Return(&gameVariables));
        ON_CALL(*bb, getGameVariables)
            .WillByDefault(Return(&gameVariables));
        ON_CALL(*utg, getGameVariables)
            .WillByDefault(Return(&gameVariables));
        ON_CALL(*hj, getGameVariables)
            .WillByDefault(Return(&gameVariables));
        ON_CALL(*co, getGameVariables)
            .WillByDefault(Return(&gameVariables));

        EXPECT_CALL(playerManager, watch)
                .Times(1); // always gets called once
        EXPECT_CALL(playerManager, nextPlayer)
                .Times(AnyNumber());

        ON_CALL(gameVariables, getCurrencySymbol)
            .WillByDefault(Return("$"));

        ON_CALL(gameVariables, getInjectedCommunityCards)
            .WillByDefault(ReturnRef(injCommunityCards));

        // set some default cards for the deck to pop
        EXPECT_CALL(gameVariables, getDeck)
            .WillRepeatedly(ReturnRef(deck));
        ON_CALL(gameVariables, getCommunityCards)
            .WillByDefault(Return(cc));

        ON_CALL(gameVariables, getAmountToCall)
            .WillByDefault(Return(0.3));

    };

    std::shared_ptr<MockPlayer> makePlayer(std::string& name, float stack) {
        std::shared_ptr<MockPlayer> p = std::make_shared<MockPlayer>();
        ON_CALL(*p, getName)
                .WillByDefault(ReturnRef(name));
        ON_CALL(*p, getStack)
                .WillByDefault(Return(stack));
        return p;
    }
};



#endif //POKERX_POKERENGINETESTS_H
