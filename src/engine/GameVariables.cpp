//
// Created by Ciaran on 16/01/2021.
//

#include <PokerX/engine/Deck.h>
#include <PokerX/engine/RandomNumberGenerator.h>
#include "PokerX/engine/GameVariables.h"


namespace pokerx {

    Pot GameVariables::getPot() {
        auto pots = getPots();
        return *pots[getCurrentPotIdx()];
    }

    float GameVariables::getAmountToCall() const {
        return amount_to_call_;
    }

    void GameVariables::setAmountToCall(float amountToCall) {
        notifyObservers(*this, "AmountToCall");
        amount_to_call_ = amountToCall;
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

    void GameVariables::reset() {
        pots_.resize(0);
        pots_.push_back(std::move(std::make_shared<Pot>(0)));
        assert(pots_.size() == 1 && "Size of pot_ should be exactly 1 after reset");
        communityCards_ = CardCollection();
        setAmountToCall(0);
        setBetPlaced(false);
        setStreet(PREFLOP_STREET);
        getDeck().reset();
        setAllInMode(false);
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

    void GameVariables::setCurrencySymbol(const std::string &symbol) {
        currencySymbol_ = symbol;
    }

    void GameVariables::setSeed(unsigned long long int seed) {
        RandomNumberGenerator::getInstance().setSeed(seed);
    }


    void GameVariables::injectCommunityCards(const std::vector<std::string> &cards) {
        for (const auto &it: cards) {
            injectedCommunityCards_.push_back(std::move(CardFactory(it)));
        }
    }

    const std::vector<ICardPtr> &GameVariables::getInjectedCommunityCards() const {
        return injectedCommunityCards_;
    }

    std::string GameVariables::lastWinner() {
        return lastWinner_;
    }

    Hand GameVariables::lastWinningHand() {
        return lastWinningHand_;
    }

    float GameVariables::lastPot() {
        return lastPotAmount;
    }

    void GameVariables::setLastWinner(std::string name) {
        lastWinner_ = name;
    }

    void GameVariables::setLastWinningHand(Hand winner) {
        lastWinningHand_ = winner;
    }

    void GameVariables::setLastPot(float amount) {
        lastPotAmount = amount;
    }

    bool GameVariables::allInMode() {
        return allInMode_;
    }

    bool GameVariables::setAllInMode(bool allInMode){
        allInMode_ = allInMode;
    }

    std::vector<std::shared_ptr<Pot>> GameVariables::getPots() const {
        return pots_;
    }

    unsigned int GameVariables::getCurrentPotIdx() const {
        return currentPotIdx_;
    }

    void GameVariables::setCurrentPotIdx(unsigned int idx) {
        currentPotIdx_ = idx;
    }

    std::vector<SharedIPlayerPtr> GameVariables::getPotIdentities() const {
        return potIdentities_;
    };

    void GameVariables::newPot(std::shared_ptr<IPlayer> player) {
        // pot at current idx is associated with player
        potIdentities_.push_back(std::move(player));
        // and we now create a new pot for the remaining players
        pots_.push_back(std::make_shared<Pot>(0));
        currentPotIdx_ += 1;
    };



}