//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_EGAMEPLAYSTATE_H
#define POKERX_EGAMEPLAYSTATE_H

namespace pokerx {
    enum eGamePlayState {
        RESET_STATE  = 0,
        BUTTON_MOVES_STATE = 1,
        SMALL_BLIND_STATE = 2,
        BIG_BLIND_STATE = 3,
        PREFLOP_STATE = 4,
        FLOP_STATE = 5,
        TURN_STATE = 6,
        RIVER_STATE = 7,
        SHOWDOWN_STATE = 8,

        ALL_PLAYERS_EQUAL_STATE = 9,
        CALL_STATE_STATE = 10, // to distinguish between the Action
        CHECK_STATE_STATE = 11, // to distinguish between the Action
        FOLD_STATE_STATE = 12, // to distinguish between the Action
        RAISE_STATE = 13, // to distinguish between the Action
        NEXT_PLAYER_STATE = 14,
        REMOVE_CHECK_FROM_OPTIONS_STATE = 15,
        START_STREET_STATE = 16,
        END_STREET_STATE = 17,
        PLAYER_TO_ACT_STATE = 18,
        NEXT_STREET_STATE = 19,
    };

}

#endif //POKERX_EGAMEPLAYSTATE_H
