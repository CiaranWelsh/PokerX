/**
 * Project PokerSimulationsInCpp
 */


#include "CallStation.h"

#include <utility>
#include "ActionType.h"
#include "Error.h"

/*
 * CallStation implementation
 */

ActionType CallStation::choose_action(std::shared_ptr<std::vector<ActionType>> actions) {
    bool check_available = std::find(actions->begin(), actions->end(), Check) != actions->end();
    ActionType action;
    if (check_available)
        action = Check;
    else
        action = Call;
    return action;
}

std::string CallStation::getType() {
    return type;
}



