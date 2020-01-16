//
// Created by CiaranWelsh on 14/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_FOLDSTATION_H
#define POKERSIMULATIONSINCPP_FOLDSTATION_H


#include <string>
#include "Player.h"

class FoldStation: public Player {
private:
    std::string type = "FoldStation";
public:
    using Player::Player;

    ActionType choose_action(std::shared_ptr<std::vector<ActionType>> actions) override;



};


#endif //POKERSIMULATIONSINCPP_FOLDSTATION_H
