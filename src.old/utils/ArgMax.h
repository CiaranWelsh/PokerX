//
// Created by CiaranWelsh on 10/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_ARGMAX_H
#define POKERSIMULATIONSINCPP_ARGMAX_H

#include <stdexcept>
#include <algorithm>
#include <map>

namespace utils {

    template<typename KeyType, typename ValueType>
    std::pair<KeyType, ValueType> GetMaxOfMap(const std::map<KeyType, ValueType> &x) {
        using pairtype=std::pair<KeyType, ValueType>;
        return *std::max_element(x.begin(), x.end(), [](const pairtype &p1, const pairtype &p2) {
            return p1.second < p2.second;
        });
    }
}

#endif //POKERSIMULATIONSINCPP_ARGMAX_H
