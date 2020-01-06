//
// Created by CiaranWelsh on 19/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_ERRORS_H
#define POKERSIMULATIONSINCPP_ERRORS_H


#include <stdexcept>

namespace errors {

    class NotImplementedException : public std::logic_error {
    public:
        NotImplementedException() : std::logic_error("Function not yet implemented") {};
    };

    class BadError : public std::logic_error {
    public:
        BadError() : std::logic_error("You did a bad") {};
    };

    class NullPointerException : public std::logic_error {
    public:
        NullPointerException() : std::logic_error("You have a nullptr where there shouldn't be one") {};
    };

    class EventNotChangedAfterStepError : public std::logic_error {
    public:
        EventNotChangedAfterStepError() : std::logic_error("The current Event subtype has not changed") {};
    };


};


#endif //POKERSIMULATIONSINCPP_ERRORS_H
