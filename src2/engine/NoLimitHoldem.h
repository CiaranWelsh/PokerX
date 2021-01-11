//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_POKERENGINE_H
#define POKERSIMULATIONSINCPP_POKERENGINE_H

#include "EngineState.h"
#include "Player.h"
#include "Pot.h"
#include <vector>

namespace engine {

    // forward declarations
    class EngineState;
    class Player;

    /**
     * More generally:
     *  Engine --> GameEngine --> PokerEngine --> TexasHoldemEngine
     */

    class Engine {
    public:
        Engine() = default;
        virtual void setState(EngineState& state) = 0;

        virtual void reset() = 0;

        virtual void rotate() = 0;
    };

    class PokerEngine : public Engine {
    public:
        PokerEngine();

        [[nodiscard]] EngineState *getCurrentState() const;

        void action();

        void setState(EngineState &state) override;

        void reset() override;

        void rotate() ovrride;

        int getNPlayers() const;

        void setNPlayers(int nPlayers);

        void setCurrentBet(float currentBet);

        float getCurrentBet() const;

        void contribPot(float amount);

        EngineState *getState() const;

        const std::vector<Player *> &getPlayers() const;

        const Pot &getPot() const;

    private:

        void initPlayers();

        EngineState *state_;
        int nPlayers_ = 6;
        std::vector<Player *> players_;
        float currentBet_ = 0.0;
        Pot pot_;
    };
}
#endif //POKERSIMULATIONSINCPP_POKERENGINE_H
