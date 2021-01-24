#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PokerX/engine/Container.h"
#include "PokerX/engine/RotatoryContainer.h"
#include <vector>

/**
 * I'm considering all containers part of this unit
 */
using namespace pokerx;
using namespace testing;

class ContainerTests : public ::testing::Test {
public:

    ContainerTests() = default;
};

TEST_F(ContainerTests, CreateContainerOfIntsUsingInitializerList){
    using IntContainer = Container<int>;
    IntContainer container({1, 2, 3});
    std::vector<int> x({1, 2, 3});
    ASSERT_EQ(container.getContents(), x);
}
class RotatoryContainerTests : public ::testing::Test {
public:

    RotatoryContainerTests() = default;
};

TEST_F(ContainerTests, TestThatRotationFunctionOfRotatoryContainerWorksWithInputSize1){
    using RotatoryIntContainer = RotatoryContainer<int>;
    RotatoryIntContainer container({1});
    std::vector<int> x({1});
    container.rotateContainerContents();
    ASSERT_EQ(container.getContents(), x);
}
TEST_F(ContainerTests, TestThatRotationFunctionOfRotatoryContainerWorksWithInputSize2){
    using RotatoryIntContainer = RotatoryContainer<int>;
    RotatoryIntContainer container({1, 2});
    std::vector<int> x({2, 1});
    container.rotateContainerContents();
    ASSERT_EQ(container.getContents(), x);
}

TEST_F(ContainerTests, TestThatRotationFunctionOfRotatoryContainerWorksWithInputSizeGreaterThan2) {
    using RotatoryIntContainer = RotatoryContainer<int>;
    RotatoryIntContainer container({1, 2, 3});
    std::vector<int> x({3, 1, 2});
    container.rotateContainerContents();
    ASSERT_EQ(container.getContents(), x);
}