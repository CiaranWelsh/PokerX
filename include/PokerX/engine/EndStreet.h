//
// Created by Ciaran on 18/01/2021.
//

#ifndef POKERX_ENDSTREET_H
#define POKERX_ENDSTREET_H


namespace pokerx {

    class EndStreet : public State {
    public:

        ~EndStreet() override = default;

        void enter(StateMachine *machine) override;

        void action(StateMachine *machine) override;

        void exit(StateMachine *machine) override;

        [[nodiscard]] unsigned int getType() const override;

        static EndStreet& getInstance();

    private:
        EndStreet() = default;

    };

}



#endif //POKERX_ENDSTREET_H
