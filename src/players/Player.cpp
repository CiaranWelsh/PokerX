/**
 * Project PokerSimulationsInCpp
 */
#include "Error.h"
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
    this->name = std::move(name);
}


std::string Player::getName() {
    return name;
}

void Player::setName(std::string name) {
    name = std::move(name);

}

ostream &operator<<(ostream &os, Player &player) {
    os << player.type << "(name=\"" << player.getName() << "\", stack=" << player.stack << ")";
    return os;
}

void Player::play(game::GamePlay &gamePlay, ActionType action, double amount) {
    played_this_street = true;
    switch (action) {
        case Raise:
//            cout << "player " << getName() << " raised" << endl;
            if (amount < gamePlay.largest_bidder_amount)
                throw errors::ValueError("Amount raised is less that existing bid", __FILE__, __LINE__);
            if (amount > stack) {
                // if call amount > stack, call recursively with AllIn
                play(gamePlay, AllIn, stack);
            }
            cout << endl;
            cout << "raiser stack: " << stack << ", raiser pot amount << " << pot << endl;
            gamePlay.largest_bidder_amount = amount;
            pot += amount;
            stack -= amount;
            cout << "raiser stack: " << stack << ", raiser pot amount << " << pot << endl;
            cout << endl;
            break;
        case Call:
//            cout << "player " << getName() << " called" << endl;
            if (amount > stack) {
                // if call amount > stack, call recursively with AllIn
                play(gamePlay, AllIn, stack);
            }
            pot += amount;
            stack -= amount;
            break;
        case Fold:
//            cout << "player " << getName() << " folded" << endl;
            inplay = false;
            break;
        case Check:
//            cout << "player " << getName() << " checked" << endl;
            break;
        case AllIn:
//            cout << "player " << getName() << " AllIn" << endl;
            all_in = true;
            pot += stack;
            stack -= stack;
            break;
        case NoAction:
            throw errors::InvalidActionError("You should never get "
                                             "to NoAction", __FILE__, __LINE__);
    }
//    cout << "Player " << getName() << "with remaining stack " << stack << " has " << pot << " in their own ";
//    cout << "pot and there is a total of "<< gamePlay.pot << "in the main pot" << endl;
}

Player::Player(Player &player) {
    name = player.getName();
    type = player.getType();
    holeCards = player.holeCards;
    stack = player.stack;
    inplay = player.inplay;
    pot = player.pot;
    played_this_street = player.played_this_street;
    all_in = player.all_in;

}

std::string Player::getType() {
    return type;
}

eval::Hand Player::getHand(game::GamePlay &gamePlay) {
    return eval::Hand(holeCards, gamePlay.communityCards);
}

void Player::reset() {
    pot = 0;
    HoleCards newHoleCards;
    holeCards = newHoleCards;
    inplay = true;
    played_this_street = false;
    all_in = false;
}

Player::Player(std::string name, HoleCards holeCards) {
    this->holeCards = holeCards;
    this->name = name;
}

Player &Player::operator=(Player &player) {
    this->holeCards = player.holeCards;
    this->pot = player.pot;
    this->stack = player.stack;
    this->inplay = player.inplay;
    this->played_this_street = player.played_this_street;
    this->all_in = player.all_in;
    return *this;
}


Player::~Player() = default;
