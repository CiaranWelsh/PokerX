//
// Created by CiaranWelsh on 08/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_EQUALITYCHECKER_H
#define POKERSIMULATIONSINCPP_EQUALITYCHECKER_H


#include <vector>
#include <algorithm>
#include <functional>


namespace utils {
/*
 * Check for equality between a vector of elements
 */
    template<class T>
    bool EqualityChecker(std::vector<T> vec) {
        bool equal = false;
        if (std::adjacent_find(vec.begin(), vec.end(), std::not_equal_to<>()) == vec.end()) {
            equal = true;
        }
        return equal;
    }
}
#endif //POKERSIMULATIONSINCPP_EQUALITYCHECKER_H
