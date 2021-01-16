//
// Created by Ciaran on 16/01/2021.
//

#include "LightHigh.h"
#include "LightOff.h"
#include "eState.h"

void LightHigh::action(StateMachine *machine) {
    machine->setState(LightOff::getInstance());
};

LightHigh &LightHigh::getInstance() {
    static LightHigh singleton;
    return singleton;
}

unsigned int LightHigh::getType() const {
    return type_;
}

