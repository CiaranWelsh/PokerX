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

TEST_F(PlayersTests, TestPreviousPlayer) {
    std::string expected = "player8";
    players.previous_player();
    ostringstream actual;
    actual << players.getCurrentPlayer()->getName();
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

TEST_F(PlayersTests, AllPlayersNotEqual) {
    players = Players::callStations(6);
    players[1]->pot = 30;
    players[2]->pot = 50;
    bool actual = players.checkAllPlayersEqual();
    ASSERT_FALSE(actual);

}

TEST_F(PlayersTests, AllPlayersEqual) {
    players = Players::callStations(6);
    players[0]->pot = 50;
    players[1]->pot = 50;
    players[2]->pot = 50;
    players[3]->pot = 50;
    players[4]->pot = 50;
    players[5]->pot = 50;
    bool actual = players.checkAllPlayersEqual();
    ASSERT_TRUE(actual);
}

TEST_F(PlayersTests, TestNoPlayersHavePlayedAStreet) {
    players = Players::callStations(6);
    players[0]->played_this_street = false;
    players[1]->played_this_street = false;
    players[2]->played_this_street = false;
    players[3]->played_this_street = false;
    players[4]->played_this_street = false;
    players[5]->played_this_street = false;
    bool actual = players.noPlayersPlayedThisStreet();
    ASSERT_TRUE(actual);
}

TEST_F(PlayersTests, TestSomePlayersHavePlayedAStreet) {
    players = Players::callStations(6);
    players[0]->played_this_street = false;
    players[1]->played_this_street = false;
    players[2]->played_this_street = false;
    players[3]->played_this_street = false;
    players[4]->played_this_street = true;
    players[5]->played_this_street = false;
    bool actual = players.noPlayersPlayedThisStreet();
    ASSERT_FALSE(actual);
}




