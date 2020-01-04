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
    Players positions;
public:
    PlayersTests() {
        for (int i = 0; i < 9; i++) {
            ostringstream name;
            name << "player"<< i;
            PlayerPtr ptr(new CallStation(name.str()));
            positions.addPlayer(ptr);
            name.flush();
        };
    }
};

TEST_F(PlayersTests, TestPositions1) {
    std::string expected = "player4";
    ostringstream actual;
    actual << positions[4]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestRotate) {
    std::string expected = "player5";
    positions.rotate();
    ostringstream actual;
    actual << positions[4]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestAddPLayerIntoPosition5) {
    std::string expected = "NewPlayer";
    PlayerPtr new_player(new CallStation("NewPlayer"));
    positions.addPlayer(new_player, 5);
    ostringstream actual;
    actual << positions[5]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PlayersTests, TestCallStationsStaticMethod) {
    positions = Players::callStations(6);
    int expected = 6;
    int actual = positions.size();
    ASSERT_EQ(expected, actual);
}

TEST_F(PlayersTests, TestOstream) {
    positions = Players::callStations(6);
    std::string expected = R"([Player(name="player0", stack=10), Player(name="player1", stack=10), Player(name="player2", stack=10), Player(name="player3", stack=10), Player(name="player4", stack=10), Player(name="player5", stack=10)]])";
    ostringstream stream;
    stream << positions;
    ASSERT_EQ(expected, stream.str());
}
