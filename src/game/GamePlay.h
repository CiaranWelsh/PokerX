//
// Created by CiaranWelsh on 05/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_GAMEPLAY_H
#define POKERSIMULATIONSINCPP_GAMEPLAY_H

#include <players/ActionType.h>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <cards/CardCollection.h>
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

        // once somebody has raised, you can no longer check
        bool raised = false;
        typedef std::vector<ActionType> ActionTypeVec;

        ActionTypeVec action_set_raise = {Call, Fold, Raise};
        std::shared_ptr<ActionTypeVec> action_set_raise_ptr = std::make_unique<ActionTypeVec>(action_set_raise);
        ActionTypeVec action_set_check = {Check, Call, Fold, Raise};
        std::shared_ptr<ActionTypeVec> action_set_check_ptr = std::make_unique<ActionTypeVec>(action_set_check);
        // start with action_set pointing at action_set_check
        std::shared_ptr<ActionTypeVec> action_set = std::make_unique<ActionTypeVec>(action_set_check);

        // When all players are equal after starting a street, we know to move on to the next street
        bool all_players_equal = false;

        std::shared_ptr<cards::CardCollection> flop;
        std::shared_ptr<cards::Card> turn;
        std::shared_ptr<cards::Card> river;

        std::shared_ptr<double> highest_bidder;
        std::shared_ptr<double> amount_to_call;
        std::shared_ptr<double> amount_raised;
        std::shared_ptr<double> amount_for_all_in;
        double largest_bidder_amount = 0.0;
    };
}

#endif //POKERSIMULATIONSINCPP_GAMEPLAY_H
