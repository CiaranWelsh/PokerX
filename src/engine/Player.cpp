//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/Player.h"
#include <ostream>
#include <utility>

namespace pokerx {

    Player::Player(std::string name, float stack)
        :  name_(std::move(name)), stack_(stack){}

    std::ostream &operator<<(std::ostream &os, Player &player) {
        os << player.getName() << "(stack=" << player.getStack() << ")" << std::endl;
        return os;
    }

    void Player::update(GameVariables &source, const string &data_field) {
        // store the reference
        gameVariables_ = &source;
    }

    GameVariables *Player::getGameVariables() const {
        return gameVariables_;
    }

    const std::string &Player::getName() const {
        return name_;
    }

    void Player::setName(const std::string &name) {
        name_ = name;
    }

    float Player::getStack() const {
        return stack_;
    }

    void Player::setStack(float stack) {
        stack_ = stack;
    }

    [[nodiscard]] bool Player::isAllIn() const {
        return stack_ == 0.0;
    }

    void Player::setIsAllIn(bool isAllIn) {
        isAllIn_ = isAllIn;
    }

    bool Player::isInPlay() const {
        return isInPlay_;
    }

    void Player::setIsInPlay(bool isInPlay) {
        isInPlay_ = isInPlay;
    }

    const HoleCards &Player::getHoleCards() const {
        return holeCards_;
    }

    void Player::fold() {
        setIsInPlay(false);
    }

    void Player::check() {
        // do nothing
    }

    float Player::call() {

        return 0;
    }

    float Player::raise(float amount) {
        return 0;
    }

    float Player::allIn() {
        return 0;
    }


}























