//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/Table.h>
#include <events/time_event/BeginGame.h>
#include "gtest/gtest.h"
#include "iostream"
#include "events/Event.h"
#include "game/Table.h"

using namespace std;
using namespace game;
using namespace events;

class EventTests : public ::testing::Test{
protected:
    Players players;
    EventTests() {
        players = Players::callStations(9);
        Table table(players);
    }
};

TEST_F(EventTests, TestGameStartedFlagIsSwitched){
    Table table;
    ASSERT_FALSE(table.game_started);
    BeginGame beginGame;
    beginGame.go(table);
    ASSERT_TRUE(table.game_started);
}


TEST_F(EventTests, TestCorrectStreet){
    Table table;
    BeginGame beginGame;
    beginGame.go(table);
    ASSERT_EQ(table.street, Preflop);
}

TEST_F(EventTests, TestPotAmount){
    Table table;
    BeginGame beginGame;
    beginGame.go(table);
    ASSERT_EQ(table.pot.value, 0.0);
}




















