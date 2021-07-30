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
#include "ArrayStack.h"
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "BookComparator.h"
using namespace std;

class Library {
private:
    string name;
    string address;
    string officeHours;

    shared_ptr<LinkedBag<shared_ptr<Book>>> books;
    shared_ptr<LinkedBag<shared_ptr<Book>>> checkedBook;
    shared_ptr<LinkedList<shared_ptr<Patron>>> patrons;
    ArrayStack<shared_ptr<Book>> dropbox;
    shared_ptr<BinarySearchTree<shared_ptr<Book>>> bookIndex;

public:
     Library();
    ~Library();

    bool addPatron(string name, string address, string phoneNum);
    bool isAvailable(string title);
    bool isCheckedOut(string title);
    bool returnBook(string title);
    bool addBook(const string &aTitle, const string &aIsbn, const string &aDatePublished,
                 const string &aPublisher, const string &aNumOfPages);
    bool removeBook(string title);

    void checkout(string phoneNum, string title);
    void placeHold(string title, string phoneNum);
    void checkIn();
    void listAvailBooks();
    void listCheckedOut();
    void listPatrons();
    void loadFile();
    void saveFile();

    shared_ptr<Book>searchBookExact(string title);
    vector<shared_ptr<Book>> search(string title);

};



#endif //PROJECT_LIBRARY_H
