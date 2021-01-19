//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/Player.h"
#include <ostream>
#include "PokerX/Error.h"

namespace pokerx {

    Player::Player(std::string name, float stack)
            : name_(std::move(name)), stack_(stack) {}

    std::ostream &operator<<(std::ostream &os, Player &player) {
        os << player.getName() << "(stack=" << player.getStack() << ")" << std::endl;
        return os;
    }

    void Player::update(GameVariables &source, const string &data_field) {
        // store the reference
        gameVariables_ = &source;
    }

    GameVariables *Player::getGameVariables() const {
        if (gameVariables_ == nullptr){
            RUNTIME_ERROR << "gameVariables is nullptr" << std::endl;
        }
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

    void Player::checkGameVariablesNotNull() {
        if (gameVariables_ == nullptr) {
            RUNTIME_ERROR << "GameVariables object of player " << name_ << " has not yet "
                          << " been initialized." << std::endl;
        }
    }

    void Player::check() {
        // do nothing
        checkGameVariablesNotNull();
        if (!gameVariables_->isCheckAvailable()){
            // todo handle this exception
            RUNTIME_ERROR << "Check not available because there is money in the pot" << std::endl;
        }
    }

    float Player::call() {
        checkGameVariablesNotNull();
        const float &amount = gameVariables_->getAmountToCall();
        stack_ -= amount;
        return amount;
    }

    float Player::allIn() {
        float amount = stack_; // copy
        stack_ = 0;
        return amount;
    }

    void Player::postSmallBlind() {
        /**
         * Todo take into account the situation when a player no longer
         * has enough money to play
         */
        float sb = gameVariables_->getSmallBlind();
        stack_ -= sb;
        gameVariables_->getPot() += sb;
    }

    void Player::postBigBlind() {
        float bb = gameVariables_->getBigBlind();
        stack_ -= bb;
        gameVariables_->getPot() += bb;
    }


}























