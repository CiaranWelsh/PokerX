//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_IPLAYER_H
#define POKERSIMULATIONSINCPP_IPLAYER_H

#include "PokerX/engine/StateMachine.h"
#include "PokerX/engine/Action.h"
#include "PokerX/engine/HoleCards.h"
#include "PokerX/engine/IObserver.h"
#include <iostream>
#include <sstream>
#include <memory>

#include "PokerX/engine/IGameVariables.h"

namespace pokerx {

    class IPlayer : public IObserver<IGameVariables>{
    public:
        explicit IPlayer() = default;

        IPlayer(std::string name, float stack)
                : name_(std::move(name)), stack_(stack) {};

        ~IPlayer() override = default;

        /**
         * @brief implement the update method from the IObserver<IGameVariables>
         * superclass
         * @details pass IGameVariables by reference
         */
        void update(IGameVariables &source, const std::string &data_field) override {
            // store the reference
            gameVariables_ = &source;
        }

        /**
         * @brief implement the update method from the IObserver<IGameVariables>
         * superclass
         * @details pass IGameVariables by pointer
         */
        void update(IGameVariables *source, const std::string &data_field) override {
            // store the reference
            gameVariables_ = source;
        }

        /**
         * @brief choose an action
         */
        virtual Action selectAction(StateMachine *engine) = 0;

        [[nodiscard]] virtual const std::string &getName() const = 0;

        virtual void setName(const std::string &name) = 0;

        std::ostream &print(std::ostream& os) const {
            os << getName() << "(stack=" << getStack() << ")";
            return os;
        }

        [[nodiscard]] virtual float getStack() const = 0;

        virtual void setStack(float stack) = 0;

        [[nodiscard]] virtual bool isAllIn() const = 0;

        virtual void setIsAllIn(bool isAllIn) = 0;

        [[nodiscard]] virtual bool hasFolded() const = 0;

        virtual void setHasFolded(bool isInPlay) = 0;

        [[nodiscard]] virtual HoleCards &getHoleCards() = 0;

        /**
         * @brief associate this IPlayer with a GameVariables object
         * @details Since the GameVariables object is a reference
         * only, we must initialize this variable before use. This should
         * never need to be done by end users but will need doing inside the
         * PokerEngine constructor. The implementation must ensure it calls
         * the IGameVariables::registerObserver method to complete the
         * Observer-Observed relationship between players and the game variables.
         *
         */
        virtual void watch(IGameVariables *variables) = 0;

        /**
         * @brief Change the hasFolded variable to false
         * to indicate the this IPlayer has folded this round
         */
        virtual void fold() = 0;

        /**
         * @brief Move on to the next IPlayer without
         * putting money in the pot or folding. Not
         * available when there is money in the pot
         * that did not originate from the small or
         * big blind.
         */
        virtual void check() = 0;

        /**
         * @brief Call the current bet by putting the
         * current bet size from this players stack into
         * the pot
         */
        virtual void call() = 0;

        /**
         * @brief raise the current bet
         * @details We cannot accept the raise amount as a parameter
         * here because we have no way to enter it from where it'll be called
         * i.e. from the Raise state, which only has an action call that accepts
         * the state machine pointer. Therefore we need to allow subclasses to override
         * this method to define their own strategy of raising. Perhaps
         * triple bet raise, perhaps console or network input
         */
        virtual void raise() = 0;

        /**
         * @brief uses the IPlayer::raise method but
         * with this players entire stack;
         */
        virtual void allIn() = 0;

        [[nodiscard]] virtual IGameVariables *getGameVariables() const = 0;

        /**
         * @brief add the amount of chips dictated by the small blind
         * into the pot
         */
        virtual void postSmallBlind() = 0;

        /**
         * @brief add the amount of chips dictated by the small blind
         * into the pot
         */
        virtual void postBigBlind() = 0;

        /**
         * @brief Get the amount contributed to the pot
         * by this player, this street.
         * @details this number resets to 0 at the start of each betting
         * round
         *
         * // todo implement resetting of this state variable
         */
        [[nodiscard]] virtual float getAmountContrib() const = 0;

        virtual void setAmountContrib(float amount) = 0;


    protected:
        float stack_ = 1000.0;
        bool isAllIn_ = false;
        bool isInPlay_ = true;

        /**
         * A running total of the amount spent
         * this street
         */
        float amountContrib_ = 0.0;

        std::string name_;

        HoleCards holeCards_{};

        /**
         * @brief Stack pointer to a GameVariables object.
         * @details When initialized, this variable will be nullptr.
         * After the GameVariables::updateObservers method has been called,
         * it'll be replaced with a pointer to the current GameVariables
         * object, which is not a heap allocated pointer.
         */
        IGameVariables *gameVariables_ = nullptr;

        virtual void checkGameVariablesNotNull() const = 0;
    };

    using IPlayerPtr = std::unique_ptr<IPlayer>;
    using SharedIPlayerPtr = std::shared_ptr<IPlayer>;

}

#endif //POKERSIMULATIONSINCPP_PLAYER_H
