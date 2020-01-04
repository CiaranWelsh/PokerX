//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_NEXTPLAYER_H
#define POKERSIMULATIONSINCPP_NEXTPLAYER_H

#include "PlayerEvent.h"
#include "RotatePlayers.h"

namespace events {
    /*
     * Conceptually, rotating players at the begining of a hand
     * is the same as moving to the next player. To make this clear
     * the folloing alias is defined.
     */
    typedef RotatePlayers NextPlayer;
}

#endif //POKERSIMULATIONSINCPP_NEXTPLAYER_H
