//
// Created by Ciaran Welsh on 23/01/2021.
//

#ifndef POKERX_IGAMEVARIABLES_H
#define POKERX_IGAMEVARIABLES_H

#include "PokerX/engine/Pot.h"
#include "PokerX/engine/Streets.h"
#include "PokerX/engine/IObservableRawPtr.h"
#include "PokerX/engine/Deck.h"

#include "PokerX/engine/IPlayer.h"

namespace pokerx {

    class Player;
    class IPlayer;

    class IGameVariables : public IObservableRawPtr<IGameVariables> {
    public:

        ~IGameVariables() override = default;

        [[nodiscard]] virtual Pot getPot() = 0;

        [[nodiscard]] virtual float getAmountToCall() const = 0;

        virtual void setAmountToCall(float amountToCall) = 0;

        [[nodiscard]] virtual Street getStreet() const = 0;

        virtual void setStreet(Street street) = 0;

        [[nodiscard]] virtual float getSmallBlind() const = 0;

        virtual void setSmallBlind(float smallBlind) = 0;

        [[nodiscard]] virtual float getBigBlind() const = 0;

        virtual void setBigBlind(float bigBlind) = 0;

        [[nodiscard]] virtual Deck &getDeck() = 0;

        virtual void setDeck(const Deck &deck) = 0;

        [[nodiscard]] virtual CardCollection getCommunityCards() const = 0;

        virtual void setCommunityCards(CardCollection communityCards) = 0;

        [[nodiscard]] virtual unsigned int getN() const = 0;

        virtual void setN(unsigned int n) = 0;

        [[nodiscard]] virtual unsigned int numGamesPlayed() const = 0;

        virtual void setGamesPlayed(unsigned int gamesPlayed) = 0;

        virtual void reset() = 0;

//        /**
//         * @brief Raisers will call this method from thier
//         * raise method, using this as first argument.
//         */
//        virtual void raise(Player *player, float amount) = 0;

        [[nodiscard]] virtual bool isDone() const = 0;

        virtual void setDone(bool done) = 0;

        [[nodiscard]] virtual bool hasBetBeenPlaced() const = 0;

        virtual void setBetPlaced(bool done) = 0;

        [[nodiscard]] virtual std::string getCurrencySymbol() const = 0;

        virtual void setCurrencySymbol(const std::string &symbol) = 0;

        virtual void setSeed(unsigned long long seed) = 0;

        virtual void injectCommunityCards(const std::vector<std::string> &cards) = 0;

        [[nodiscard]] virtual const std::vector<ICardPtr> &getInjectedCommunityCards() const = 0;

        virtual std::string lastWinner() = 0;

        virtual Hand lastWinningHand() = 0;

        virtual float lastPot() = 0;

        virtual void setLastWinner(std::string name) = 0;

        virtual void setLastWinningHand(Hand winner) = 0;

        virtual void setLastPot(float  amount) = 0;

        virtual bool allInMode() = 0;

        virtual bool setAllInMode(bool allInMode) = 0;

        [[nodiscard]] virtual std::vector<std::shared_ptr<Pot>> getPots() const = 0;

        [[nodiscard]] virtual unsigned int getCurrentPotIdx() const = 0;

        virtual void setCurrentPotIdx(unsigned int idx) = 0;

        [[nodiscard]] virtual std::vector<std::shared_ptr<IPlayer>> getPotIdentities() const = 0;

        virtual void newPot(std::shared_ptr<IPlayer> player) = 0;

    protected:

        /**
         * Stores the player a particular pot
         * belongs to. When a player goes all in
         * the remaining players can continue but the all
         * in player can only win the amount in "their" pot.
         */
        std::vector<std::shared_ptr<IPlayer>> potIdentities_;

        /**
         * A vector of Pot objects. Most
         * of the time, only 1 pot will be
         * needed, but we'll need to spawn
         * new pots as needed to deal with complex
         * split pot situations
         */
         std::vector<std::shared_ptr<Pot>> pots_;

        /**
         * Current pot index. When a split pot is needed
         * the currentPot index increases.
         */
         unsigned int currentPotIdx_ = 0;

        /**
         * boolean indicator as to whether
         * we are in `allIn` mode. When we play
         * through cards without betterin g
         * because a player is all in.
         */
         bool allInMode_ = false;

        /**
         * Name of player who won last
         */
        std::string lastWinner_;

        /**
         * Hand that won the last game
         */
        Hand lastWinningHand_;

        /**
         * Amount won in last game
         */
        float lastPotAmount;

        /**
         * Number of games to play
         */
        unsigned int n_;

        /**
         * Number of games player
         */
        unsigned int gamesPlayed_ = 0;

        /**
          * A deck of cards
          */
        Deck deck_;

        /**
         * @brief Storage for Commmunity cards.
         */
        CardCollection communityCards_{};

        /**
         * @brief the amount of money in the pot
         */
        Pot pot_;

        /**
         * @brief the amount to call the current bet
         */
        float amount_to_call_ = 0.0;

        /**
         * @brief set to true once somebody other than the blinds
         * have put money in the pot, false otherwise. When true
         * players can no longer check.
         */
        bool betPlaced_ = false;

        /**
         * @brief variable to denote the current street
         */
        Street street_ = PREFLOP_STREET;

        /**
         * @brief small blind amount
         */
        float smallBlind_ = 1.0;

        /**
         * @brief big blind amount
         */
        float bigBlind_ = 2.0;

        /**
         * @brief count of how many games player
         */
        unsigned int count = 0;

        /**
         * @bief set to true once all N games
         * have been played
         */
        bool done_ = false;

        /**
         * @brief Currency symbol like $ or £.
         * Default to dollar.
         */
        std::string currencySymbol_ = "$";

        /**
         * @brief control the community cards by prividing them here.
         * The first three, fourth then fifth will be used as the flop,
         * turn and river respectively. This is used in testing and
         * to reproduce games. Partial games are not supported right now
         * so users should provide all 5 community cares. Later implementations
         * could make it so that we could inject only the turn or river for example.
         */
        std::vector<ICardPtr> injectedCommunityCards_ = std::vector<ICardPtr>();

    };

}
#endif //POKERX_IGAMEVARIABLES_H
