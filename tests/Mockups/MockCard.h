//
// Created by Ciaran on 02/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_MOCKCARD_H
#define POKERSIMULATIONSINCPP_MOCKCARD_H

#include <utility>

#include "card/Card.h"
#include "gmock/gmock.h"

using namespace cards;

class MockCard : public ICard {
public:
    MockCard(int rank, std::string suit) : ICard(rank, std::move(suit)){};
    MOCK_METHOD(int, getRank, (), (const, override));
    MOCK_METHOD(std::string, getSuit, (), (const, override));
};



#endif //POKERSIMULATIONSINCPP_MOCKCARD_H
