//
// Created by CiaranWelsh on 19/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_ERROR_H
#define POKERSIMULATIONSINCPP_ERROR_H


#include <stdexcept>
#include <sstream>
#include <utility>
#include <iostream>


#define THROW_HELPER(ex_type)                                       \
    for (std::stringstream ss; true; throwError<ex_type>(__FILE__, __func__, __LINE__, ss.str())) \
        ss

    using FileNotFoundError = std::logic_error;
    using NotImplementedError = std::logic_error;


    /**
     * @brief Makes the full error message string
     * @param file: the file
     * @param function: the function
     * @param line: the line of the file
     * @param msg: the message to throw (default "")
     */
    template<typename ErrorType>
    void throwError(const std::string &file,
                    const std::string &function,
                    unsigned int line,
                    const std::string &msg = "") {
        std::ostringstream errMsg;
        errMsg << file << ":" << line << ":" << function << ":"
               << "\nError: " << msg << std::endl;
        std::cerr << errMsg.str();
        throw ErrorType(errMsg.str());
    }


#define INVALID_ARGUMENT_ERROR          THROW_HELPER(std::invalid_argument)
#define LOGIC_ERROR                     THROW_HELPER(std::logic_error)
#define RUNTIME_ERROR                   THROW_HELPER(std::runtime_error)
#define NOT_IMPLEMENTED_ERROR           THROW_HELPER(NotImplementedError)
#define FILE_NOT_FOUND_ERROR            THROW_HELPER(FileNotFoundError)


/**
 * The below is deprecated and will be replaced with the above style errors
 */
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


#endif //POKERSIMULATIONSINCPP_ERROR_H
