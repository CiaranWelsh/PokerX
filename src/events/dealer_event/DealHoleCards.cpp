//
// Created by CiaranWelsh on 06/01/2020.
//

#include "DealHoleCards.h"

namespace events {
    void DealHoleCards::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
        dealer.dealHoleCards(players);
        // after dealing we point our player pointer at UTG1 position
        players.next_player(); // From small blind to big bling
        players.next_player(); // From big blind to UTG1
    }
}