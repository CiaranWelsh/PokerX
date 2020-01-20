//
// Created by CiaranWelsh on 27/12/2019.
//

#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "iostream"
#include "players/FoldStation.h"

using namespace std;

TEST(PlayerTests, TestOstreamOperator) {
    CallStation callStation("Boid");
    string expected = "Player(name=\"Boid\", stack=0)";
    ostringstream actual;
    actual << callStation;
    cout << callStation;
    ASSERT_EQ(expected, actual.str());
}

TEST(PlayerTests, TestCallStationType) {
    CallStation callStation("Boid");
    std::string expected = "CallStation";
    std::string actual = callStation.getType();
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestFoldStationType) {
    FoldStation foldStation("Boid");
    std::string expected = "FoldStation";
    std::string actual = foldStation.getType();
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestYouCanSetInplay) {
    FoldStation foldStation("Boid");
    foldStation.inplay  = false;
    ASSERT_FALSE(foldStation.inplay);
}

TEST(PlayerTests, TestYouCanSetInplayFromPtr) {
    FoldStation foldStation("Boid");
    foldStation.inplay = false;
    std::shared_ptr<Player> foldStationPtr = std::make_shared<Player>(foldStation);
    ASSERT_FALSE(foldStationPtr->inplay);
}



//TEST(PlayerTests, TestFolder){
//    FoldStation foldStation("nag");
//    cout << foldStation << endl;
//    cout << foldStation.getType() << endl;
//    string expected = "Player(name=\"\", stack=0)";
//    ostringstream actual;
//    actual << callStation;
//    cout << callStation;
//    ASSERT_EQ(expected, actual.str());
//}

