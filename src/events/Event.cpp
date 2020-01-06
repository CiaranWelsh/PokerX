//
// Created by CiaranWelsh on 02/01/2020.
//

#include "Event.h"
#include <iostream>
#include <dshow.h>

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

    void Event::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
        throw errors::NotImplementedException();
    }

    Event::~Event() = default;

    Event::Event() = default;
}



