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

    Card *CardFactory(std::string cardString);

    using ICardPtr = std::unique_ptr<ICard>;


    class Cards {
    public:
        Card lowAceOfSpades;
        Card twoOfSpades;
        Card threeOfSpades;
        Card fourOfSpades;
        Card fiveOfSpades;
        Card sixOfSpades;
        Card sevenOfSpades;
        Card eightOfSpades;
        Card nineOfSpades;
        Card tenOfSpades;
        Card jackOfSpades;
        Card queenOfSpades;
        Card kingOfSpades;
        Card aceOfSpades;
        Card lowAceOfDiamonds;
        Card twoOfDiamonds;
        Card threeOfDiamonds;
        Card fourOfDiamonds;
        Card fiveOfDiamonds;
        Card sixOfDiamonds;
        Card sevenOfDiamonds;
        Card eightOfDiamonds;
        Card nineOfDiamonds;
        Card tenOfDiamonds;
        Card jackOfDiamonds;
        Card queenOfDiamonds;
        Card kingOfDiamonds;
        Card aceOfDiamonds;
        Card lowAceOfClubs;
        Card twoOfClubs;
        Card threeOfClubs;
        Card fourOfClubs;
        Card fiveOfClubs;
        Card sixOfClubs;
        Card sevenOfClubs;
        Card eightOfClubs;
        Card nineOfClubs;
        Card tenOfClubs;
        Card jackOfClubs;
        Card queenOfClubs;
        Card kingOfClubs;
        Card aceOfClubs;
        Card lowAceOfHearts;
        Card twoOfHearts;
        Card threeOfHearts;
        Card fourOfHearts;
        Card fiveOfHearts;
        Card sixOfHearts;
        Card sevenOfHearts;
        Card eightOfHearts;
        Card nineOfHearts;
        Card tenOfHearts;
        Card jackOfHearts;
        Card queenOfHearts;
        Card kingOfHearts;
        Card aceOfHearts;

        Cards() {
            lowAceOfSpades = Card(1, "S");
            twoOfSpades = Card(2, "S");
            threeOfSpades = Card(3, "S");
            fourOfSpades = Card(4, "S");
            fiveOfSpades = Card(5, "S");
            sixOfSpades = Card(6, "S");
            sevenOfSpades = Card(7, "S");
            eightOfSpades = Card(8, "S");
            nineOfSpades = Card(9, "S");
            tenOfSpades = Card(10, "S");
            jackOfSpades = Card(11, "S");
            queenOfSpades = Card(12, "S");
            kingOfSpades = Card(13, "S");
            aceOfSpades = Card(14, "S");
            lowAceOfDiamonds = Card(1, "D");
            twoOfDiamonds = Card(2, "D");
            threeOfDiamonds = Card(3, "D");
            fourOfDiamonds = Card(4, "D");
            fiveOfDiamonds = Card(5, "D");
            sixOfDiamonds = Card(6, "D");
            sevenOfDiamonds = Card(7, "D");
            eightOfDiamonds = Card(8, "D");
            nineOfDiamonds = Card(9, "D");
            tenOfDiamonds = Card(10, "D");
            jackOfDiamonds = Card(11, "D");
            queenOfDiamonds = Card(12, "D");
            kingOfDiamonds = Card(13, "D");
            aceOfDiamonds = Card(14, "D");
            lowAceOfClubs = Card(1, "C");
            twoOfClubs = Card(2, "C");
            threeOfClubs = Card(3, "C");
            fourOfClubs = Card(4, "C");
            fiveOfClubs = Card(5, "C");
            sixOfClubs = Card(6, "C");
            sevenOfClubs = Card(7, "C");
            eightOfClubs = Card(8, "C");
            nineOfClubs = Card(9, "C");
            tenOfClubs = Card(10, "C");
            jackOfClubs = Card(11, "C");
            queenOfClubs = Card(12, "C");
            kingOfClubs = Card(13, "C");
            aceOfClubs = Card(14, "C");
            lowAceOfHearts = Card(1, "H");
            twoOfHearts = Card(2, "H");
            threeOfHearts = Card(3, "H");
            fourOfHearts = Card(4, "H");
            fiveOfHearts = Card(5, "H");
            sixOfHearts = Card(6, "H");
            sevenOfHearts = Card(7, "H");
            eightOfHearts = Card(8, "H");
            nineOfHearts = Card(9, "H");
            tenOfHearts = Card(10, "H");
            jackOfHearts = Card(11, "H");
            queenOfHearts = Card(12, "H");
            kingOfHearts = Card(13, "H");
            aceOfHearts = Card(14, "H");
        }
    };

}


#endif //POKERSIMULATIONSINCPP_CARD_H
