//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_PLAYER_H
#define POKERSIMULATIONSINCPP_PLAYER_H

#include "PokerX/engine/Action.h"
#include "PokerX/engine/GameVariables.h"
#include "PokerX/engine/HoleCards.h"
#include <iostream>

namespace pokerx {

    class PokerEngine;

    class Player {
    public:
        explicit Player() = default;

        Player(std::string name, float stack);

        virtual Action selectAction(PokerEngine* engine) = 0;

        [[nodiscard]] const std::string &getName() const;

        void setName(const std::string &name);

        friend std::ostream &operator<<(std::ostream &os, Player& player);

        [[nodiscard]] float getStack() const;

        void setStack(float stack);

        [[nodiscard]] bool isAllIn() const;

        void setIsAllIn(bool isAllIn);

        [[nodiscard]] bool isInPlay() const;

        void setIsInPlay(bool isInPlay);

        [[nodiscard]] const HoleCards &getHoleCards() const;

    protected:
        float stack_ = 1000.0;
        bool isAllIn_ = false;
        bool isInPlay_ = true;
        std::string name_;

        HoleCards holeCards_;

        /**
         * What if the Player implemented the Observer interface with
         * the GameVariables class?
         * Player observes  subscribes to the GameVariables class
         *
         * We could just hold a reference to the GameVariables class within
         * the Player class? This is simpler although might incur some
         * recrusive dependencies that need resolving with forward declarations. Note,
         * in languages where C++ like references are not possible, it would *have
         * to be an observer.
         */
    };

}

#endif //POKERSIMULATIONSINCPP_PLAYER_H
