//
// Created by CiaranWelsh on 27/12/2019.
//

#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "iostream"
#include "game/Pot.h"

using namespace std;


TEST(PotTests, TestPotEmpty){
    Pot pot;
    ASSERT_EQ(0, pot.value);
}

TEST(PotTests, TestPotValue){
    Pot pot(10);
    ASSERT_EQ(10, pot.value);
}

TEST(PotTests, TestCopyConstructor){
    Pot pot1(10);
    Pot pot2(pot1);
    std::cout << pot1 << endl;
    std::cout << pot2;
    ASSERT_EQ(10, pot2.value);
}


TEST(PotTests, TestPlusOverload){
    Pot pot1(10);
    Pot pot2(50);
    Pot pot3 = pot1 + pot2;
    ASSERT_EQ(60, pot3.value);
}

TEST(PotTests, TestMinusOverload){
    Pot pot1(10);
    Pot pot2(50);
    Pot pot3 = pot2 - pot1;
    ASSERT_EQ(40, pot3.value);
}











