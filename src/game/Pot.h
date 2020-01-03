/**
 * Project PokerSimulationsInCpp
 */
#include "ostream"

#ifndef _POT_H
#define _POT_H

class Pot {
public:
    double value = 0.0;

    Pot();

    explicit Pot(double value);

    explicit Pot(int value);

    Pot(Pot &pot);

    ~Pot();

    Pot& operator+(const Pot& other);

    Pot& operator-(const Pot& other);

    Pot& operator=(int amount);

    Pot& operator=(double amount);

    friend std::ostream &operator<<(std::ostream &os, const Pot& pot);
};

#endif //_POT_H