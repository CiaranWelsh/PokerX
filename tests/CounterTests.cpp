//
// Created by CiaranWelsh on 21/12/2019.
//

#include "gtest/gtest.h"
#include <string>
#include <PokerX/engine/Counter.h>

class CounterTests : public ::testing::Test {
public:
    CounterTests() = default;
};

TEST_F(CounterTests, teststring) {
    std::vector<std::string> x = {"A", "A", "B", "B", "C", "D", "D", "D"};
    Counter<std::string> counter(x);
    std::unordered_map<std::string, int> count = counter.count();
    ASSERT_TRUE(count["D"] == 3);
    ASSERT_TRUE(count["A"] == 2);
    ASSERT_TRUE(count["B"] == 2);
    ASSERT_TRUE(count["C"] == 1);
}

TEST_F(CounterTests, testInt) {
    std::vector<int> x = {1, 1, 1, 4, 4, 4, 6, 6, 6, 7, 7, 7, 4, 3, 3};
    Counter<int> counter(x);
    std::unordered_map<int, int> count = counter.count();
    ASSERT_TRUE(count[1] == 3);
    ASSERT_TRUE(count[4] == 4);
    ASSERT_TRUE(count[6] == 3);
    ASSERT_TRUE(count[7] == 3);
    ASSERT_TRUE(count[3] == 2);
}











