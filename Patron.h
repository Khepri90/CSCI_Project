//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_PATRON_H
#define PROJECT_PATRON_H
#include <string>
#include <memory>
#include "LinkedList.h"

using namespace std;
class Patron{
private:
    string name, address, phoneNum;
    LinkedList<shared_ptr<Patron>> patrons;
public:
    //constructors and destructor
    Patron();
    Patron(string& name, string& address, string& phoneNum);
    virtual ~Patron();
    //accessor and mutator methods (review const and book type/inheritance call if just library)
    string getName() const;
    void setName(const string& aName);
    string getAddress() const;
    void setAddress(const string& anAddress);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& aPhoneNum);

};


#endif //PROJECT_PATRON_H
