//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_EGAMEPLAYSTATE_H
#define POKERX_EGAMEPLAYSTATE_H

namespace pokerx {
    enum eBettingState {
        ENTER_STREET,
        PLAYER_TO_ACT_STATE,
        REMOVE_CHECK_FROM_ACTIONS,
        NEXT_PLAYER_STATE,
        EXIT_STREET,
    };

}

#endif //POKERX_EGAMEPLAYSTATE_H
