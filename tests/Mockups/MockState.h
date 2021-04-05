//
// Created by Ciaran on 16/01/2021.
//

#ifndef POKERX_MOCKSTATE_H
#define POKERX_MOCKSTATE_H


/**
 * Might have need to be template but possibly not
 * so I'll avoid for now.
 */
class MockState : public State {
public:

    MockState() = default;

    MOCK_METHOD(void, enter,(StateMachine *),

    ());

    MOCK_METHOD(void, action,(StateMachine *),

    ());

    MOCK_METHOD(void, exit,(StateMachine *),

    ());

    MOCK_METHOD(unsigned int, getType,(),

    (const));

};


#endif //POKERX_MOCKSTATE_H
