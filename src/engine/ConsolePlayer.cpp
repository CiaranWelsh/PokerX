//
// Created by Ciaran on 10/01/2021.
//
#include <iostream>
#include <string>
#include "ConsolePlayer.h"
#include "NoLimitHoldem.h"

namespace pokerx {

    Action ConsolePlayer::selectAction(PokerEngine *engine) {
        std::cout << "Enter action:" << std::endl;
        std::string input;
        std::string raise_amount_str;

        std::cin >> input;

        if (input == "call") {
            stack_ -= engine->getCurrentBet();
            engine->contribPot(engine->getCurrentBet());
            return CALL;
        } else if (input == "fold") {
            return FOLD;
        } else if (input == "raise") {
            bool done = false;
            while (!done) {
                std::cin >> raise_amount_str;
                float raise_amount = std::stof(raise_amount_str);
                if (raise_amount <= getStack()) {
                    engine->setCurrentBet(raise_amount);
                    stack_ -= engine->getCurrentBet();
                    engine->contribPot(engine->getCurrentBet());
                    done = true;
                } else {
                    std::cout << "Not big enough stack for that bet" << std::endl;
                }
            }
            return RAISE;
        } else if (input == "check") {
            return CHECK;
        } else if (input == "all in") {
            engine->setCurrentBet(getStack());
            return ALL_IN;
        } else {
            selectAction(engine);
        }
    }
}