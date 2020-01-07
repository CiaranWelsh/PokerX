/**
 * Project PokerSimulationsInCpp
 */
#include "errors.h"
#include "Player.h"
#include "typeinfo"
#include <boost/type_index.hpp>
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

ostream &operator<<(ostream &os, Player &player) {
    os << player.type << "(name=\"" << player.getName() << "\", stack=" << player.stack << ")";
    return os;
}

void Player::play(ActionType action, double amount) {
    switch (action){
        case Raise:
            cout << "player " << getName() << " raised" << endl;
            pot += amount;
            stack -= amount;
            break;
        case Call:
            cout << "player " << getName() << " called" << endl;
            pot += amount;
            stack -= amount;
            break;
        case Fold:
            cout << "player " << getName() << " folded" << endl;
            break;
        case Check:
            cout << "player " << getName() << " checked" << endl;
            break;
            ;
    }
}

Player::Player(Player &player) {
    stack = player.stack;
    _name = player.getName();
}

std::string Player::getType() {
    return type;
}


Player::~Player() = default;
