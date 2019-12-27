/**
 * Project PokerSimulationsInCpp
 */
#include "errors.h"
#include "Player.h"
#include "ActionType.h"
#include <iostream>
#include <utility>
/**
 * Player implementation
 */
Player::Player() = default;


Player::Player(std::string name) {
    this->_name = std::move(name);
}


std::string Player::getName() {
    return _name;
}

void Player::setName(std::string name) {
    _name = std::move(name);

}

ostream& operator<<(ostream& os, Player& player) {
    os << "Player(\"name\"=" << player.getName() << ", stack=" << player.stack << ")";
    return os;
}

ActionType Player::play() {
    throw errors::NotImplementedException();
}
