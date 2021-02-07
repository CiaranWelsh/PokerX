#include "gtest/gtest.h"
#include "PokerX/engine/Policy.h"

using namespace pokerx;
class PolicyTests  : public ::testing::Test {
public:
    PolicyTests () = default;
};

TEST_F(PolicyTests, CheckNextActionOrder){
    Policy policy({CHECK, CALL, FOLD});
    Action one = policy.nextAction();
    ASSERT_EQ(CHECK, one);
    Action two = policy.nextAction();
    ASSERT_EQ(CALL, two);
    Action three = policy.nextAction();
    ASSERT_EQ(FOLD, three);
    Action four = policy.nextAction();
    ASSERT_EQ(CHECK, four);

}


























