//
// Created by CiaranWelsh on 20/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_RAISER_H
#define POKERSIMULATIONSINCPP_RAISER_H



#include <string>
#include "Player.h"

class Raiser : public Player {
private:
    std::string type = "Raiser";
public:
    using Player::Player;

    ActionType choose_action(std::shared_ptr<std::vector<ActionType>> actions) override;

    std::string getType() override;

};


#endif //POKERSIMULATIONSINCPP_RAISER_H
