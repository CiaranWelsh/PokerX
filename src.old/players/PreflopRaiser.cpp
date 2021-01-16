//
// Created by CiaranWelsh on 20/01/2020.
//

#include "PreflopRaiser.h"

ActionType PreflopRaiser::choose_action(std::shared_ptr<std::vector<ActionType>> actions) {

    return Player::choose_action(actions);
}

std::string PreflopRaiser::getType() {
    return type;
}
