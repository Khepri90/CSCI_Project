//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_PRECONDVIOLATEDEXCEP_H
#define PROJECT_PRECONDVIOLATEDEXCEP_H


#include <stdexcept>
#include <string>



class PrecondViolatedExcep : public std::logic_error{
public:
    explicit PrecondViolatedExcep(const std::string& message="");
};

#include "PrecondViolatedExcep.cpp"

#endif //PROJECT_PRECONDVIOLATEDEXCEP_H
