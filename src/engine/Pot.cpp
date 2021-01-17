#include "PokerX/engine/Pot.h"
#include "PokerX/Error.h"

Pot::Pot(int value) : value_(static_cast<float>(value)) {};

Pot::Pot(float value) : value_(value) {}

Pot &Pot::operator+(const Pot &other) {
    value_ += other.value_;
    return *this;
}

Pot &Pot::operator-(const Pot &other) {
    if (other.value_ > this->value_)
        LOGIC_ERROR << "You have negative pot amounts" << std::endl;
    value_ -= other.value_;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Pot &pot) {
    os << "Pot(value_=" << pot.value_ << ")";
    return os;
}

Pot &Pot::operator+(const float &amount) {
    value_ += amount;
    return *this;
}

Pot &Pot::operator-(const float &amount) {
    if (amount > this->value_)
        LOGIC_ERROR << "You have negative pot amounts" << std::endl;
    value_ -= amount;
    return *this;
}
Pot &Pot::operator+=(const float &amount) {
    value_ += amount;
    return *this;
}

Pot &Pot::operator-=(const float &amount) {
    value_ -= amount;
    return *this;
}

bool Pot::operator==(const float& amount) const {
    return value_ == amount;
}

bool Pot::operator!=(const float &amount) {
    return (!(*this == amount));
}

void Pot::reset() {
    value_ = 0;

}

float Pot::getValue() const {
    return value_;
}
