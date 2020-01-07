//
// Created by CiaranWelsh on 07/01/2020.
//

#include <dshow.h>
#include "PlayerAction.h"

void events::PlayerAction::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
    boost::shared_ptr<Player> player = players.getCurrentPlayer();
    ActionType action = player->choose_action(gamePlay.action_set);
    if (action == NoAction)
        throw errors::InvalidActionError();
    players.getCurrentPlayer()->play(action);

}
