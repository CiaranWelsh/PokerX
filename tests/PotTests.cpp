//
// Created by CiaranWelsh on 27/12/2019.
//

#include "gtest/gtest.h"
#include "iostream"
#include "engine/Pot.h"

using namespace std;


TEST(PotTests, TestPotEmpty){
    Pot pot;
    ASSERT_TRUE(pot == 0);
}

TEST(PotTests, TestPotValue){
    Pot pot(10);
    ASSERT_TRUE(pot == 10);
}

TEST(PotTests, TestPlusOverload){
    Pot pot1(10);
    Pot pot2(50);
    Pot pot3 = pot1 + pot2;
    ASSERT_TRUE(pot3 == 60);
}

TEST(PotTests, TestMinusOverload){
    Pot pot1(10);
    Pot pot2(50);
    Pot pot3 = pot2 - pot1;
    ASSERT_TRUE(pot3 == 40);
}

TEST(PotTests, TestAddInt){
    Pot pot1(10);
    pot1 += 5;
    ASSERT_TRUE(pot1 == 15);
}

TEST(PotTests, TestAddDouble){
    Pot pot1(10);
    pot1 += 5.0;
    ASSERT_TRUE(pot1 == 15.0);
}


TEST(PotTests, TestNotEqual){
    Pot pot1(10);
    pot1 += 5.0;
    ASSERT_TRUE(pot1 != 5.0);
}

TEST(PotTests, TestaddInt2){
    Pot pot1(10);
    pot1 += 0.5;
    ASSERT_TRUE(pot1 == 10.5);
}

TEST(PotTests, SetPotTo0){
    Pot pot(10);
    pot.reset();
    ASSERT_TRUE(pot == 0);
}











