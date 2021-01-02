//
// Created by CiaranWelsh on 07/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARD_H
#define POKERSIMULATIONSINCPP_CARD_H

using namespace std;

#include <string>
#include <vector>
#include <ctime>
//#include "NumCpp/Random/generator.hpp"

namespace cards {

    const std::vector<int> RANKS = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    const std::vector<std::string> SUITS = {"S", "H", "D", "C"};

    class Card {
    public:
        int rank; // 1 to 13
        std::string suit;

        Card(int r, std::string s);

        ~Card();

        Card(const Card &other); // copy constructor
        friend std::ostream &operator<<(std::ostream &os, const Card &c);

        Card &operator=(const Card &c);

        bool operator>(const Card &other);

        bool operator<(const Card &other);

        bool operator<=(const Card &other);

        bool operator>=(const Card &other);

        bool operator==(const Card &other);

        bool operator!=(const Card &other);
    };

}


#endif //POKERSIMULATIONSINCPP_CARD_H
