//
// Created by CiaranWelsh on 29/12/2019.
//

#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "iostream"
#include "game/Pot.h"
#include "game/Positions.h"
#include "players/CallStation.h"

using namespace std;
using namespace game;

class PositionsTests : public ::testing::Test {
protected:
    Positions positions;
public:
    PositionsTests() {
        for (int i = 0; i < 9; i++) {
            ostringstream name;
            name << "player"<< i;
            PlayerPtr ptr(new CallStation(name.str()));
            positions.addPlayer(ptr);
            name.flush();
        };
    }
};

TEST_F(PositionsTests, TestPositions1) {
    std::string expected = "player4";
    ostringstream actual;
    actual << positions[4]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PositionsTests, TestRotate) {
    std::string expected = "player5";
    positions.rotate();
    ostringstream actual;
    actual << positions[4]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PositionsTests, TestAddPLayerIntoPosition5) {
    std::string expected = "NewPlayer";
    PlayerPtr new_player(new CallStation("NewPlayer"));
    positions.addPlayer(new_player, 5);
    ostringstream actual;
    actual << positions[5]->getName();
    ASSERT_EQ(expected, actual.str());
}

TEST_F(PositionsTests, TestCallStationsStaticMethod) {
    positions = Positions::callStations(6);
    int expected = 6;
    int actual = positions.size();
    ASSERT_EQ(expected, actual);
}
