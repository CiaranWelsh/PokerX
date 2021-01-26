#ifndef POKERSIMULATIONSINCPP_COUNTER_H
#define POKERSIMULATIONSINCPP_COUNTER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

//using namespace std;

template<class T>
class Counter {


public:
    explicit Counter(std::vector<T> to_be_counted) : to_be_counted_(to_be_counted), unique_elements_(to_be_counted) {
        this->unique_elements_ = get_unique_elements();
    };

    std::unordered_map<T, int> count() {
        std::unordered_map<T, int> map{};
        for (auto &s: get_unique_elements()) {
            int count = 0;
            for (int t = 0; t < to_be_counted_.size(); t++) {
                if (s == to_be_counted_[t]) {
                    count += 1;
                }
            }
            map[s] = count;
        }
        return map;
    };
private:
    std::vector<T> to_be_counted_;
    std::vector<T> unique_elements_;

    std::unordered_map<T, int> count_ = count();

    std::vector<T> get_unique_elements() {
        std::vector<T> unique;
        typename std::vector<T>::iterator ip;
        ip = std::unique(unique_elements_.begin(), unique_elements_.begin() + unique_elements_.size());
        unique_elements_.resize(std::distance(unique_elements_.begin(), ip));
        return unique_elements_;
    }

    friend std::ostream &operator<<(std::ostream &os, const Counter &count) {
        os << "{";
        for (auto &element : count.count_) {
            os << element.first << ": " << element.second << ", ";
        }
        os << "\b\b}";
        return os;
    };

};


#endif // POKERSIMULATIONSINCPP_COUNTER_H