//
// Created by CiaranWelsh on 02/01/2020.
//

#include "PlayerEvent.h"



namespace events{

    TargetType PlayerEvent::getTarget() {
        return target;
    }

    std::string PlayerEvent::getDescription() {
        return description;
    }

    bool PlayerEvent::getDone() {
        return done;
    }

    std::string PlayerEvent::getId() {
        return id;
    }
}