//
// Created by CiaranWelsh on 02/01/2020.
//

#include <dshow.h>
#include "TimeEvent.h"


namespace events {

    void TimeEvent::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer,
                       double &amount_to_call) {
        throw errors::NotImplementedException("Cannot use the TimeEvent::go member function", __FILE__, __LINE__);
    }
}


