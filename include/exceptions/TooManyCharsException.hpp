#ifndef _NOTLETTEREXCEPTION_HPP_
#define _NOTLETTEREXCEPTION_HPP_
#include <exception>

class NotLetterException: public std::exception {
public:
    virtual const char* what() const noexcept {
        return "You have to give a letter.";
    }
    NotLetterException() {};
    ~NotLetterException() {};
};

#endif