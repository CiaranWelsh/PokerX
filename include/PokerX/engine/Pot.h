/**
 * Project PokerSimulationsInCpp
 */
#include "ostream"

#ifndef POKERX_POT_H
#define POKERX_POT_H

class Pot {
public:

    Pot() = default;

    explicit Pot(float value);

    Pot &operator+(const Pot &other);

    Pot &operator+(const float &amount);

    Pot &operator+=(const float &amount);

    Pot &operator-(const Pot &other);

    Pot &operator-(const float &amount);

    Pot &operator-=(const float &amount);

    bool operator==(const float &amount) const;

    bool operator!=(const float &amount);

    friend std::ostream &operator<<(std::ostream &os, const Pot &pot);

    void reset();

    [[nodiscard]] float getValue() const;
private:
    float value_ = 0.0;
};

#endif //_POT_H