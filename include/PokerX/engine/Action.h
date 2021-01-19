//
// Created by Ciaran on 10/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_ACTION_H
#define POKERSIMULATIONSINCPP_ACTION_H

namespace pokerx {
    enum Action {
        NONE = 0,
        CHECK = 1,
        FOLD = 2,
        CALL = 3,
        RAISE = 4,
        ALL_IN = 5,
    };
}
#endif //POKERSIMULATIONSINCPP_ACTION_H
