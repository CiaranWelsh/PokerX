//
// Created by Ciaran on 08/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PokerX/engine/RestrictedCardCollection.h"
#include "Mockups/MockCard.h"

using namespace testing;

class RestrictedCardCollectionTests : public ::testing::Test {

public:

    MockCard twoOfClubs;
    MockCard fiveOfDiamonds;
    MockCard sixOfDiamonds;

    RestrictedCardCollectionTests() {
        ON_CALL(twoOfClubs, getRank()).WillByDefault(Return(2));
        ON_CALL(twoOfClubs, getSuit()).WillByDefault(Return("C"));

        ON_CALL(fiveOfDiamonds, getRank()).WillByDefault(Return(5));
        ON_CALL(fiveOfDiamonds, getSuit()).WillByDefault(Return("D"));

        ON_CALL(sixOfDiamonds, getRank()).WillByDefault(Return(6));
        ON_CALL(sixOfDiamonds, getSuit()).WillByDefault(Return("D"));
    };
};

/**
 * The RestrictedCardCollection should be inherited so we test this functionality here
 */
class TwoCards : public RestrictedCardCollection {

public:

    using RestrictedCardCollection::RestrictedCardCollection;

    using RestrictedCardCollection::add;

    explicit TwoCards(const std::vector<ICardPtr> &cards)
            : RestrictedCardCollection(cards, 2) {}
};

TEST_F(RestrictedCardCollectionTests, TestContainerCanHoldTwoCards) {
    TwoCards cards({"2C", "5D"});
    ASSERT_EQ(2, cards.size());
}

TEST_F(RestrictedCardCollectionTests, CheckErrorWhenTryToAddMoreThan2Cards) {
    TwoCards cards({"2C", "5D"});
    ASSERT_THROW(cards.add({"6D"}), std::logic_error);
}


TEST_F(RestrictedCardCollectionTests, CheckErrorWhenTryToInitializeWithMoreThan2Cards) {
    ASSERT_THROW(
            TwoCards cards({"2C", "5D", "6D"}),
            std::logic_error
    );
}








