//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_GAMEVARIABLES_H
#define POKERX_GAMEVARIABLES_H

#include "PokerX/engine/Pot.h"
#include "PokerX/engine/Streets.h"
#include "PokerX/engine/IGameVariables.h"
#include "PokerX/engine/CardCollection.h"
#include <memory>

namespace pokerx {

    class GameVariables : public IGameVariables {

    public:

        GameVariables() = default;

        ~GameVariables() override = default;

        [[nodiscard]] Pot getPot() override;

        [[nodiscard]] float getAmountToCall() const override;

        void setAmountToCall(float amountToCall) override;

        [[nodiscard]] Street getStreet() const override;

        void setStreet(Street street) override;

        [[nodiscard]] float getSmallBlind() const override;

        void setSmallBlind(float smallBlind) override;

        [[nodiscard]] float getBigBlind() const override;

        void setBigBlind(float bigBlind) override;

        [[nodiscard]] Deck &getDeck() override;

        void setDeck(const Deck &deck) override;

        [[nodiscard]] CardCollection getCommunityCards() const override;

        void setCommunityCards(CardCollection communityCards) override;

        [[nodiscard]] unsigned int getN() const override;

        void setN(unsigned int n) override;

        [[nodiscard]] unsigned int numGamesPlayed() const override;

        void setGamesPlayed(unsigned int gamesPlayed) override;

        void reset() override;

        [[nodiscard]] bool isDone() const override;

        void setDone(bool done) override;

        [[nodiscard]] bool hasBetBeenPlaced() const override;

        void setBetPlaced(bool done) override;

        [[nodiscard]] std::string getCurrencySymbol() const override;

        void setCurrencySymbol(const std::string &symbol) override;

        void setSeed(unsigned long long seed) override;

        void injectCommunityCards(const std::vector<std::string> &cards) override;

        [[nodiscard]] const std::vector<ICardPtr > &getInjectedCommunityCards() const override;

        std::string lastWinner() override;

        Hand lastWinningHand() override;

        float lastPot() override;

        void setLastWinner(std::string name) override;

        void setLastWinningHand(Hand winner) override;

        void setLastPot(float  amount) override;

        bool allInMode() override;

        bool setAllInMode(bool allInMode) override;

        [[nodiscard]] std::vector<std::shared_ptr<Pot>> getPots() const override;

        [[nodiscard]] unsigned int getCurrentPotIdx() const override;

        void setCurrentPotIdx(unsigned int idx) override;

        [[nodiscard]] std::vector<SharedIPlayerPtr> getPotIdentities() const override;

        void newPot(std::shared_ptr<IPlayer> player);

        };
}


#endif //POKERX_GAMEVARIABLES_H
