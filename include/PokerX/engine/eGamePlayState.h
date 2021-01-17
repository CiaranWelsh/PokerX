//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_EGAMEPLAYSTATE_H
#define POKERX_EGAMEPLAYSTATE_H

namespace pokerx {
    enum eGamePlayState {
        RESET  = 0,
        BUTTON_MOVES = 1,
        SMALL_BLIND = 2,
        BIG_BLIND = 3,
        PREFLOP = 4,
        FLOP = 5,
        TURN = 6,
        RIVER = 7,
        SHOWDOWN = 8,
    };

}

#endif //POKERX_EGAMEPLAYSTATE_H
