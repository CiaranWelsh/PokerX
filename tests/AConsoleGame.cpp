#include <iostream>
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/PlayerManager.h"
#include "PokerX/engine/CallStationPlayer.h"
#include "PokerX/engine/GameVariables.h"
#include <regex>

using namespace pokerx;

int main() {

    PlayerManager playerManager = PlayerManager::populate<CallStationPlayer>(6, 100.0);
    GameVariables variables;
    PokerEngine engine(&playerManager, &variables);

    std::string userInput;
    while (true) {
        std::cout << "Enter one of: [Finish [Ff], check [a], fold [s], call [w], raise [d], all_in [c]]" << std::endl;
        std::cout << "> ";
        std::cin >> userInput;
        if (userInput == "Finish" | userInput == "F" | userInput == "f") {
            break;
        } else {
            if (userInput == "none") {
                engine.action();
            } else if (userInput.empty()) {
                engine.action();
            } else if (userInput == "check" | userInput == "a") {
                engine.action();
            } else if (userInput == "fold" | userInput == "s") {
                engine.action();
            } else if (userInput == "call" | userInput == "w") {
                engine.action();
            } else if (userInput == "raise" | userInput == "d") {
                engine.action();
            } else if (userInput == "all_in" | userInput == "c") {
                engine.action();
            } else {
                // now for regexes
//                std::smatch sm;
//                std::regex variables_regex("^variables\.(.*)\(\)");
//                if (std::regex_match(userInput, variables_regex)) {
//                    std::regex_match(userInput, sm, variables_regex);
//                    std::cout << "matched: " << sm[0] << std::endl;
//                    std::cout << variables << std::endl;
//                };
            }
        }
    }
}



