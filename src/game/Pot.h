/**
 * Project PokerSimulationsInCpp
 */


#ifndef _POT_H
#define _POT_H

class Pot {
public:
    double value;

    Pot();

    explicit Pot(double value);

    explicit Pot(int value);

    Pot(Pot &pot);

    ~Pot();

    Pot& operator+(const Pot& other);

    Pot& operator-(const Pot& other);

    friend std::ostream &operator<<(std::ostream &os, const Pot& pot);
};

#endif //_POT_H