//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_PLAYER_H
#define POKERSIMULATIONSINCPP_PLAYER_H

#include "Action.h"
#include "NoLimitHoldem.h"
#include "PokerEngine.h"

namespace pokerx {

    class PokerEngine;

    class Player {
    public:
        Player() = default;

        explicit Player(float stack) : stack_(stack){}

        virtual Action selectAction(PokerEngine* engine) = 0;

        [[nodiscard]] float getStack() const {
            return stack_;
        }

        void setStack(float stack) {
            stack_ = stack;
        }

        [[nodiscard]] bool isAllIn() const {
            return isAllIn_;
        }

        void setIsAllIn(bool isAllIn) {
            isAllIn_ = isAllIn;
        }

    protected:
        float stack_ = 1000.0;
        bool isAllIn_ = false;
    };

}

#endif //POKERSIMULATIONSINCPP_PLAYER_H
