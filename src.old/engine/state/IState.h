//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_STATE_H
#define POKERSIMULATIONSINCPP_STATE_H

#include "IEntity.h"

class IEntity;

class IState{
public:
    virtual void enter(Entity* entity)  = 0;
    virtual void action(IEntity *entity) = 0;
    virtual void exit(Entity* entity)   = 0;
    virtual ~State() = default;
};


#endif //POKERSIMULATIONSINCPP_STATE_H
