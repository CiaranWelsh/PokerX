//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/Player.h"
#include "PokerX/Error.h"
#include <ostream>

namespace pokerx {



    std::ostream &operator<<(std::ostream &os, Player &player) {
        return player.print(os);
    }

    IGameVariables *Player::getGameVariables() const {
        checkGameVariablesNotNull();
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

    bool Player::hasFolded() const {
        return isInPlay_;
    }

    void Player::setHasFolded(bool isInPlay) {
        isInPlay_ = isInPlay;
    }

    HoleCards &Player::getHoleCards() {
        return holeCards_;
    }

    void Player::watch(IGameVariables *variables) {
        gameVariables_ = variables;
//        std::cout << __FILE_NAME__<<":"<<__LINE__<<": possible memory related error"<<std::endl;
        gameVariables_->registerObserver(this);
    }


    void Player::fold() {
        setHasFolded(false);
    }

    void Player::checkGameVariablesNotNull() const {
        if (gameVariables_ == nullptr) {
            RUNTIME_ERROR << "GameVariables object of player " << name_ << " has not yet "
                          << " been initialized. Use the PlayerManager::watch or "
                             "Player::watch method before gameplay" << std::endl;
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

    void Player::call() {
        checkGameVariablesNotNull();
        const float &amount = gameVariables_->getAmountToCall();
        if (amount > stack_){
            RUNTIME_ERROR << "Amount to call is greater than your stack" << std::endl;
        } else if(amount == stack_)
            setIsAllIn(true);
        stack_ -= amount;
        getGameVariables()->getPot() += amount;
    }

    void Player::allIn() {
        setIsAllIn(true);
        float amount = stack_; // copy
        stack_ = 0;
        getGameVariables()->getPot() += amount;
    }

    // raise is left virtual

    void Player::postSmallBlind() {
        /**
         * Todo take into account the situation when a player no longer
         * has enough money to play
         */
        checkGameVariablesNotNull();
        float sb = gameVariables_->getSmallBlind();
        stack_ -= sb;
        gameVariables_->getPot() += sb;
    }

    void Player::postBigBlind() {
        checkGameVariablesNotNull();
        float bb = gameVariables_->getBigBlind();
        stack_ -= bb;
        gameVariables_->getPot() += bb;
    }



}























