//
// Created by Ciaran on 17/01/2021.
//

#include "PokerX/engine/Showdown.h"



#include <iostream>
#include <PokerX/engine/Evaluator.h>
#include "PokerX/engine/Showdown.h"
#include "PokerX/engine/Reset.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void Showdown::enter(StateMachine *machine) {

    }

    void Showdown::action(StateMachine *machine) {

        auto *engine = dynamic_cast<PokerEngine *>(machine);
        engine->getGameVariables()->setGamesPlayed(engine->getGameVariables()->numGamesPlayed() + 1);

        if (engine->getGameVariables()->numGamesPlayed() < engine->getGameVariables()->getN()){
            // if we only have one player in the pot, then they are the winner by default
            if (engine->getPlayers()->getNumPlayersStillInPot() == 1){
                for (auto &player : *engine->getPlayers()){
                    // in this situation, only 1 player is still in the pot
                    // so we look for them and call winner
                    if (!player->hasFolded()){
                        // todo do we also need to return amount contrib to winning player here?
                        player->setStack( player->getStack() + engine->getGameVariables()->getPot().getValue());
                        engine->setState(Reset::getInstance());
                        return;
                    }
                }
            }

            // stack stuff taken care of by this method too
            Evaluator eval;
            auto [winnerIdx, hand] = eval.evaluate(engine->getPlayers()->getPlayerHands());
            std::cout << "winner is " << winnerIdx << " with " << hand << std::endl;
            auto winner = (*engine->getPlayers())[winnerIdx];
            winner->setStack( winner->getStack() + engine->getGameVariables()->getPot().getValue());


            engine->setState(Reset::getInstance());
        } else {
            // we done
            // todo print out more interesting information. Logger? Observational data recorder? Stats?
            std::cout <<"Number of games played: " << engine->getGameVariables()->getN() << std::endl;
            engine->getGameVariables()->setDone(true);
        }

    }

    void Showdown::exit(StateMachine *machine) {
    }

    Showdown &Showdown::getInstance() {
        static Showdown singleton;
        return singleton;
    }

    unsigned int Showdown::getType() const {
        return SHOWDOWN_STATE;
    }
}

