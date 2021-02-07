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

    CardCollection GameVariables::getCommunityCards() const {
        return communityCards_;
    }

    void GameVariables::setCommunityCards(CardCollection communityCards) {
        communityCards_ = communityCards;
    }

    unsigned int GameVariables::getN() const {
        return n_;
    }

    void GameVariables::setN(unsigned int n) {
        n_ = n;
    }

    unsigned int GameVariables::numGamesPlayed() const {
        return gamesPlayed_;
    }

    void GameVariables::setGamesPlayed(unsigned int gamesPlayed) {
        gamesPlayed_ = gamesPlayed;
    }

    void GameVariables::reset(){
        getPot() = Pot();
        communityCards_ = CardCollection();
        setAmountToCall(0);
        setBetPlaced(false);
        setStreet(PREFLOP_STREET);
        getDeck().reset();
//        setDone(false); // no, this is only for a hard reset (end of epoch)
    }

    bool GameVariables::isDone() const {
        return done_;
    }

    void GameVariables::setDone(bool done) {
        done_ = done;
    }

    bool GameVariables::hasBetBeenPlaced() const {
        return betPlaced_;
    }

    void GameVariables::setBetPlaced(bool betPlaced) {
        betPlaced_ = betPlaced;
    }

    std::string GameVariables::getCurrencySymbol() const {
        return currencySymbol_;
    }

    void GameVariables::setCurrencySymbol(const std::string& symbol) {
        currencySymbol_ = symbol;
    }



}