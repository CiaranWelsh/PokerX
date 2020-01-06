//
// Created by CiaranWelsh on 02/01/2020.
//

#include "Event.h"
#include <iostream>

namespace events {

    TargetType Event::getTarget() {
        return target;
    }

    std::string Event::getDescription() {
        return description;
    }

    bool Event::getDone() {
        return done;
    }

    std::string Event::getId() {
        return id;
    }

    void Event::go(game::GamePlay &gamePlay) {}

    Event::~Event() = default;

    Event::Event() = default;
}



