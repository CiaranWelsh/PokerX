//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_POKERENGINE_H
#define POKERSIMULATIONSINCPP_POKERENGINE_H

#include "StateMachine.h"
#include "State.h"
#include "Player.h"
#include "Pot.h"
#include <vector>

namespace engine {

    class PokerState;

    class PokerEngine : public StateMachine {
    public:
        using StateMachine::StateMachine;

        virtual void reset();

        virtual void rotate();

        void action();

        int getNPlayers() const;

        void setNPlayers(int nPlayers);

        void setCurrentBet(float currentBet);

        float getCurrentBet() const;

        void contribPot(float amount);

        const std::vector<Player *> &getPlayers() const;

        const Pot &getPot() const;

        State *getState() const override;


    protected:

        void initPlayers();

        int nPlayers_ = 6;
        std::vector<Player *> players_;
        float currentBet_ = 0.0;
        Pot pot_;
    };

}

#endif //POKERSIMULATIONSINCPP_POKERENGINE_H
