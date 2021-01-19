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

    bool GameVariables::isCheckAvailable() const {
        return checkAvailable_;
    }

    void GameVariables::setCheckAvailable(bool checkAvailable) {
        notify(*this, "checkAvailable");
        GameVariables::checkAvailable_ = checkAvailable;
    }

    Street GameVariables::getStreet() const {
        return street_;
    }

    void GameVariables::setStreet(Street street) {
        street_ = street;
    }

    float GameVariables::getSmallBlind() const {
        return smallBlind;
    }

    void GameVariables::setSmallBlind(float smallBlind) {
        GameVariables::smallBlind = smallBlind;
    }

    float GameVariables::getBigBlind() const {
        return bigBlind;
    }

    void GameVariables::setBigBlind(float bigBlind) {
        GameVariables::bigBlind = bigBlind;
    }
}