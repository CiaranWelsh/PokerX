//
// Created by CiaranWelsh on 07/01/2020.
//

#include "PlayerAction.h"

void events::PlayerAction::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
//    PlayerEvent::go(gamePlay, players, dealer);

    players.getCurrentPlayer()->play()

}
