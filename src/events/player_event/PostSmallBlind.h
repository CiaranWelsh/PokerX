//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_POSTSMALLBLIND_H
#define POKERSIMULATIONSINCPP_POSTSMALLBLIND_H

#include "PlayerEvent.h"

namespace events {
    class PostSmallBlind : public PlayerEvent {
    private:
        TargetType target = None;
        std::string id = "PostSmallBlind";
        bool done = false;
        std::string description = "Post the small blind";
    public:
        using PlayerEvent::Event;

        TargetType getTarget() override;

        std::string getDescription() override;

        bool getDone() override;

        std::string getId() override;

        void go(game::GamePlay &gamePlay, game::PlayerPtr &player) override;


//        virtual void go(game::GamePlay &gamePlay);
    };
}


#endif //POKERSIMULATIONSINCPP_POSTSMALLBLIND_H
