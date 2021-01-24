//
// Created by Ciaran Welsh on 23/01/2021.
//

#ifndef POKERX_IGAMEVARIABLES_H
#define POKERX_IGAMEVARIABLES_H

#include "PokerX/engine/Pot.h"
#include "PokerX/engine/Streets.h"
#include "PokerX/engine/IObservableRawPtr.h"
#include "Deck.h"

namespace pokerx {


    class IGameVariables : public IObservableRawPtr<IGameVariables> {
    public:

        ~IGameVariables() override = default;

        [[nodiscard]] virtual Pot &getPot() = 0;

        [[nodiscard]] virtual float getAmountToCall() const = 0;

        virtual void setAmountToCall(float amountToCall) = 0;

        virtual void addToPot(const Pot &pot) = 0;

        [[nodiscard]] virtual bool isCheckAvailable() const = 0;

        virtual void setCheckAvailable(bool checkAvailable) = 0;

        [[nodiscard]] virtual Street getStreet() const = 0;

        virtual void setStreet(Street street) = 0;

        [[nodiscard]] virtual float getSmallBlind() const = 0;

        virtual void setSmallBlind(float smallBlind) = 0;

        [[nodiscard]] virtual float getBigBlind() const = 0;

        virtual void setBigBlind(float bigBlind) = 0;

        [[nodiscard]] virtual Deck &getDeck() = 0;

        virtual void setDeck(const Deck &deck) = 0;

        [[nodiscard]] virtual const unique_ptr<CardCollection> &getCommunityCards() const = 0;

        virtual void setCommunityCards( unique_ptr<CardCollection> communityCards) = 0;

        [[nodiscard]] virtual unsigned int getN() const = 0;

        virtual void setN(unsigned int n)= 0;

        [[nodiscard]] virtual unsigned int getGamesPlayed() const = 0;

        virtual void setGamesPlayed(unsigned int gamesPlayed) = 0;

    protected:

        Pot pot_;

        float amount_to_call_ = 0.0;

        bool checkAvailable_ = true;

        Street street_ = PREFLOP_STREET;

        float smallBlind_ = 1.0;

        float bigBlind_ = 2.0;

        /**
         * Number of games to play
         */
        unsigned int n_;

        /**
         * Number of games player
         */
        unsigned int gamesPlayed_;

    };

}
#endif //POKERX_IGAMEVARIABLES_H
