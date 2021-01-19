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

        ALL_PLAYERS_EQUAL = 9,
        CALL_STATE = 10, // to distinguish between the Action
        CHECK_STATE = 11, // to distinguish between the Action
        FOLD_STATE = 12, // to distinguish between the Action
        RAISE_STATE = 13, // to distinguish between the Action
        NEXT_PLAYER = 14,
        REMOVE_CHECK_FROM_OPTIONS = 15,
        START_STREET = 16,
        END_STREET = 17,
        PLAYER_TO_ACT = 18

    };

}

#endif //POKERX_EGAMEPLAYSTATE_H
