//
// Created by CiaranWelsh on 08/01/2020.
//

#include "DealFlop.h"

void
events::DealFlop::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer, double &amount_to_call) {
    gamePlay.communityCards.add(dealer.dealFlop());
}
