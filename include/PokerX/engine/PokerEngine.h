//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_POKERENGINE_H
#define POKERSIMULATIONSINCPP_POKERENGINE_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/State.h"
#include "PokerX/engine/GameVariables.h"
#include "PokerX/engine/PlayerManager.h"
//#include "Player.h"
//#include "Pot.h"
//#include <vector>

namespace pokerx {


    class PokerEngine : public StateMachine {
    public:
        PokerEngine();

        explicit PokerEngine(State* starting_state);

        void setState(State &state) override;

        /**
         * @brief Call the action method of the currently
         * active state
         *
         * @details This method invokes the State::action method
         * of the currently active state.
         */
        void action() override;

        /**
         * @brief calls the action @param times times
         */
        void action(unsigned int times);

        /**
         * @brief Reset the game for another hand
         */
        void reset() override;

        [[nodiscard]] const GameVariables &getGameVariables() const;

    private:
        /**
         * @brief GameVariables contain all configurable
         * elements of the current game. Number of players,
         * current positions, etc.
         */
        GameVariables gameVariables_;
//        PlayerManager players_;

    };

//    class PokerState;
//
//    class PokerEngine : public StateMachine {
//    public:
//        using StateMachine::StateMachine;
//
//        virtual void reset();
//
//        virtual void rotate();
//
//        void action();
//
//        int getNPlayers() const;
//
//        void setNPlayers(int nPlayers);
//
//        void setCurrentBet(float currentBet);
//
//        float getCurrentBet() const;
//
//        void contribPot(float amount);
//
//        const std::vector<Player *> &getPlayers() const;
//
//        const Pot &getPot() const;
//
//        State *getState() const override;
//
//
//    protected:
//
//        void initPlayers();
//
//        int nPlayers_ = 6;
//        std::vector<Player *> players_;
//        float currentBet_ = 0.0;
//        Pot pot_;
//    };

}

#endif //POKERSIMULATIONSINCPP_POKERENGINE_H
