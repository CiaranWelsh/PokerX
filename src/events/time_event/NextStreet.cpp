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

    // set all players 'played_this_street' variable to false to allow proceeding with the
    // next round of betting.
    for (const game::PlayerPtr& player: players)
        player->played_this_street = false;


    // move to the next street
    switch (gamePlay.street){
        case game::Preflop:{
            std::cout << "Moving from preflop to flop" << endl;
            gamePlay.street = game::Flop;
//            gamePlay.preflop_done = true;
            gamePlay.communityCards.add(dealer.dealFlop());
            break;
        }
        case game::Flop:{
            std::cout << "Moving from flop to turn" << endl;
            gamePlay.street = game::Turn;
//            gamePlay.flop_done = true;
            gamePlay.communityCards.add(dealer.dealTurn());
            break;
        }
        case game::Turn:{
            std::cout << "Moving from turn to river" << endl;
            gamePlay.street = game::River;
//            gamePlay.turn_done = true;
            gamePlay.communityCards.add(dealer.dealRiver());
            break;
        }
        case game::River:{
            std::cout << "Moving from river to showdown " << endl;
//            gamePlay.river_done = true;
            gamePlay.street = game::Showdown;
            break;
        }
        case game::Showdown:{
            std::cout << "Moving from showdown to endgame" << endl;
//            gamePlay.game_ended = true;
            gamePlay.street = game::EndGame;
            break;
        }
        case game::EndGame:{
            cout << "turning game_ended to true" << endl;
            gamePlay.game_ended = true;
            break;
        }
    }
}
