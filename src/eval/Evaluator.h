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

        ~Evaluator() = default;

        Evaluator(const Evaluator &evaluator) = default;

        Evaluator(Evaluator &&) = default;

        HandPtr evaluate(Hand &hand);

        map<int, HandType> evaluate(std::vector<HandPtr> hands);

        template<class T>
        static std::pair<T, std::vector<int>> getMaxValueOfAMap(const std::map<int, T> &map) {
            // get the value of the element with max HandType value
            T max_hand = HighCard_;
            for (auto it : map) {
                if (it.second > max_hand) {
                    max_hand = it.second;
                }
            }
            // get the indexes of value of the element with max HandType value
            std::vector<int> argmax;
            for (auto it : map) {
                if (it.second == max_hand) {
                    argmax.push_back(it.first);
                }
            }
            return std::pair<T, std::vector<int>>(max_hand, argmax);
        }

        template<class Keys, class Values>
        static std::vector<Keys> getKeysOfMap(std::map<Keys, Values> &map) {
            std::vector<Keys> x;
            for (auto i : map)
                x.push_back(i.first);
            return x;
        }

        template<class Keys, class Values>
        static std::vector<Values> getValuesOfMap(std::map<Keys, Values> &map) {
            std::vector<Values> x;
            for (auto i : map)
                x.push_back(i.second);
            return x;
        }

    };

}
#endif //POKERSIMULATIONSINCPP_EVALUATOR_H
