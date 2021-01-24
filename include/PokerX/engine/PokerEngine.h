//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_POKERENGINE_H
#define POKERSIMULATIONSINCPP_POKERENGINE_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/State.h"
#include "PokerX/engine/IGameVariables.h"
#include "PokerX/engine/IPlayerManager.h"
#include "pokerx_export.h"


namespace pokerx {

    class PokerEngine : public StateMachine {
    public:

        /**
         * Container base enables dependency injection but the more specialized
         * PlayerManager has methods required by PokerEngine, so we've broken
         * the liskov substitution principle. So, how do we fix it. 
         */
        PokerEngine(IPlayerManager *playerManager, IGameVariables *variables);

        void setState(State &state) override;

        /**
         * @brief Call the action method of the currently
         * active state
         *
         * @details This method invokes the State::action method
         * of the currently active state.
         */
        void action(Action action) override;

        /**
         * @brief calls the action @param times times
         */
        void action(unsigned int times);

        /**
         * @brief Reset the game for another hand
         */
        void reset() override;

        [[nodiscard]] IGameVariables *getGameVariables() const;

        [[nodiscard]] IPlayerManager *getPlayers() const;

        void bind(IPlayerManager *manager);

        void bind(IGameVariables *gameVariables);

        /**
         * @brief move the PokerEngine to the next player.
         * @details static allocation
         */
        static void nextPlayer(StateMachine *machine);

        void dealHoleCards() const;

        void dealFlop();

        void dealTurn();

        void dealRiver();

        /**
         * @brief evaluate all hands of players in the game
         * and determine who has won. The winning players stack
         * is increased by the pot amount.
         */
        void determineWinner();

    private:
        /**
         * @brief GameVariables contain all configurable
         * elements of the current game. Number of players,
         * current positions, etc.
         */
        IGameVariables *gameVariables_;

        /**
         * @brief variable to store all things regarding players
         */
        IPlayerManager *players_;


    };

}

#endif //POKERSIMULATIONSINCPP_POKERENGINE_H
