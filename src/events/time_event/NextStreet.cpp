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
            std::cout << "Moving from preflop to flop" << endl;
            gamePlay.street = game::Flop;
            gamePlay.preflop_done = true;
            gamePlay.flop = std::make_unique<CardCollection>(dealer.dealFlop());

        }
        case game::Flop:{
            std::cout << "Moving from flop to turn" << endl;
            gamePlay.street = game::Turn;
            gamePlay.flop_done = true;
            gamePlay.turn = std::make_unique<cards::Card>(dealer.dealTurn());
        }
        case game::Turn:{
            std::cout << "Moving from turn to river" << endl;
            gamePlay.street = game::River;
            gamePlay.turn_done = true;
            gamePlay.river = std::make_unique<cards::Card>(dealer.dealRiver());
        }
        case game::River:{
            std::cout << "Moving from river to showdown " << endl;
            gamePlay.river_done = true;
            gamePlay.street = game::Showdown;
        }
        case game::Showdown:{
            std::cout << "Moving from showdown to endgame" << endl;
            gamePlay.game_ended = true;
            gamePlay.street = game::EndGame;
        }
        case game::EndGame:{
            cout << "turning game_ended to true" << endl;
            gamePlay.game_ended = true;
        }
    }


}
