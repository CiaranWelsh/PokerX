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

    explicit Pot(float value);

    explicit Pot(int value);

    Pot(Pot &pot);

    ~Pot();

    Pot& operator+(const Pot& other);

    Pot& operator+(const double& amount);

    Pot& operator+=(const double& amount);

    Pot& operator-(const Pot& other);

    Pot& operator-(const double& amount);

    Pot& operator-=(const double& amount);

    Pot& operator=(int amount);

    Pot& operator=(double amount);

    bool operator==(const double &amount);

    bool operator!=(const double &amount);

    friend std::ostream &operator<<(std::ostream &os, const Pot& pot);
};

#endif //_POT_H