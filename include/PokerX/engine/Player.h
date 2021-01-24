//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_PLAYER_H
#define POKERSIMULATIONSINCPP_PLAYER_H

#include "PokerX/engine/IPlayer.h"
#include "PokerX/engine/IGameVariables.h"

namespace pokerx {

    class PokerEngine;


    class Player : public IPlayer {
    public:
        explicit Player() = default;

        using IPlayer::IPlayer;

        ~Player() override = default;

//        void update(IGameVariables &source, const std::string &data_field) override;

        friend std::ostream &operator<<(std::ostream &os, Player& IPlayer);

        [[nodiscard]] const std::string &getName() const override;

        void setName(const std::string &name) override;

        [[nodiscard]] float getStack() const override;

        void setStack(float stack) override;

        [[nodiscard]] bool isAllIn() const override;

        void setIsAllIn(bool isAllIn) override;

        [[nodiscard]] bool hasFolded() const override;

        void setHasFolded(bool isInPlay) override;

        [[nodiscard]] HoleCards &getHoleCards() override;

        void watch(IGameVariables *variables) override;

        void fold() override;

        void check() override;

        void call() override;

        void allIn() override;

        [[nodiscard]] IGameVariables *getGameVariables() const override;

        void postSmallBlind() override;

        void postBigBlind() override;

    protected:

        void checkGameVariablesNotNull() const override;
    };

    using PlayerPtr = std::unique_ptr<Player>;
    using SharedPlayerPtr = std::shared_ptr<Player>;

}

#endif //POKERSIMULATIONSINCPP_PLAYER_H
