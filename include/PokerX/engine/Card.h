//
// Created by CiaranWelsh on 07/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_CARD_H
#define POKERSIMULATIONSINCPP_CARD_H

#include <string>
#include <memory>
#include <vector>
#include <ctime>

namespace pokerx {

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
        int rank_ = 14;
        std::string suit_ = "S";
    public:
        ICard(int rank, std::string suit) : rank_(rank), suit_(std::move(suit)) {};

        ICard() = default;

        virtual ~ICard() = default;

        virtual void setRank(int rank) = 0;

        virtual void setSuit(const std::string &suit) = 0;

        [[nodiscard]] virtual int getRank() const = 0;

        [[nodiscard]] virtual std::string getSuit() const = 0;

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

        using ICard::ICard;

        void setRank(int rank) override;

        void setSuit(const std::string &suit) override;

        [[nodiscard]] int getRank() const override;

        [[nodiscard]] std::string getSuit() const override;
    };

    using ICardPtr = std::unique_ptr<ICard>;

}


#endif //POKERSIMULATIONSINCPP_CARD_H
