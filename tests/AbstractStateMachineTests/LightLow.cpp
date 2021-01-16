//
// Created by Ciaran on 16/01/2021.
//

#include "LightLow.h"
#include "LightHigh.h"
#include "enumState.h"

void LightLow::action(StateMachine *machine) {
    machine->setState(LightHigh::getInstance());
};

LightLow &LightLow::getInstance() {
    static LightLow singleton;
    return singleton;
}

unsigned int LightLow::getType() const {
    return type_;
}
