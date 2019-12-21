//
// Created by CiaranWelsh on 19/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_EVALUATOR_H
#define POKERSIMULATIONSINCPP_EVALUATOR_H

#include <vector>
#include "Hand.h"

//need to figure out how to implement a factory design for hand objects. I'll have a single method or object
// in which the user interacts with.
namespace eval {
    class Evaluator {
    private:

    public:
        Evaluator() = default;

        void evaluate(Hand &hand);

        void evaluate(std::vector<Hand> hands);

    };

}
#endif //POKERSIMULATIONSINCPP_EVALUATOR_H
