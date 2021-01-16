//
// Created by CiaranWelsh on 05/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_GAMEPLAY_H
#define POKERSIMULATIONSINCPP_GAMEPLAY_H

class community_cards;

#include <players/ActionType.h>
#include <vector>
#include <memory>
#include "card/CardCollection.h"
#include "Street.h"
#include "Pot.h"
#include "eval/Hand.h"
#include "card/CommunityCards.h"

namespace game {
    struct GamePlay {
    public:
        typedef std::vector<ActionType> ActionTypeVec;

        // boolean flags marking poker landmarks
        Street street = Preflop;
        bool game_started = false;
        bool game_ended = false;
        std::vector<int> winning_players;
        eval::HandType winning_hand;
        double small_blind = 0.5;
        double big_blind = 1.0;
        Pot pot;
        // once somebody has raised, you can no longer check
        bool raised = false;
        ActionTypeVec action_set_raise = {Call, Fold, Raise};
        ActionTypeVec action_set_check = {Check, Call, Fold, Raise};
        std::shared_ptr<ActionTypeVec> action_set_check_ptr = std::make_unique<ActionTypeVec>(action_set_check);
        std::shared_ptr<ActionTypeVec> action_set_raise_ptr = std::make_unique<ActionTypeVec>(action_set_raise);
        // start with action_set pointing at action_set_check
        std::shared_ptr<ActionTypeVec> action_set = std::make_unique<ActionTypeVec>(action_set_check);
        // When all players are equal after starting a street, we know to move on to the next street
        bool all_players_equal = false;
        cards::CommunityCards communityCards;
        std::shared_ptr<double> highest_bidder;
        std::shared_ptr<double> amount_to_call;
        std::shared_ptr<double> amount_raised;
        std::shared_ptr<double> amount_for_all_in;
        double largest_bidder_amount = 0.0;
    };
//    GamePlay &GamePlay::operator=(GamePlay &gamePlay) {
//        street = gamePlay.street;
//        game_started = gamePlay.game_started;
//        game_ended = gamePlay.game_ended;
//        winning_players = gamePlay.winning_players;
//        winning_hand = gamePlay.winning_hand;
//        small_blind = gamePlay.small_blind;
//        big_blind = gamePlay.big_blind;
//        pot = gamePlay.pot;
//        raised = gamePlay.raised;
//        action_set_raise = gamePlay.action_set_raise;
//        action_set_check = gamePlay.action_set_check;
//        action_set_check_ptr = gamePlay.action_set_check_ptr;
//        action_set = gamePlay.action_set;
//        all_players_equal = gamePlay.all_players_equal;
//        communityCards = gamePlay.communityCards;
//        highest_bidder = gamePlay.highest_bidder;
//        amount_to_call = gamePlay.amount_to_call;
//        amount_raised = gamePlay.amount_raised;
//        amount_for_all_in = gamePlay.amount_for_all_in;
//        largest_bidder_amount = gamePlay.largest_bidder_amount;
//    }


}

#endif //POKERSIMULATIONSINCPP_GAMEPLAY_H
