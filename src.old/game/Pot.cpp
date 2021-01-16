/**
 * Project PokerSimulationsInCpp
 */


#include <iostream>
#include <dshow.h>
#include <sstream>
#include "Pot.h"

Pot::Pot(int value) : value((double) value) {};

Pot::Pot(float value) : value(value) {}

Pot &Pot::operator+(const Pot &other) {
    value += other.value;
    return *this;
}

Pot &Pot::operator-(const Pot &other) {
    if (other.value > this->value)
        throw errors::NegativePotValue("You have negative pot amounts", __FILE__, __LINE__);
    value -= other.value;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Pot &pot) {
    os << "Pot(value=" << pot.value << ")";
    return os;
}

Pot &Pot::operator=(int amount) {
    value = (double) amount;
    return *this;
}
Pot &Pot::operator=(double amount) {
    value = amount;
    return *this;
}

Pot &Pot::operator+(const double &amount) {
    value += amount;
    return *this;
}

Pot &Pot::operator-(const double &amount) {
    if (amount > this->value)
        throw errors::NegativePotValue("You have negative pot amounts", __FILE__, __LINE__);
    value -= amount;
    return *this;
}
Pot &Pot::operator+=(const double &amount) {
    value += amount;
    return *this;
}

Pot &Pot::operator-=(const double &amount) {
    value -= amount;
    return *this;
}

bool Pot::operator==(const double& amount) {
    return value == amount;
}

bool Pot::operator!=(const double &amount) {
    return (!(*this == amount));
}

Pot::Pot() = default;

Pot::~Pot() = default;
