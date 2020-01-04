//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_POSTSMALLBLIND_H
#define POKERSIMULATIONSINCPP_POSTSMALLBLIND_H

#include "PlayerEvent.h"
#include "game/Table.h"

namespace events {
    class PostSmallBlind : PlayerEvent {
    private:
        std::string description = "Post the small blind";
    public:
        using PlayerEvent::Event;

        void go(game::Table &table, game::PlayerPtr player);

    };
}


#endif //POKERSIMULATIONSINCPP_POSTSMALLBLIND_H
