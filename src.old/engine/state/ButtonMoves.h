//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_BUTTONMOVES_H
#define POKERSIMULATIONSINCPP_BUTTONMOVES_H

#include "IState.h"

class ButtonMoves : public IState {
public:

    void enter(IEntity *entity) override;

    void action(IEntity *entity) override;

    void exit(IEntity *entity) override;

    static IState &getInstance();

private:

    ButtonMoves() = default;

};


#endif //POKERSIMULATIONSINCPP_BUTTONMOVES_H
