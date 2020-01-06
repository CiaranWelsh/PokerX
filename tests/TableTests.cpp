//
// Created by CiaranWelsh on 01/01/2020.
//

#include <game/Table.h>
#include "gtest/gtest.h"
#include "iostream"

using namespace std;
using namespace game;




TEST(TableTests, TestNumberOfPlayers) {
    Players players = Players::callStations(9);
    Table table(players);
    int actual = table.players.size();
    int expected = 9;
    ASSERT_EQ(expected, actual);
}

TEST(TableTests, TestAccessToPLayer) {
    Players players = Players::callStations(9);
    Table table(players);
    game::PlayerPtr ptr = table.players[0];
    Player player = *ptr;
    std::string expected = "player0";
    ASSERT_EQ(expected, player.getName());
}

TEST(TableTests, TestCurrentPlayer) {
    Players players = Players::callStations(9);
    Table table(players);
    PlayerPtr player = table.players.getCurrentPlayer();
    std::string expected = "player0";
    ASSERT_EQ(expected, player->getName());
}

TEST(TableTests, TestCurrentPlayerUpdatesAfterRotate) {
    Players players = Players::callStations(9);
    Table table(players);
    table.players.rotate();
    PlayerPtr player = table.players.getCurrentPlayer();
    std::string expected = "player1";
    ASSERT_EQ(expected, player->getName());
}




















