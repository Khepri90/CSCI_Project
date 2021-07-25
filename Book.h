//
// Created by dariu on 7/25/2021.
//

#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H

#include <string>
#include <memory>
#include "LinkedBag.h"
#include "Author.h"
#include "LinkedQueue.h"
#include "Patron.h"

using namespace std;


class Book {
private:
    string title;
    string isbn;
    string datePublished;
    string publisher;
    string numOfPages;

    shared_ptr<Patron> currentPatron;


public:
    explicit Book();
    explicit Book(const string &aTitle, const string &aIsbn, const string &aDatePublished,
                  const string &aPublisher, const string &aNumOfPages);
    ~Book();

    string getTitle();
    string getIsbn();
    string getDatePub();
    string getPublisher();
    string getNumOfPages();

    void setTitle(string title);
    void setIsbn(string isbn);
    void setDatePub(string datePublished);
    void setPublisher(string publisher);
    void setNumOfPages(string numOfPages);

    void setPatron(shared_ptr<Patron> aPatron);
    bool isChecked();

};



#include "Book.cpp"

#endif //PROJECT_BOOK_H
