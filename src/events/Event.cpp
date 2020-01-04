//
// Created by CiaranWelsh on 02/01/2020.
//

#include "Event.h"


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

    Event::~Event() = default;

    Event::Event() = default;
}




