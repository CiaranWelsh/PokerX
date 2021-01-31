//
// Created by Ciaran Welsh on 30/01/2021.
//

#include "PokerX/engine/Evaluator.h"


namespace pokerx {

    std::pair<int, Hand> Evaluator::evaluate(std::initializer_list<Hand> hands) {
        // how to pass this into std::max?
        std::vector<Hand> v(hands.begin(), hands.end());
        return evaluate(v);
    }

    std::pair<int, Hand> Evaluator::evaluate(std::vector<Hand> hands) {
        auto pos = std::max_element(hands.begin(), hands.end());
        int idx = std::distance(hands.begin(), pos);
        std::pair<int, Hand> ret(idx, hands[idx]);
        return ret;
    }

}