//
// Created by Ciaran on 16/01/2021.
//

#include "PokerX/engine/GameVariables.h"


namespace pokerx {

    Pot GameVariables::getPot() const {
        return pot_;
    }

    float GameVariables::getAmountToCall() const {
        return amount_to_call_;
    }

    void GameVariables::setAmountToCall(float amountToCall) {
        notify(*this, "AmountToCall");
        amount_to_call_ = amountToCall;
    }

    void GameVariables::addToPot(const Pot &pot) {
        notify(*this, "Pot");
        pot_ = pot;
    }
}