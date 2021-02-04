//
// Created by Ciaran Welsh on 02/02/2021.
//

#include <utility>

#include "PokerX/engine/Policy.h"


namespace pokerx {

//    Policy::Policy(std::initializer_list<Action> actions)
//            : Policy(std::vector<Action>(actions.begin(), actions.end())) {}

    Policy::Policy(std::vector<Action> actions)
            : actions_(std::move(actions)) {}

    Policy::Policy(std::vector<Action>  actions, std::vector<float>  raiseAmounts)
            : actions_(std::move(actions)), raiseAmounts_(std::move(raiseAmounts)){}

    const std::vector<Action> &Policy::getActions() const {
        return actions_;
    }

    void Policy::setActions(const std::vector<Action> &actions) {
        actions_ = actions;
    }

    Action Policy::nextAction() {
        Action this_action = actions_[nextAction_];
        if (nextAction_ == actions_.size() - 1) {
            nextAction_ = 0;
        } else {
            nextAction_ += 1; // increment action
        }
        return this_action;
    }

    const std::vector<float> &Policy::getRaiseAmounts() const {
        return raiseAmounts_;
    }

    void Policy::setRaiseAmounts(const std::vector<float> &raiseAmounts) {
        raiseAmounts_ = raiseAmounts;
    }

    void Policy::setNextAction(int nextAction) {
        nextAction_ = nextAction;
    }

}