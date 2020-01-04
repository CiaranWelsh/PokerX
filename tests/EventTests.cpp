//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/Table.h>
#include <events/time_event/BeginGame.h>
#include <events/player_event/RotatePlayers.h>
#include <events/player_event/PostSmallBlind.h>
#include "gtest/gtest.h"
#include "iostream"
#include "events/Event.h"
#include "game/Table.h"
#include "game/Players.h"

using namespace std;
using namespace events;

class EventTests : public ::testing::Test{
protected:
    game::Players players;
    EventTests() {
        players = game::Players::callStations(9);
        game::Table table(players);
    }
};


/*
 * BeginGame tests
 */
TEST_F(EventTests, TestGameStartedFlagIsSwitched){
    game::Table table;
    ASSERT_FALSE(table.game_started);
    BeginGame beginGame;
    beginGame.go(table);
    ASSERT_TRUE(table.game_started);
}


TEST_F(EventTests, TestCorrectStreet){
    game::Table table;
    BeginGame beginGame;
    beginGame.go(table);
    ASSERT_EQ(table.street, game::Preflop);
}

TEST_F(EventTests, TestPotAmount){
    game::Table table;
    BeginGame beginGame;
    beginGame.go(table);
    ASSERT_EQ(table.pot.value, 0.0);
}


/*
 * RotatePlayer tests
 */
TEST_F(EventTests, TestRotatePlayers){
    game::Table table;
    RotatePlayers rotatePlayers;
    rotatePlayers.go(players);
    game::PlayerPtr player0 = players[0];
    std::string expected = "player1";
    std::string actual = player0->getName();
    ASSERT_EQ(expected, actual);
}


/*
 * PostSmallBlind tests
 */
TEST_F(EventTests, TestPostSmallBlind){
    game::Table table;
    PostSmallBlind postSmallBlind;
    postSmallBlind.go(table, table.current_player);
//    game::PlayerPtr player0 = players[0];
//    std::string expected = "player1";
//    std::string actual = player0->getName();
//    ASSERT_EQ(expected, actual);
}




















