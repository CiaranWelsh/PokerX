//
// Created by CiaranWelsh on 06/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_ENDGAME_H
#define POKERSIMULATIONSINCPP_ENDGAME_H

#include "iostream"
#include "TimeEvent.h"

namespace events {
    class EndGame : public TimeEvent {
    private:
        std::string id = "BeginGame";
        TargetType target = GamePlay;
        std::string description = "This event marks the start of a game, i.e. before preflop.";
        bool done = false;
    public:
        using TimeEvent::Event;

        TargetType getTarget() override;

        std::string getDescription() override;

        bool getDone() override;

        std::string getId() override;

        void go(game::GamePlay &gamePlay) override;

    };
}

#endif //POKERSIMULATIONSINCPP_ENDGAME_H
