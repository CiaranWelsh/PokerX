//
// Created by CiaranWelsh on 05/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_GAMEPLAY_H
#define POKERSIMULATIONSINCPP_GAMEPLAY_H

#include "Street.h"
#include "Pot.h"

namespace game {
    struct GamePlay {
    public:
        // boolean flags marking poker landmarks
        Street street = Preflop;
        bool game_started = false;
        bool game_ended = false;
        bool small_blind_posted = false;
        bool big_blind_posted = false;
        bool ante_posted = false;
        bool dealt_hole_cards = false;
        bool preflop_done = false;
        bool flop_done = false;
        bool turn_done = false;
        bool river_done = false;
        bool dealt_preflop = false;
        bool dealt_flop = false;
        bool dealt_turn = false;
        bool dealt_river = false;
        bool showdown = false;

        double small_blind = 0.5;
        double big_blind = 1.0;

        Pot pot;

    };
}

#endif //POKERSIMULATIONSINCPP_GAMEPLAY_H
