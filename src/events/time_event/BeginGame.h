//
// Created by CiaranWelsh on 02/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_BEGINGAME_H
#define POKERSIMULATIONSINCPP_BEGINGAME_H

#include <string>
#include <iostream>
#include "TimeEvent.h"
#include "game/Table.h"

namespace events {
    class BeginGame : public TimeEvent {
    private:
        TargetType target = Table;
        std::string description = "This event marks the start of a game, i.e. before preflop.";
    public:
        using TimeEvent::Event;

        void go() override;

        void go(game::Table &table);

    };
}

#endif //POKERSIMULATIONSINCPP_BEGINGAME_H
