/**
 * Project PokerSimulationsInCpp
 */
#include "Errors.h"
#include "Player.h"
#include "ActionType.h"
#include <iostream>
#include <utility>
#include "game/GamePlay.h"

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

void Player::play(game::GamePlay &gamePlay, ActionType action, double amount) {
    switch (action) {
        case Raise:
            cout << "player " << getName() << " raised" << endl;
            if (amount < gamePlay.largest_bidder_amount)
                throw errors::ValueError("Amount raised is less that existing bid", __FILE__, __LINE__);
            if (amount > stack) {
                // if call amount > stack, call recursively with AllIn
                play(gamePlay, AllIn, stack);
            }

            gamePlay.largest_bidder_amount = amount;
            pot += amount;
            stack -= amount;
            break;
        case Call:
            cout << "player " << getName() << " called" << endl;
            if (amount > stack) {
                // if call amount > stack, call recursively with AllIn
                play(gamePlay, AllIn, stack);
            }
            pot += amount;
            stack -= amount;
            break;
        case Fold:
            cout << "player " << getName() << " folded" << endl;
            inplay = false;
            break;
        case Check:
            cout << "player " << getName() << " checked" << endl;
            break;
        case AllIn:
            cout << "player " << getName() << " AllIn" << endl;
            all_in = true;
            pot += stack;
            stack -= stack;
            break;
        case NoAction:
            throw errors::InvalidActionError("You should never get "
                                             "to NoAction", __FILE__, __LINE__);
    }
    cout << "Player " << getName() << "with remaining stack " << stack << " has " << pot << " in their own ";
    cout << "pot and there is a total of "<< gamePlay.pot << "in the main pot" << endl;
}

Player::Player(Player &player) {
    stack = player.stack;
    _name = player.getName();
}

std::string Player::getType() {
    return type;
}


Player::~Player() = default;
