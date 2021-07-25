//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_NOTFOUNDEXCEPTION_H
#define PROJECT_NOTFOUNDEXCEPTION_H


#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
    explicit NotFoundException(const std::string& message = "")
            : std::logic_error("Precondition Violated Exception: " + message){}
};


#endif //PROJECT_NOTFOUNDEXCEPTION_H
