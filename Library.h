//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Book.h"
#include "Author.h"
#include "LinkedBag.h"
#include "LinkedList.h"
#include "LinkedQueue.h"

using namespace std;

template<class ItemType>
class Library {
private:
    string name;
    string address;
    string officeHours;

    LinkedBag<shared_ptr<Book>> availBooks;
    shared_ptr<LinkedList<shared_ptr<Patron>>> patrons;

public:
    explicit Library();
    ~Library();

    bool addPatron(string name, string address, string phoneNum);
    bool isAvailable(string title);
    bool isCheckedOut(string title);
    bool returnBook();
    bool addBook(const string &aTitle, const string &aIsbn, const string &aDatePublished,
                 const string &aPublisher, const string &aNumOfPages);
    bool removeBook(string title);

    void checkout(string phoneNum, string title);
    void placeHold();
    void listAvailBooks();
    void listCheckedOut();
    void listPatrons();
    void loadFile();
    void saveFile();

    vector<shared_ptr<Book>> search(string title);

    friend ostream &operator<<(ostream &out, const Library& library);
};



#endif //PROJECT_LIBRARY_H
