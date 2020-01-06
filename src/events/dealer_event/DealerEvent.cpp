//
// Created by CiaranWelsh on 02/01/2020.
//

#include "DealerEvent.h"

namespace events{

    void DealerEvent::go(game::GamePlay &gamePlay, game::PlayerPtr &current_player, game::Dealer &dealer) {
        cout << "go in DealerEvent" << endl;
    }
}