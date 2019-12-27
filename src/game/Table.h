/**
 * Project PokerSimulationsInCpp
 */


#ifndef _TABLE_H
#define _TABLE_H

class Table {
public: 
    Pot pot;
    Positions positions;
    Player players;
    Dealer dealer;
    double small_blind;
    void Attribute1;
};

#endif //_TABLE_H