//
// Created by CiaranWelsh on 18/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_COMMUNITYCARDS_H
#define POKERSIMULATIONSINCPP_COMMUNITYCARDS_H

#include "CardCollection.h"
#include "Card.h"

namespace Game {
    class CommunityCards : public Game::CardCollection {
    public:
        CommunityCards();

        ~CommunityCards();

        CommunityCards(Game::Card &flop1, Game::Card &flop2, Game::Card &flop3);

        CommunityCards(Game::Card &flop1, Game::Card &flop2, Game::Card &flop3, Game::Card &turn);

        CommunityCards(Game::Card &flop1, Game::Card &flop2, Game::Card &flop3, Game::Card &turn, Game::Card &river);

    };
}

#endif //POKERSIMULATIONSINCPP_COMMUNITYCARDS_H
