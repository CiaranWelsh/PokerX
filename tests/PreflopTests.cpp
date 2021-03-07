#include <utility>

#include "gtest/gtest.h"
#include "Mockups/MockGameVariables.h"
#include "Mockups/MockPlayerManager.h"
#include "Mockups/MockPlayer.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/Pot.h" // not mocked. Too simple.


class PreflopTests : public ::testing::Test {
public:
    MockGameVariables gameVariables;
    MockPlayerManager playerManager;
    std::shared_ptr<MockPlayer> p1;
    std::shared_ptr<MockPlayer> p2;
    std::shared_ptr<MockPlayer> p3;
    std::shared_ptr<MockPlayer> p4;
    std::shared_ptr<MockPlayer> p5;
    std::shared_ptr<MockPlayer> p6;
    PreflopTests() {
        p1 = makePlayer("DrLevty", 10.01);
        p2 = makePlayer("OhhhJeee", 4.86);
        p3 = makePlayer("gokudousan", 5.81);
        p4 = makePlayer("aka_Kranv1ch", 10);
        p5 = makePlayer("Malyar-88", 3.97);
        p6 = makePlayer("Lorn_Antoan", 10.25);
    };

    std::shared_ptr<MockPlayer> makePlayer(const std::string& name, float stack){
        std::shared_ptr<MockPlayer> p = std::make_shared<MockPlayer>();
        ON_CALL(*p, getName)
            .WillByDefault(ReturnRef(name));
        ON_CALL(*p, getStack)
            .WillByDefault(Return(stack));
        return p;
    }
};

/**
 * PokerStars Hand #222947450188:  Hold'em No Limit ($0.05/$0.10 USD) - 2021/01/23 3:08:58 ET
 * Table 'Aaryn II' 6-max Seat #1 is the button
 * Seat 1: DrLevty ($10.01 in chips)
 * Seat 2: Ohhh Jeee ($4.86 in chips)
 * Seat 3: gokudousan ($8.51 in chips)
 * Seat 4: aka_Kranv1ch ($10 in chips)
 * Seat 5: Malyar-88 ($3.97 in chips)
 * Seat 6: Lord_Antoan ($10.25 in chips)
 * Ohhh Jeee: posts small blind $0.05
 * gokudousan: posts big blind $0.10
 */
TEST_F(PreflopTests, CheckSmallBlindPays5Cents){

    // prime the pot for returning the correct amount
    Pot pot(0.05);
    ON_CALL(gameVariables, getPot)
        .WillByDefault(ReturnRef(pot));

    // first call to action resets the game, calls watch for initialize observer
    // and gets the next player ready.
    EXPECT_CALL(gameVariables, reset).Times(1);
    EXPECT_CALL(playerManager, reset).Times(1);
    EXPECT_CALL(playerManager, watch).Times(1);
    // (remember that reset is tested in the units for
    // gamevariables and playerManager separetly, they are
    // not under test here so assume they work correctly)

    PokerEngine engine(&playerManager, &gameVariables);

    ON_CALL(playerManager, getCurrentPlayer)
        .WillByDefault(Return(p2));
    ASSERT_STREQ("Ohhh Jeee",
            playerManager.getCurrentPlayer()->getName().c_str()
    );



    // get the SB player. Get his stack
    // Get the pot an check amount


    engine.action(1);

}


//
///**
// * Interface for X
// */
//class AbstractX {
//
//    virtual int getNumber() const = 0;
//};
//
//
///**
// * Holds a number
// */
//class X : public AbstractX {
//public:
//    X() = default;
//    explicit X(int x): number(x){};
//
//    [[nodiscard]] int getNumber() const override {
//        return number;
//    }
//private:
//    int number;
//};
//
///**
// * Interfact for Y
// */
//class AbstractY {
//
//    virtual std::shared_ptr<X> getPtrToX() = 0;
//};
//
///**
// * Implementation of Y. Has method that returns shared
// * pointer to X
// */
//class Y : public AbstractY{
//public:
//    Y() = default;
//
//    explicit Y(X x): xPtr(std::make_shared<X>(x)){};
//
//    std::shared_ptr<X> getPtrToX() override{
//        return xPtr;
//    }
//
//private:
//    std::shared_ptr<X> xPtr;
//};
//
//class MockedX : public AbstractX {
//public:
//    MOCK_METHOD(int, getNumber, (), (const, override));
//
//};
//
//class MockedY : public AbstractY {
//public:
//    MOCK_METHOD(std::shared_ptr<X>, getPtrToX, (), (override));
//};
//
//
///**
// * Z uses both X and Y. When Z is under test,
// * we use mocks of both X and Y.
// */
//class Z {
//public:
//    Z() = default;
//
//    Z(std::shared_ptr<AbstractX> x, std::shared_ptr<AbstractY> y)
//        : x_(std::move(x)), y_(std::move(y)){};
//
//    void doSomethingCool(){
//
//    }
//
//private:
//    std::shared_ptr<AbstractX> x_;
//    std::shared_ptr<AbstractY> y_;
//
//};
//
//
//TEST(UnitTestForZ, test){
//    MockedY y;
//    MockedX x;
//    std::shared_ptr<MockedX> sharedX = std::make_shared<MockedX>(MockedX());
//    //Z z(&x, &y);
////    z.doSomethingCool();
//
//
//
//}




























