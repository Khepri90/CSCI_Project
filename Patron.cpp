//
// Created by dariu on 7/25/2021.
//

#include "Patron.h"
Patron::Patron(){}

Patron:: Patron(string& name, string& address, string& phoneNum):
        name(name), address(address), phoneNum(phoneNum)
{}

Patron:: ~Patron(){
    clear();
}


string Patron::getName() const {
    return name;
}
void Patron::setName(const string& aName){
    name = aName;
}
string Patron::getAddress() const {
    return address;
}
void Patron::setAddress(const string& anAddress){
    address = anAddress;
}
string Patron::getPhoneNumber() const {
    return phoneNum;
}
void Patron::setPhoneNumber(const string& aPhoneNumb){
    phoneNum = aPhoneNumb;
}