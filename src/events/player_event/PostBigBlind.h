//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_POSTBIGBLIND_H
#define POKERSIMULATIONSINCPP_POSTBIGBLIND_H

#include "PlayerEvent.h"

namespace events {
    class PostBigBlind : public PlayerEvent {
    private:
        TargetType target = Players;
        std::string id = "PostBigBlind";
        bool done = false;
        std::string description = "Post the big blind";
    public:
        using PlayerEvent::Event;

        TargetType getTarget() override;

        std::string getDescription() override;

        bool getDone() override;

        std::string getId() override;

        void go(game::GamePlay &gamePlay, game::PlayerPtr &player) override;


    };
}


#endif //POKERSIMULATIONSINCPP_POSTBIGBLIND_H
