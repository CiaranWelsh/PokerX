//
// Created by CiaranWelsh on 02/01/2020.
//

#include "DealerEvent.h"

namespace events{

    void DealerEvent::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                         double &amount_to_call) {
        cout << "go in DealerEvent" << endl;
    }
}