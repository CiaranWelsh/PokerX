//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_GAMEVARIABLES_H
#define POKERX_GAMEVARIABLES_H

#include "PokerX/engine/Pot.h"

namespace pokerx {

    class GameVariables {

    public:

        GameVariables() = default;

        [[nodiscard]] Pot getPot() const;


    private:
        Pot pot_;

    };
}

#endif //POKERX_GAMEVARIABLES_H
