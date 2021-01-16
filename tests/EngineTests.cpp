//
// Created by Ciaran on 10/01/2021.
//


//#include "gmock/gmock.h"
//#include "gtest/gtest.h"

//#include "engine/NoLimitHoldem.h"
//
//using namespace testing;
//using namespace engine;
//
//class EngineTests : public ::testing::Test {
//public:
//    EngineTests() = default;
//};
//
//TEST_F(EngineTests, TestPlayersInstantiatedWhenEngineCreated){
//    NoLimitHoldem engine;
//    const std::vector<Player*> &players = engine.getPlayers();
//
//}

// fwd declaration
//class StateMachine;
//
//class State {
//public:
//    virtual void action(StateMachine *engine) = 0;
//
//    virtual ~State() = default;
//};
//
//class StateMachine {
//public:
//    StateMachine() = default;
//
//    explicit StateMachine(State &state) : state_(&state) {};
//
//    virtual void setState(State &state) {
//        state_ = &state;
//    }
//
//    [[nodiscard]] virtual State *getState() const {
//        return state_;
//    }
//
//protected:
//    State *state_ = nullptr;
//
//};
//
//class DerivedStateMachine : public StateMachine {
//public:
//    using StateMachine::StateMachine;
//
//    int doSpecializedThings(){
//        return special_thing_;
//    }
//
//    void setSpecialState(int specialState) {
//        special_thing_ = specialState;
//    }
//
//private:
//    int special_thing_;
//};
//
//class DerivedStateDependsOnGeneralStateMachine : public State {
//
//    virtual void action(StateMachine *engine) {
//        int important_value = engine->doSpecializedThings();
//    };
//
//};
//
//class DerivedStateDependsOnDerivedStateMachine : public State {
//
//    void action(DerivedStateMachine *engine) override {
//        engine->doSpecializedThings();
//    };
//
//};
//
//
//int main(){
//
//}




#include <iostream>

class StateMachine; //fwd

class State {
public:
    virtual void action(StateMachine *engine) = 0;

    virtual ~State() = default;
};

class StateMachine {
public:
    StateMachine() = default;

    explicit StateMachine(State &state) : state_(&state) {};

    virtual void setState(State &state) {
        state_ = &state;
    }
    virtual void setState(int state) {};

    [[nodiscard]] virtual State *getState() const {
        return state_;
    }

    virtual int doSpecializedThings(){
        std::cout << "Do StateMachine things (or nothing)" << std::endl;
        return 0;
    }

protected:
    State *state_ = nullptr;

};

class DerivedStateDependsOnGeneralStateMachine : public State {
public:

    virtual void action(StateMachine *engine) {
        int important_value = engine->doSpecializedThings();
    };

};

class DerivedStateDependsOnDerivedStateMachine : public State {
public:
    void action(StateMachine *engine) override {
        engine->doSpecializedThings();
    };

};

class DerivedStateMachine : public StateMachine {
public:
    using StateMachine::StateMachine;

    int doSpecializedThings(){
        std::cout << "Do DerivedStateMachine things " << std::endl;
        return special_thing_;
    }

    void setState(int specialState) {
        special_thing_ = specialState;
    }

private:
    int special_thing_;
};

class AnotherDerivedStateMachine : public StateMachine {
public:
    using StateMachine::StateMachine;

    int doSpecializedThings(){
        std::cout << "Do AnotherDerivedStateMachine things and" << std::endl;
        std::cout << "\tcalling base class: ";
        StateMachine::doSpecializedThings();
        return special_thing_;
    }

    void setState(int specialState) {
        special_thing_ = specialState;
    }

private:
    int special_thing_;
};

int main()
{
    StateMachine sm;
    DerivedStateMachine dsm;
    AnotherDerivedStateMachine adsm;
    DerivedStateDependsOnGeneralStateMachine dsmg;
    DerivedStateDependsOnDerivedStateMachine dsmd;

    sm.setState (dsmg);

    StateMachine * pdsm = &dsm;
    pdsm->setState (dsmd);
    dsm.setState (1);

    dsmg.action (&dsm);
    dsmd.action (&dsm);

    dsmg.action (&sm);
    dsmd.action (&sm);

    dsmd.action (&adsm);

    return 0;
}









