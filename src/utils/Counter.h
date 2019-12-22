#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<class T>
class Counter {
private:
    vector<T> _to_be_counted;
    vector<T> _unique_elements;

    unordered_map<T, int> _count = count();

    vector<T> _get_unique_elements() {
        vector<T> unique;
        vector<std::string>::iterator ip;
        ip = std::unique(_unique_elements.begin(), _unique_elements.begin() + _unique_elements.size());
        _unique_elements.resize(std::distance(_unique_elements.begin(), ip));
        return _unique_elements;
    }

public:
    explicit Counter(vector<T> to_be_counted) : _to_be_counted(to_be_counted), _unique_elements(to_be_counted) {
        this->_unique_elements = _get_unique_elements();
    };

    unordered_map<T, int> count() {
        unordered_map<T, int> map{};
        for (const string &s: _get_unique_elements()) {
            int count = 0;
            for (int t = 0; t < _to_be_counted.size(); t++) {
                if (s == _to_be_counted[t]) {
                    count += 1;
                }
                bool x = s == _to_be_counted[t];
            }
            map[s] = count;
        }
        return map;
    };

    friend ostream &operator<<(ostream &os, const Counter &count) {
        os << "{";
        for (auto &element : count._count) {
            os << element.first << ": " << element.second << ", ";
        }
        os << "\b\b}";
        return os;
    };

};
