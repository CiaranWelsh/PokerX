//
// Created by Ciaran on 16/01/2021.
//

#include <PokerX/engine/Deck.h>
#include "PokerX/engine/GameVariables.h"


namespace pokerx {

    Pot & GameVariables::getPot() {
        return pot_;
    }

    float GameVariables::getAmountToCall() const {
        return amount_to_call_;
    }

    void GameVariables::setAmountToCall(float amountToCall) {
        notifyObservers(*this, "AmountToCall");
        amount_to_call_ = amountToCall;
    }

    void GameVariables::addToPot(const Pot &pot) {
        notifyObservers(*this, "Pot");
        pot_ = pot;
    }

    bool GameVariables::isCheckAvailable() const {
        return checkAvailable_;
    }

    void GameVariables::setCheckAvailable(bool checkAvailable) {
        notifyObservers(*this, "checkAvailable");
        GameVariables::checkAvailable_ = checkAvailable;
    }

    Street GameVariables::getStreet() const {
        return street_;
    }

    void GameVariables::setStreet(Street street) {
        street_ = street;
    }

    float GameVariables::getSmallBlind() const {
        return smallBlind_;
    }

    void GameVariables::setSmallBlind(float smallBlind) {
        smallBlind_ = smallBlind;
    }

    float GameVariables::getBigBlind() const {
        return bigBlind_;
    }

    void GameVariables::setBigBlind(float bigBlind) {
        bigBlind_ = bigBlind;
    }

    pokerx::Deck &GameVariables::getDeck() {
        return deck_;
    }

    void GameVariables::setDeck(const pokerx::Deck &deck) {
        deck_ = deck;
    }

    const std::unique_ptr<CardCollection> &GameVariables::getCommunityCards() const {
        return communityCards_;
    }

    void GameVariables::setCommunityCards(std::unique_ptr<CardCollection> communityCards) {
        communityCards_ = std::move(communityCards);
    }

    unsigned int GameVariables::getN() const {
        return n_;
    }

    void GameVariables::setN(unsigned int n) {
        n_ = n;
    }

    unsigned int GameVariables::getGamesPlayed() const {
        return gamesPlayed_;
    }

    void GameVariables::setGamesPlayed(unsigned int gamesPlayed) {
        gamesPlayed_ = gamesPlayed;
    }


}