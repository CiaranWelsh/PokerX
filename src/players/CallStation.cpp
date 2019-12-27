/**
 * Project PokerSimulationsInCpp
 */


#include "CallStation.h"

#include <utility>
#include "ActionType.h"

/**
 * CallStation implementation
 */
CallStation::CallStation() : Player(){};

CallStation::CallStation(std::string name) : Player(std::move(name)){}

ActionType CallStation::play() {
    return Call;
}
