//
// Created by CiaranWelsh on 07/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARD_H
#define POKERSIMULATIONSINCPP_CARD_H

using namespace std;

#include <string>

namespace Game {

class Card {
private:
    int ranks[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    char suits[4] = {'S', 'H', 'D', 'H'};
public:
    int rank; // 1 to 13
    char suit;

    Card(int r, char s);

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
