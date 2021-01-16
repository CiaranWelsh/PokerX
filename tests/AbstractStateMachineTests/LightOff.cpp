//
// Created by Ciaran on 16/01/2021.
//

#include "LightOff.h"
#include "LightLow.h"
#include "enumState.h"

void LightOff::action(StateMachine *machine) {
    machine->setState(LightLow::getInstance());
};

LightOff &LightOff::getInstance() {
    static LightOff singleton;
    return singleton;
}

unsigned int LightOff::getType() const {
    return type_;
}
