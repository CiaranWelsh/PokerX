//
// Created by CiaranWelsh on 07/01/2020.
//

#include <dshow.h>
#include "PlayerAction.h"

void events::PlayerAction::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                              double &amount_to_call) {
    boost::shared_ptr<Player> player = players.getCurrentPlayer();
    ActionType action = player->choose_action(gamePlay.action_set);
    if (action == NoAction)
        throw errors::InvalidActionError();
    // need to calculate amount to call here and
    // accept amount to raise
    double amount = 0.0; // for fold and check
    // when raised, switched to action set that doesn't contain check.
    switch (action) {
        case Check: {
            break;
        }
        case Fold: {
            break;
        }
        case Call: {
            cout << "amount to call is: " << amount_to_call << endl;
            amount = amount_to_call;
        }
        case Raise: {
            amount = 1.0;
        }
        case AllIn: {
            amount = 1.0;
        }
        case NoAction: {
        }
    }

    players.getCurrentPlayer()->play(gamePlay, action, amount);

}
