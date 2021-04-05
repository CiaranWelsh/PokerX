//
// Created by Ciaran Welsh on 30/01/2021.
//

#include "PokerX/engine/Evaluator.h"


namespace pokerx {

    std::pair<std::string, Hand> Evaluator::evaluate(std::unordered_map<std::string, Hand> hands) {
        using pair = std::pair<std::string, Hand>;
        return *std::max_element(hands.begin(), hands.end(), [] (const pair& a, const pair& b)->bool{ return a.second < b.second; } );
    }

}


















