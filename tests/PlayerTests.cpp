//
// Created by CiaranWelsh on 27/12/2019.
//

#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "iostream"

using namespace std;

TEST(PlayerTests, test_ostream_operator){
    CallStation callStation("Boid");
    string expected = "Player(name=\"Boid\", stack=0)";
    ostringstream actual;
    actual << callStation;
    cout << callStation;
    ASSERT_EQ(expected, actual.str());
}