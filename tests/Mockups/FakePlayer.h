#ifndef POKERX_FAKEPLAYER_H
#define POKERX_FAKEPLAYER_H

#include "MockPokerEngine.h"
#include "PokerX/engine/Action.h"
#include "PokerX/engine/Player.h"

using namespace pokerx;

class FakePlayer: public Player {
public:

    FakePlayer() = default;

    FakePlayer(std::string name, float stack)
        : Player(std::move(name), stack){};

    pokerx::Action selectAction(StateMachine *engine) override{
        return CALL;
    }

    float raise() override{
        float raiseAmount = getGameVariables()->getAmountToCall()*2;
        float callAmount = getGameVariables()->getAmountToCall();
        stack_ -= (raiseAmount + callAmount);
        getGameVariables()->getPot() += (raiseAmount + callAmount);
        return (raiseAmount + callAmount);
    }


};



#endif //POKERX_FAKEPLAYER_H
