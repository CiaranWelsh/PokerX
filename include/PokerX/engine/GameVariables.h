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

        [[nodiscard]] Pot getPot() const override;

        [[nodiscard]] float getAmountToCall() const override;

        void setAmountToCall(float amountToCall) override;

        void addToPot(const Pot &pot) override;

        [[nodiscard]] bool isCheckAvailable() const override;

        void setCheckAvailable(bool checkAvailable) override;

        [[nodiscard]] Street getStreet() const override;

        void setStreet(Street street) override;

        [[nodiscard]] float getSmallBlind() const override;

        void setSmallBlind(float smallBlind) override;

        [[nodiscard]] float getBigBlind() const override;

        void setBigBlind(float bigBlind) override;

    private:
        /**
         * @brief Storage for Commmunity cards.
         */
        std::unique_ptr<CardCollection> communityCards;

        /**
         * @brief the amount of money in the pot
         */
        Pot pot_;

        /**
         * @brief the amount to call the current bet
         */
        float amount_to_call_ = 0.0;

        /**
         * @brief indicator variable that denotes whether players can
         * check or not
         */
        bool checkAvailable_ = true;

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

    };
}

#endif //POKERX_GAMEVARIABLES_H
