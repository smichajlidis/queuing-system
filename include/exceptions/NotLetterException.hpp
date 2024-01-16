#ifndef _TOOMANYCHARSEXCEPTION_HPP_
#define _TOOMANYCHARSEXCEPTION_HPP_
#include <exception>

class TooManyCharsException: public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Given to many chars.";
    }
    TooManyCharsException() {};
    ~TooManyCharsException() {};
};

#endif