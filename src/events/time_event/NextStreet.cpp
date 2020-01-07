//
// Created by CiaranWelsh on 07/01/2020.
//

#include "NextStreet.h"

void events::NextStreet::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer) {
    // collect player pots
    for (const game::PlayerPtr& playerPtr: players)
        gamePlay.pot += playerPtr->pot.value;

    // move to the next street
    switch (gamePlay.street){
        case game::Preflop:{
            gamePlay.street = game::Flop;
        }
        case game::Flop:{
            gamePlay.street = game::Turn;
        }
        case game::Turn:{
            gamePlay.street = game::River;
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
