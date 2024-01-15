#ifndef _INVALIDNUMBEROFSTATIONSEXCEPTION_HPP_
#define _INVALIDNUMBEROFSTATIONSEXCEPTION_HPP_
#include <stdexcept>

class InvalidNumberOfStationsException: public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Please give a number from 1 to 9";
    }
    InvalidNumberOfStationsException() {};
    ~InvalidNumberOfStationsException() {};
};

#endif