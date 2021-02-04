//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/Player.h"
#include "PokerX/Error.h"
#include <ostream>
#include <PokerX/engine/hands/Hand.h>

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
        return isAllIn_;
    }

    void Player::setIsAllIn(bool isAllIn) {
        isAllIn_ = isAllIn;
    }

    bool Player::hasFolded() const {
        return hasFolded_;
    }

    void Player::setHasFolded(bool hasFolded) {
        hasFolded_ = hasFolded;
    }

    bool Player::isSittingOut() const {
        return isSittingOut_;
    }

    void Player::setSittingOut(bool isSittingOut) {
        isSittingOut_ = isSittingOut;
    }

    HoleCards &Player::getHoleCards() {
        return holeCards_;
    }

    void Player::watch(IGameVariables *variables) {
        gameVariables_ = variables;
//         __FILE_NAME__<<":"<<__LINE__<<": possible memory related error"<<std::endl;
        gameVariables_->registerObserver(this);
    }


    void Player::fold() {
        setHasFolded(true);
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
        if (gameVariables_->hasBetBeenPlaced()){
            // todo handle this exception
            RUNTIME_ERROR << "Check not available because a bet has been placed" << std::endl;
        }
    }

    void Player::call() {
        checkGameVariablesNotNull();
        const float &amount = gameVariables_->getAmountToCall();
        if (amount > stack_){
            RUNTIME_ERROR << "Amount to call is greater than your stack" << std::endl;
        } else if(amount == stack_)
            setIsAllIn(true);
        amountContrib_ += amount;
        stack_ -= amount;
        getGameVariables()->getPot() += amount;
    }

    void Player::allIn() {
        setIsAllIn(true);
        float amount = stack_; // copy
        stack_ = 0;
        amountContrib_ += amount;
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
        amountContrib_ += sb;
        gameVariables_->setAmountToCall(sb);
    }

    void Player::postBigBlind() {
        checkGameVariablesNotNull();
        float bb = gameVariables_->getBigBlind();
        stack_ -= bb;
        gameVariables_->getPot() += bb;
        amountContrib_ += bb;
        gameVariables_->setAmountToCall(bb);
    }

    float Player::getAmountContrib() const {
        return amountContrib_;
    }

    void Player::setAmountContrib(float amount) {
        amountContrib_ = amount;
    }

    Hand Player::getHand() {
        const CardCollection & comm = getGameVariables()->getCommunityCards();
        Hand hand;
        hand.add(comm);
        hand.add(getHoleCards().getCards());
        return hand;
    }

    void Player::reset(){
        holeCards_ = HoleCards();
        setHasFolded(false);
        setIsAllIn(false);
        if (stack_ == 0){
            setSittingOut(true);
        } else{
            setSittingOut(false);
        }
    }

    void Player::doRaise(float amountToRaiseTo) {
        amountContrib_ += amountToRaiseTo;
        gameVariables_->getPot() += amountToRaiseTo;
        stack_ -= amountToRaiseTo;
    }


    [[nodiscard]] const Policy &Player::getPolicy() const {
        return policy_;
    }

    void Player::setPolicy(const Policy &policy) {
        policy_ = policy;
    }
}























