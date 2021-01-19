//
// Created by Ciaran on 19/01/2021.
//

#ifndef POKERX_STREETS_H
#define POKERX_STREETS_H

namespace pokerx {

    enum Street {
        PREFLOP_STREET = 0,
        FLOP_STREET = 1,
        TURN_STREET = 2,
        RIVER_STREET = 3,
        SHOWDOWN_STREET = 4,
    };
}

#endif //POKERX_STREETS_H
