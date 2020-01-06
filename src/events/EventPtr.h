//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_EVENTPTR_H
#define POKERSIMULATIONSINCPP_EVENTPTR_H

#include <memory>
#include "Event.h"

namespace events {

    typedef std::shared_ptr<Event> EventPtr;

}

#endif //POKERSIMULATIONSINCPP_EVENTPTR_H
