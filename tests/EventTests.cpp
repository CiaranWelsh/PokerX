//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/Table.h>
#include <events/time_event/BeginGame.h>
#include <events/player_event/RotatePlayers.h>
#include <events/player_event/PostSmallBlind.h>
#include <events/player_event/PostBigBlind.h>
#include "gtest/gtest.h"
#include "iostream"
#include "events/Event.h"
#include "game/Table.h"
#include "game/Players.h"
#include "game/Street.h"

using namespace std;
using namespace events;

class EventTests : public ::testing::Test {
protected:
    game::Players players;
    game::Table table;
    void SetUp() {
        players = game::Players::callStations(9);
        game::Table table2(players);
        table = table2;
    }
};


/*
 * BeginGame tests
 */
TEST_F(EventTests, TestGameStartedFlagIsSwitched) {
    game::Table table;
    ASSERT_FALSE(table.gamePlay.game_started);
    table.step();
    ASSERT_TRUE(table.gamePlay.game_started);
}

TEST_F(EventTests, TestCorrectStreet) {
    game::Table table;
    ASSERT_TRUE(table.gamePlay.street == game::Preflop);
}

TEST_F(EventTests, TestGetId) {
    game::Table table;
    std::string expected = "BeginGame";
    std::string actual = table.current_event->getId();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestEventSwitchedToRotatePlayers) {
    game::Table table;
    table.step();
    std::string expected = "RotatePlayers";
    std::string actual = table.current_event->getId();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, Test) {
    game::Table table;
    table.step();
    table.step();
//    std::string expected = "RotatePlayers";
//    std::string actual = table.current_event->getId();
//    ASSERT_EQ(expected, actual);
}


//TEST_F(EventTests, TestCorrectS
//    ASSERT_EQ(table.street, game::Preflop);
//}
//
//TEST_F(EventTests, TestPotAmount) {
//    game::Table table;treet) {
////    game::Table table;
////    BeginGame beginGame;
////    beginGame.go(table);
//    BeginGame beginGame;
//    beginGame.go(table);
//    ASSERT_EQ(table.pot.value, 0.0);
//}


/*
 * RotatePlayer tests
 */
TEST_F(EventTests, TestRotatePlayers) {
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
TEST_F(EventTests, TestPostSmallBlindPlayerPtrNotEmpty) {
    PostSmallBlind postSmallBlind;
    game::PlayerPtr player0 = players[0];
    std::string expected = "player0";
    std::string actual = player0->getName();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestPostSmallBlind) {
    // small blind is 0.5
    game::PlayerPtr player0 = players[0];
    PostSmallBlind postSmallBlind;
//    postSmallBlind.go(table, table.current_player);
    ASSERT_TRUE(player0->stack == 9.5);
    ASSERT_TRUE(player0->pot == 0.5);
}


/*
 * PostBigBlind tests
 */
TEST_F(EventTests, TessmatPostBigBlindPlayerPtrNotEmpty) {
    PostBigBlind postBigBlind;
    game::PlayerPtr player0 = players[0];
    std::string expected = "player0";
    std::string actual = player0->getName();
    ASSERT_EQ(expected, actual);
}

TEST_F(EventTests, TestPostBigBlind) {
    // Big blind is 0.5
    game::PlayerPtr player0 = players[0];
    PostBigBlind postBigBlind;
//    postBigBlind.go(table, table.current_player);
    ASSERT_TRUE(player0->stack == 9.0);
    ASSERT_TRUE(player0->pot == 1.0);
}




















