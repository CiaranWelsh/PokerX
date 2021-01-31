//
// Created by Ciaran Welsh on 30/01/2021.
//

#include "PokerX/engine/Evaluator.h"


namespace pokerx{

    std::pair<int, Hand> Evaluator::evaluate(std::initializer_list<Hand> hands) {
        // how to pass this into std::max?
        std::vector<Hand> v(hands.begin(), hands.end());
        auto pos = std::max_element(v.begin(), v.end());
        int idx = std::distance(v.begin(), pos);
        std::pair<int, Hand> ret(idx, v[idx]);
        return ret;
    }
}