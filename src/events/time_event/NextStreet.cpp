//
// Created by CiaranWelsh on 07/01/2020.
//

#include "NextStreet.h"

void events::NextStreet::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                            double &amount_to_call) {
    // collect player pots
    for (const game::PlayerPtr& playerPtr: players) {
        gamePlay.pot += playerPtr->pot.value;
        playerPtr->pot.value = 0;
    }

    // before start of street put ActionSet back to the one with check available
    gamePlay.action_set = gamePlay.action_set_check_ptr;


    // move to the next street
    switch (gamePlay.street){
        case game::Preflop:{
            gamePlay.street = game::Flop;
            gamePlay.flop = std::make_unique<CardCollection>(dealer.dealFlop());
        }
        case game::Flop:{
            gamePlay.street = game::Turn;
            gamePlay.turn = std::make_unique<cards::Card>(dealer.dealTurn());
        }
        case game::Turn:{
            gamePlay.street = game::River;
            gamePlay.river = std::make_unique<cards::Card>(dealer.dealRiver());
        }
        case game::River:{
            gamePlay.street = game::Showdown;
        }
        case game::Showdown:{
            gamePlay.street = game::EndGame;
        }
        case game::EndGame:{
            cout << "turning game_ended to true";
            gamePlay.game_ended = true;
        }
    }


}
