//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_ENTITY_H
#define POKERSIMULATIONSINCPP_ENTITY_H

class IEntity {
public:

    IEntity();

    State* getCurrentState() const;
    void toggle();
    void setState(State& state);

private:
    State* state_;

};

#endif //POKERSIMULATIONSINCPP_ENTITY_H
