//
// Created by dariu on 7/25/2021.
//

#include "Author.h"


Author::Author() {

}


Author::Author(string &aName) {

}


Author::~Author() {

}


string Author::getName() {
    return name;
}


void Author::setName(string& aName) {
    name = aName;
}