//
// Created by CiaranWelsh on 01/01/2020.
//

#include <game/Table.h>
#include "gtest/gtest.h"
#include "iostream"

using namespace std;
using namespace game;

TEST(TableTests, Test){
    Players players;
    players = Players::callStations(9);
    Table table(players);
    int actual = table.players.size();
    int expected = 9;
    ASSERT_EQ(expected, actual);
}