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
            CallStation cs(name.str());
            cout << cs << endl;
            positions.addPlayer(&cs);
            name.flush();
        };
    }
};

TEST_F(PositionsTests, Test1) {
    cout << "here" << endl;
//    CallStation pl_ptr = positions[4];
//    cout << *pl_ptr << endl;
//    cout << pl_ptr->getName() << endl;
//    cout << *positions[4] << endl;
}
