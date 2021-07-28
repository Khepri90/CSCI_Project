//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_AUTHOR_H
#define PROJECT_AUTHOR_H

#include <string>
using namespace std;

class Author {
private:
    string name;

public:
    Author();
    Author(string& aName);
    ~Author();

    string getName();
    void setName(string& aName);

};


#endif //PROJECT_AUTHOR_H
