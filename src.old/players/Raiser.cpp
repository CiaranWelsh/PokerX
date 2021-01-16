//
// Created by CiaranWelsh on 20/01/2020.
//

#include "Raiser.h"

ActionType Raiser::choose_action(std::shared_ptr<std::vector<ActionType>> actions) {
    return Raise;
}

std::string Raiser::getType() {
    return type;
}
