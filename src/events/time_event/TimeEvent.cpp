//
// Created by CiaranWelsh on 02/01/2020.
//

#include <dshow.h>
#include "TimeEvent.h"


namespace events {

    TargetType TimeEvent::getTarget() {
        return target;
    }

    std::string TimeEvent::getDescription() {
        return description;
    }

    bool TimeEvent::getDone() {
        return done;
    }

    std::string TimeEvent::getId() {
        return id;
    }

}
