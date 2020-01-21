//
// Created by CiaranWelsh on 20/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_PREFLOPRAISER_H
#define POKERSIMULATIONSINCPP_PREFLOPRAISER_H

#include "Player.h"

class PreflopRaiser : public Player {
private:
    std::string type = "PreflopRaiser";
public:
    using Player::Player;

    ActionType choose_action(std::shared_ptr<std::vector<ActionType>> actions) override;

    std::string getType() override;

};


#endif //POKERSIMULATIONSINCPP_PREFLOPRAISER_H
