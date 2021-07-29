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
    shared_ptr<LinkedBag<shared_ptr<Author>>> authors;
    shared_ptr<LinkedQueue<shared_ptr<Patron>>> waitingPatrons;
    shared_ptr<Patron> currentPatron;


public:
    explicit Book();
    explicit Book(const string &aTitle, const string &aIsbn, const string &aDatePublished,
                  const string &aPublisher, const string &aNumOfPages);
    ~Book();

    string getTitle() const;
    string getIsbn() const;
    string getDatePub() const;
    string getPublisher() const;
    string getNumOfPages() const;
    string getAuthor()const;
    shared_ptr<LinkedQueue<shared_ptr<Patron>>> getHold() const;
    void setTitle(string title);
    void setIsbn(string isbn);
    void setDatePub(string datePublished);
    void setPublisher(string publisher);
    void setNumOfPages(string numOfPages);

    void setPatron(shared_ptr<Patron> aPatron);
    bool isChecked();

    friend ostream &operator<<(ostream &out, const Book& aBook);

};



#include "Book.cpp"

#endif //PROJECT_BOOK_H
