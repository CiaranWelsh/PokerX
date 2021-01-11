//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_POKER_H
#define POKERSIMULATIONSINCPP_POKER_H


class Poker {

public:
    Poker() = default;

    [[nodiscard]] unsigned int getNumPlayers() const;

    void setNumPlayers(unsigned int numPlayers);

    [[nodiscard]] float getSmallBlind() const;

    void setSmallBlind(float smallBlind);

    [[nodiscard]] float getBigBlind() const;

    void setBigBlind(float bigBlind);

    void playConsole();

private:
    unsigned int num_players_;
    float small_blind = 1.0;
    float big_blind = 2.0;

};


#endif //POKERSIMULATIONSINCPP_POKER_H
