//
// Created by CiaranWelsh on 20/01/2020.
//

#include "Checker.h"

ActionType Checker::choose_action(std::shared_ptr<std::vector<ActionType>> actions) {
    return Check;
}

std::string Checker::getType() {
    return type;
}
