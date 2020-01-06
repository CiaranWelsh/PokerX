//
// Created by CiaranWelsh on 29/12/2019.
//

#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "iostream"
#include "game/Pot.h"
#include "game/Players.h"
#include "players/CallStation.h"

using namespace std;
using namespace game;

class PlayersTests : public ::testing::Test {
protected:
    Players players = Players::callStations(9);
};

TEST_F(PlayersTests, TestPositions1) {
    std::string expected = "player4";
    ostringstream actual;
    actual << players[4]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestRotate) {
    std::string expected = "player5";
    players.rotate();
    ostringstream actual;
    actual << players[4]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestCurrentPlayer) {
    std::string expected = "player0";
    ostringstream actual;
    actual << players.getCurrentPlayer()->getName();
    ASSERT_EQ(expected, actual.str());
}
TEST_F(PlayersTests, TestCurrentPlayerIsUpdatedAfterRotate) {
    std::string expected = "player1";
    players.rotate();
    ostringstream actual;
    actual << players.getCurrentPlayer()->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestNextPlayer) {
    std::string expected = "player3";
    players.next_player();
    players.next_player();
    ostringstream actual;
    actual << players[1]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestAddPLayerIntoPosition5) {
    std::string expected = "NewPlayer";
    PlayerPtr new_player(new CallStation("NewPlayer"));
    players.addPlayer(new_player, 5);
    ostringstream actual;
    actual << players[5]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestCallStationsStaticMethod) {
    players = Players::callStations(6);
    int expected = 6;
    int actual = players.size();
    ASSERT_EQ(expected, actual);
}

TEST_F(PlayersTests, TestOstream) {
    players = Players::callStations(6);
    std::string expected = R"([Player(name="player0", stack=10), Player(name="player1", stack=10), Player(name="player2", stack=10), Player(name="player3", stack=10), Player(name="player4", stack=10), Player(name="player5", stack=10)]])";
    ostringstream stream;
    stream << players;
    ASSERT_EQ(expected, stream.str());
}
