//
// Created by Ciaran Welsh on 30/01/2021.
//

#ifndef POKERX_EVALUATOR_H
#define POKERX_EVALUATOR_H

#include <initializer_list>
#include "PokerX/engine/hands/Hand.h"

/**
 * We probably want to implement a hand observer here to
 * collect data
 */

namespace pokerx {

    class Evaluator {

    public:
        Evaluator() = default;

        std::pair<int, Hand> evaluate(std::initializer_list<Hand> hands);

    private:
        std::vector<Hand> hands_;

    };
}


#endif //POKERX_EVALUATOR_H
