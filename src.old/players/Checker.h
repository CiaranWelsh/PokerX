//
// Created by CiaranWelsh on 20/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_CHECKER_H
#define POKERSIMULATIONSINCPP_CHECKER_H



#include <string>
#include "Player.h"

class Checker : public Player {
private:
    std::string type = "Checker";
public:
    using Player::Player;

    ActionType choose_action(std::shared_ptr<std::vector<ActionType>> actions) override;

    std::string getType() override;

};



#endif //POKERSIMULATIONSINCPP_CHECKER_H
