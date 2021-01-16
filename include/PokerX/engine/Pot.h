/**
 * Project PokerSimulationsInCpp
 */
#include "ostream"

#ifndef _POT_H
#define _POT_H

class Pot {
public:
    float value_ = 0.0;

    Pot() = default;

    explicit Pot(float value);

    explicit Pot(int value);

    Pot& operator+(const Pot& other);

    Pot& operator+(const float& amount);

    Pot& operator+=(const float& amount);

    Pot& operator-(const Pot& other);

    Pot& operator-(const float& amount);

    Pot& operator-=(const float& amount);

    bool operator==(const float &amount) const;

    bool operator!=(const float &amount);

    friend std::ostream &operator<<(std::ostream &os, const Pot& pot);

    void reset();
};

#endif //_POT_H