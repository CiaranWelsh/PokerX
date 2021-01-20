#include <iostream>
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/PlayerManager.h"
#include "PokerX/engine/CallStationPlayer.h"
#include "PokerX/engine/GameVariables.h"

using namespace pokerx;

int main() {

    PlayerManager playerManager = PlayerManager::populate<CallStationPlayer>(6, 100.0);
    GameVariables variables;
    PokerEngine engine(playerManager, variables);


    std::string x;
    while (true) {
        std::cout << "Enter one of: [none, check, fold, call, raise, all_in]" << std::endl;
        std::cin >> x;
        if (x == "N") {
            break;
        } else {
            if (x == "none") {
                engine.action(NONE);
            } else if (x.empty()) {
                engine.action(CALL);
            } else if (x == "check") {
                engine.action(CHECK);
            } else if (x == "fold") {
                engine.action(FOLD);
            } else if (x == "call") {
                engine.action(CALL);
            } else if (x == "raise") {
                engine.action(RAISE);
            } else if (x == "all_in") {
                engine.action(ALL_IN);
            }
        }
    }
}



