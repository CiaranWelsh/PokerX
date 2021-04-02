//
// Created by Ciaran Welsh on 23/01/2021.
//

#ifndef POKERX_IGAMEVARIABLES_H
#define POKERX_IGAMEVARIABLES_H

#include "PokerX/engine/Pot.h"
#include "PokerX/engine/Streets.h"
#include "PokerX/engine/IObservableRawPtr.h"
#include "PokerX/engine/Deck.h"

#include "PokerX/engine/Player.h"

namespace pokerx {

    class Player;

    class IGameVariables : public IObservableRawPtr<IGameVariables> {
    public:

        ~IGameVariables() override = default;

        [[nodiscard]] virtual Pot &getPot() = 0;

        [[nodiscard]] virtual float getAmountToCall() const = 0;

        virtual void setAmountToCall(float amountToCall) = 0;

        virtual void addToPot(const Pot &pot) = 0;

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

        virtual void setN(unsigned int n)= 0;

        [[nodiscard]] virtual unsigned int numGamesPlayed() const = 0;

        virtual void setGamesPlayed(unsigned int gamesPlayed) = 0;

        virtual void reset() = 0;

//        /**
//         * @brief Raisers will call this method from thier
//         * raise method, using this as first argument.
//         */
//        virtual void raise(Player *player, float amount) = 0;

        [[nodiscard]] virtual bool isDone() const = 0;

        virtual void setDone(bool done) = 0 ;

        [[nodiscard]] virtual bool hasBetBeenPlaced() const = 0;

        virtual void setBetPlaced(bool done) = 0 ;

        [[nodiscard]] virtual std::string getCurrencySymbol() const = 0;

        virtual void setCurrencySymbol(const std::string& symbol) = 0 ;

        virtual void setSeed(unsigned long long seed) = 0;

        virtual void injectCommunityCards(const std::vector<ICardPtr >& cards) = 0;

        virtual void injectCommunityCards(const std::initializer_list<ICardPtr > &cards) = 0;

        virtual void injectCommunityCards(const std::vector<std::string> &cards) = 0;

        [[nodiscard]] virtual const std::vector<ICardPtr > &getInjectedCommunityCards() const = 0;

    protected:

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
        std::vector<ICardPtr > injectedCommunityCards_;

    };

}
#endif //POKERX_IGAMEVARIABLES_H
