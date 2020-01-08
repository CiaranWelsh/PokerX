//
// Created by CiaranWelsh on 08/01/2020.
//


#include "gtest/gtest.h"
#include <string>
#include <utils/Counter.h>
#include "Errors.h"

TEST(ErrorsTests, TestException){
    int number = 4;
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    if (number == 4){
        throw errors::NotImplementedError("e", __FILE__, __LINE__ );
    }
}














