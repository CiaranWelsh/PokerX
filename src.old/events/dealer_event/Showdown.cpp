//
// Created by CiaranWelsh on 12/01/2020.
//

#include <eval/Evaluator.h>
#include <dshow.h>
#include "Showdown.h"

void
events::Showdown::go(game::GamePlay &gamePlay, game::Players &players, game::Dealer &dealer, double &amount_to_call) {

//    cout << "Determining the winner" << endl;
    // collect hands
    std::vector<eval::HandPtr> hands;
//    cout << "community cards: " << gamePlay.communityCards << endl;
    for (auto player : players) {
//        cout << "comm: " << gamePlay.communityCards << endl;
//        cout << "hole: " << player->holeCards << endl;
        eval::Hand hand(player->holeCards, gamePlay.communityCards);
//        cout << "Player "<< player->getName() << player->holeCards << endl;
        eval::HandPtr handPtr(std::make_shared<eval::Hand>(hand));
//        cout << "Handptr " << *handPtr << endl;
        hands.push_back(handPtr);
    }
    eval::Evaluator evaluator;
    std::map<int, eval::HandType> winner = evaluator.evaluate(hands);
    std::vector<int> winning_player;
    std::vector<eval::Hand> winning_hand;
        for (auto i: winner) {
            gamePlay.winning_players.push_back(i.first);
            gamePlay.winning_hand = i.second;
        }
    if (winner.size() == 1) {
//        cout << "winning player: " << gamePlay.winning_players[0] << endl;
//        cout << "winning hand: " << gamePlay.winning_hand<< endl;
        players[gamePlay.winning_players[0]]->pot += gamePlay.pot.value;
//        cout << "made it to after the pot " << endl;
    }
    else{
//        cout <<"split pot between: ";
        double amount_each = gamePlay.pot.value / winning_player.size();
        for (auto i: gamePlay.winning_players){
//            cout << i << " and ";
            players[i]->pot += amount_each;
        }
//        cout << endl;
    }

}
