//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_POKERENGINE_H
#define POKERSIMULATIONSINCPP_POKERENGINE_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/State.h"
#include "PokerX/engine/GameVariables.h"
#include "PokerX/engine/PlayerManager.h"
#include "pokerx_export.h"


namespace pokerx {

    class PokerEngine : public StateMachine {
    public:
        /**
         * @brief deprecated constructor. We need manager and variables.
         */
        POKERX_DEPRECATED PokerEngine();

        /**
         * @brief deprecated constructor. We need manager and variables.
         */
        POKERX_DEPRECATED explicit PokerEngine(State *starting_state);

        PokerEngine(PlayerManager& manager, GameVariables& variables);

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

        [[nodiscard]] const GameVariables &getGameVariables() const;

        [[nodiscard]] const PlayerManager &getPlayers() const;


        void bind(PlayerManager& manager);

        void bind(GameVariables& gameVariables);

    private:
        /**
         * @brief GameVariables contain all configurable
         * elements of the current game. Number of players,
         * current positions, etc.
         */
        GameVariables gameVariables_;

        /**
         * @brief variable to store all things regarding players
         */
        PlayerManager players_;


    };

}

#endif //POKERSIMULATIONSINCPP_POKERENGINE_H
