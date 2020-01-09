//
// Created by CiaranWelsh on 19/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_ERRORS_H
#define POKERSIMULATIONSINCPP_ERRORS_H


#include <stdexcept>
#include <sstream>
#include <utility>

namespace errors {

    class Exception : public std::logic_error {
        const char *msg;
        int line;
        std::string file;

        std::string build_exception() const {
            std::ostringstream stream;
            stream << file << ":" << line << ": " << msg << std::endl;
            return stream.str();
        }

    public:

        Exception(const char *msg, std::string file, int line) :
                msg(msg),
                line(line),
                file(std::move(file)),
                std::logic_error(build_exception()) {}

        Exception(std::string *msg, std::string file, int line) :
                msg(reinterpret_cast<const char *>(msg)),
                line(line),
                file(std::move(file)),
                std::logic_error(build_exception()) {}

        ~Exception() noexcept override = default;

        Exception(Exception const &other) noexcept(true):
                msg(other.msg),
                line(other.line),
                file(other.file),
                logic_error(build_exception()) {};

        Exception &operator=(Exception const &other) = default;

        const char *what() const noexcept {
            const char *out = build_exception().c_str();
            return out;
        }
    };


    class AnotherError : public Exception {
    public:
        using Exception::Exception;
    };

    class BadError : public Exception {
    public:
        using Exception::Exception;
    };

    class InvalidActionError : public Exception {
    public:
        using Exception::Exception;
    };

    class EmptyContainerError : public Exception {
    public:
        using Exception::Exception;
    };

    class EventNotChangedAfterStepError : public Exception {
    public:
        using Exception::Exception;
    };

    class NullPointerException : public Exception {
    public:
        using Exception::Exception;
    };

    class NegativePotValue : public Exception {
    public:
        using Exception::Exception;
    };

    class ValueError : public Exception {
    public:
        using Exception::Exception;
    };

    class NotImplementedError : public Exception {
    public:
        using Exception::Exception;
    };

    class NotImplementedException : public Exception {
    public:
        using Exception::Exception;
    };

};


#endif //POKERSIMULATIONSINCPP_ERRORS_H
