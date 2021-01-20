//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_GAMEVARIABLES_H
#define POKERX_GAMEVARIABLES_H

#include "PokerX/engine/Pot.h"
#include "PokerX/engine/Observable.h"
#include "PokerX/engine/Streets.h"

namespace pokerx {

    /**
     * The fact that GameVariables is difficult to make
     * a interface for is probably a code smell.
     *
     * We could create a "Variables" interface. But then, what
     * would go in it. Its too vague. And so is GameVariables.
     * Therefore, I should consider refactoring GameVaribales
     * into the components that will make up a GameVariables
     * object.
     */

    class GameVariables : public Observable<GameVariables> {

    public:

        GameVariables() = default;

        [[nodiscard]] Pot getPot() const;

        [[nodiscard]] float getAmountToCall() const;

        void setAmountToCall(float amountToCall);

        void addToPot(const Pot &pot);

        [[nodiscard]] bool isCheckAvailable() const;

        void setCheckAvailable(bool checkAvailable);

        [[nodiscard]] Street getStreet() const;

        void setStreet(Street street);

        [[nodiscard]] float getSmallBlind() const;

        void setSmallBlind(float smallBlind);

        [[nodiscard]] float getBigBlind() const;

        void setBigBlind(float bigBlind);

    private:
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
