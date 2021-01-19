//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_PLAYER_H
#define POKERSIMULATIONSINCPP_PLAYER_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/Action.h"
#include "PokerX/engine/GameVariables.h"
#include "PokerX/engine/HoleCards.h"
#include "PokerX/engine/Observer.h"
#include <iostream>


/**
 * todo implement a Pot observer such that
 * players can addSubscriber and be notified of any pot changes
 */

namespace pokerx {

    class PokerEngine;

    class Player : public Observer<GameVariables>{
    public:
        explicit Player() = default;

        Player(std::string name, float stack);

        virtual Action selectAction(StateMachine *engine) = 0;

        void update(GameVariables &source, const std::string &data_field) override;

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

        /**
         * @brief Change the isInPlay variable to false
         * to indicate the this player has folded this round
         */
        void fold();

        /**
         * @brief Move on to the next player without
         * putting money in the pot or folding. Not
         * available when there is money in the pot
         * that did not originate from the small or
         * big blind.
         */
         void check();

         /**
          * @brief Call the current bet by putting the
          * current bet size from this players stack into
          * the pot
          */
         float call();

         /**
          * @brief raise the current bet
          * @details We cannot accept the raise amount as a parameter
          * here because we have no way to enter it from where it'll be called
          * i.e. from the Raise state, which only has an action call that accepts
          * the state machine pointer. Therefore we need to allow subclasses to override
          * this method to define their own strategy of raising. Perhaps
          * triple bet raise, perhaps console or network input
          */
         virtual float raise() = 0;

         /**
          * @brief uses the Player::raise method but
          * with this players entire stack;
          */
         float allIn();

        [[nodiscard]] GameVariables *getGameVariables() const;

        /**
         * @brief add the amount of chips dictated by the small blind
         * into the pot
         */
         void postSmallBlind();

        /**
         * @brief add the amount of chips dictated by the small blind
         * into the pot
         */
         void postBigBlind();

    protected:
        float stack_ = 1000.0;
        bool isAllIn_ = false;
        bool isInPlay_ = true;
        std::string name_;

        HoleCards holeCards_;

        /**
         * @brief Stack pointer to a GameVariables object.
         * @details When initialized, this variable will be nullptr.
         * After the GameVariables::update method has been called,
         * it'll be replaced with a pointer to the current GameVariables
         * object, which is not a heap allocated pointer.
         */
        GameVariables* gameVariables_ = nullptr;


        void checkGameVariablesNotNull();
    };

    using PlayerPtr = std::unique_ptr<Player>;
    using SharedPlayerPtr = std::shared_ptr<Player>;
    using PlayerPtr2 = std::unique_ptr<PlayerPtr>;

}

#endif //POKERSIMULATIONSINCPP_PLAYER_H
