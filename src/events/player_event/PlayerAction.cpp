//
// Created by CiaranWelsh on 07/01/2020.
//

#include <dshow.h>
#include "PlayerAction.h"

void events::PlayerAction::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                              double &amount_to_call) {
    std::shared_ptr<Player> player = players.getCurrentPlayer();
    ActionType action = player->choose_action(gamePlay.action_set);
    if (action == NoAction)
        throw errors::InvalidActionError("ActionType NoAction is not to be used", __FILE__, __LINE__);
    // need to calculate amount to call here and
    // accept amount to raise
    double amount = 0.0; // for fold and check
    // when raised, switched to action set that doesn't contain check.
    switch (action) {
        case Check: {
            cout << player->getName() << " has checked" << endl;
            break;
        }
        case Fold: {
            player->inplay = false;
            cout << player->getName() << " has folded" << endl;
            break;
        }
        case Call: {
            amount = amount_to_call;
            cout << player->getName() << " has called" << endl;
            break;
        }
        case Raise: {
            amount = 1.0;
            cout << player->getName() << " has raised" << endl;
            break;
        }
        case AllIn: {
            amount = 1.0;
            break;
        }
        case NoAction: {
            break;
        }
    }

    players.getCurrentPlayer()->play(gamePlay, action, amount);

}
