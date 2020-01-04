/**
 * Project PokerSimulationsInCpp
 */


#include <iostream>
#include "Pot.h"


Pot::Pot(int value) : value((double) value) {};

Pot::Pot(Pot &pot) {this->value = pot.value;}

Pot::Pot(double value) : value(value) {}

Pot &Pot::operator+(const Pot &other) {
    value += other.value;
    return *this;
}

Pot &Pot::operator-(const Pot &other) {
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
    value += amount;
    return *this;
}
Pot &Pot::operator+=(const double &amount) {
    value += amount;
    return *this;
}

Pot &Pot::operator-=(const double &amount) {
    value += amount;
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
