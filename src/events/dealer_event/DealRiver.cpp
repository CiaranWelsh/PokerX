//
// Created by CiaranWelsh on 08/01/2020.
//

#include "DealRiver.h"

void
events::DealRiver::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer, double &amount_to_call) {
    gamePlay.river = std::make_unique<cards::Card>(dealer.dealRiver());
}
