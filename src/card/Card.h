//
// Created by CiaranWelsh on 07/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARD_H
#define POKERSIMULATIONSINCPP_CARD_H

using namespace std;

#include <string>
#include <utility>
#include <vector>
#include <ctime>
//#include "NumCpp/Random/generator.hpp"

namespace cards {

    static std::vector<int> getRanks() {
        std::vector<int> r = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        return r;
    }

    static std::vector<std::string> getSuits() {
        std::vector<std::string> s = {"S", "H", "D", "C"};
        return s;
    }

    class ICard {
    protected:
        int rank_;
        std::string suit_;
    public:

        ICard(int rank, std::string suit) : rank_(rank), suit_(std::move(suit)) {};

        [[nodiscard]] virtual int getRank() const = 0;

        [[nodiscard]] virtual std::string getSuit() const  = 0;

        friend std::ostream &operator<<(std::ostream &os, const ICard &c);

        bool operator>(const ICard &other) const;

        bool operator<(const ICard &other) const;

        bool operator<=(const ICard &other) const;

        bool operator>=(const ICard &other) const;

        bool operator==(const ICard &other) const;

        bool operator!=(const ICard &other) const;
    };

    class Card : public ICard {
    public:

        Card(int r, std::string s);

        [[nodiscard]] int getRank() const override;

        [[nodiscard]] std::string getSuit() const override;

    };

}


#endif //POKERSIMULATIONSINCPP_CARD_H
