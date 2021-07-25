//
// Created by dariu on 7/25/2021.
//

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const std::string &message)
        : logic_error("Precondition Violated Exception: " + message) {}

