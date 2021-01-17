//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_GAMEVARIABLES_H
#define POKERX_GAMEVARIABLES_H

#include "PokerX/engine/Pot.h"

namespace pokerx {

    /**
     * The fact that GameVariables is difficult to make
     * a interface for is probably a code smell.
     *
     * We could create a "Variables" interface. But then, what
     * would go in it. Its too vague. And so is GameVariables.
     * Therefore, I should consider refactoring GameVaribales
     * into the components that will make up a GameVariables
     * object.
     */

    class GameVariables {

    public:

        GameVariables() = default;

        [[nodiscard]] Pot getPot() const;


    private:
        Pot pot_;

    };
}

#endif //POKERX_GAMEVARIABLES_H
