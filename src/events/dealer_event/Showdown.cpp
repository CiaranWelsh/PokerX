//
// Created by CiaranWelsh on 12/01/2020.
//

#include <eval/Evaluator.h>
#include <dshow.h>
#include "Showdown.h"

void
events::Showdown::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer, double &amount_to_call) {

    cout << "Determining the winner" << endl;
    // collect hands
    std::vector<eval::HandPtr> hands;
    for (auto player : players) {
//        cout << "comm: " << gamePlay.communityCards << endl;
//        cout << "hole: " << player->holeCards << endl;
        eval::Hand hand(player->holeCards, gamePlay.communityCards);
        cout << "PLayer "<< player->getName() << "Hand " << hand << endl;
        eval::HandPtr handPtr(std::make_shared<eval::Hand>(hand));
//        cout << "Handptr " << *handPtr << endl;
        hands.push_back(handPtr);
    }
    eval::Evaluator evaluator;
    std::map<int, eval::HandType> winner = evaluator.evaluate(hands);
    std::vector<int> winning_player;
    std::vector<eval::Hand> winning_hand;
//    for (auto i : winner)
    if (winner.size() == 1) {
        for (auto i: winner) {
            gamePlay.winning_player = i.first;
            gamePlay.winning_hand = i.second;
        }
        cout << "winning player: " << gamePlay.winning_player << endl;
        cout << "winning hand: " << gamePlay.winning_hand<< endl;
    }
    else{
        cout << "Not implemented " << endl;
//        throw errors::NotImplementedError("Error", __FILE__, __LINE__);
    }
}
