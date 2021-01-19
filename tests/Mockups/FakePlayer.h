#ifndef POKERX_FAKEPLAYER_H
#define POKERX_FAKEPLAYER_H

#include "MockPokerEngine.h"
#include "PokerX/engine/Action.h"

using namespace pokerx;

class FakePlayer: public Player {
public:

    FakePlayer() = default;

    FakePlayer(std::string name, float stack)
        : Player(std::move(name), stack){};

    pokerx::Action selectAction(StateMachine *engine) override{
        return CALL;
    }


};



#endif //POKERX_FAKEPLAYER_H
