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
        gameVariables_->registerObserver(this);
    }


    void Player::fold() {
        setHasFolded(true);
        numActionsThisStreet_ += 1;
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
        // has bet other than the blinds been placed?
        // everyone gets a chance to raise

        // increment the number of actions this player has taken
        numActionsThisStreet_ += 1;
    }

    void Player::call() {
        checkGameVariablesNotNull();
        // amount to call is alwas the amount already contributed minus
        const float &amount = gameVariables_->getAmountToCall() - amountContrib_;
        if (amount > stack_) {
            RUNTIME_ERROR << "Amount to call is greater than your stack" << std::endl;
        } else if (amount == stack_)
            setIsAllIn(true);
        amountContrib_ += amount;
        stack_ -= amount;
        getGameVariables()->getPot() += amount;
        numActionsThisStreet_ += 1;
    }

    void Player::allIn() {
        setIsAllIn(true);
        float amount = stack_; // copy
        stack_ = 0;
        amountContrib_ += amount;
        getGameVariables()->getPot() += amount;
        numActionsThisStreet_ += 1;
    }

    // raise is left virtual but the subclass should call
    // doRaise. Its up to the subclass to determine the strategy

    void Player::doRaise(float amountToRaiseTo) {
        amountContrib_ += amountToRaiseTo;
        gameVariables_->getPot() += amountToRaiseTo;
        stack_ -= amountToRaiseTo;
        numActionsThisStreet_ += 1;
    }

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
        const CardCollection &comm = getGameVariables()->getCommunityCards();
        Hand hand;
        hand.add(comm);
        hand.add(getHoleCards().getCards());
        return hand;
    }

    void Player::reset() {
        setNumActionsThisStreet(0);
        holeCards_ = HoleCards();
        setHasFolded(false);
        setIsAllIn(false);
        if (stack_ == 0) {
            setSittingOut(true);
        } else {
            setSittingOut(false);
        }
    }


    [[nodiscard]] Policy *Player::getPolicy() {
        return &policy_;
    }

    void Player::setPolicy(const Policy &policy) {
        policy_ = policy;
    }

    unsigned int Player::getNumActionsThisStreet() const {
        return numActionsThisStreet_;
    }

    void Player::setNumActionsThisStreet(unsigned int numActionsThisStreet) {
        numActionsThisStreet_ = numActionsThisStreet;
    }

    void Player::injectHoleCards(std::vector<std::string> cards) {
        if (cards.size() > 2) {
            LOGIC_ERROR << "Cannot inject more than 2 cards into a players hand" << std::endl;
        }
        for (auto & card : cards){
            injectedHoleCards_.pushBack(CardFactory(card));
            getGameVariables()->getDeck().erase(card);
        }
    }

    HoleCards Player::getInjectedHoleCards() const {
        return injectedHoleCards_;
    };


}























