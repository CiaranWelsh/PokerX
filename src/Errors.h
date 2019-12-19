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


};


#endif //POKERSIMULATIONSINCPP_ERRORS_H
