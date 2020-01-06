//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_NEXTPLAYER_H
#define POKERSIMULATIONSINCPP_NEXTPLAYER_H

#include "PlayerEvent.h"
#include "game/Players.h"

namespace events {
    class NextPlayer : public PlayerEvent {
    private:
        std::string id = "NextPlayer";
        TargetType target = Players;
        bool done = false;
        std::string description = "Move to the next player that is in the game ";
    public:
        using PlayerEvent::Event;

        void go(game::Players &players);

        TargetType getTarget() override;

        std::string getDescription() override;

        bool getDone() override;

        std::string getId() override;


    };
}

#endif //POKERSIMULATIONSINCPP_NEXTPLAYER_H
