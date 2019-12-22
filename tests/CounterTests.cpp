//
// Created by CiaranWelsh on 21/12/2019.
//

#include "gtest/gtest.h"
#include <string>
#include <utils/Counter.h>


TEST(CounterTests, test1) {
    std::vector<std::string> x = {"A", "A", "B", "B", "C", "D", "D", "D"};
    Counter<std::string> counter(x);
    std::unordered_map<std::string, int> count = counter.count();
    ASSERT_TRUE(count["D"] == 3);
    ASSERT_TRUE(count["A"] == 2);
    ASSERT_TRUE(count["B"] == 2);
    ASSERT_TRUE(count["C"] == 1);
}









