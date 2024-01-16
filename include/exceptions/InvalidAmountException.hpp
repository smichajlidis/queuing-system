#ifndef _INVALIDAMOUNTEXCEPTION_HPP_
#define _INVALIDAMOUNTEXCEPTION_HPP_
#include <stdexcept>
#include <string>

class InvalidAmountException: public std::exception {
private:
    int limit;
    mutable std::string errorString;
public:
    virtual const char* what() const noexcept {
        errorString = "Please give a number from 1 to " + std::to_string(limit);
        return errorString.c_str();
    }
    InvalidAmountException(int limit) : limit (limit) {};
    ~InvalidAmountException() {};
};

#endif