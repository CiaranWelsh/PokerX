//
// Created by CiaranWelsh on 19/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_EVALUATOR_H
#define POKERSIMULATIONSINCPP_EVALUATOR_H

#include <vector>
#include "Hand.h"

namespace eval {
    class Evaluator {
    private:
        pass
    public:
        Evaluator() = default;

        void evaluate(Hand &hand);

        void evaluate(std::vector<Hand> hands);

    };

}
#endif //POKERSIMULATIONSINCPP_EVALUATOR_H
