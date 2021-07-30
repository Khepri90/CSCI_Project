//
// Created by dariu on 7/25/2021.
//

#include "Book.h"
#include "iomanip"
Book::Book() {

}


Book::Book(const string &aTitle, const string &aIsbn, const string &aDatePublished,
           const string &aPublisher, const string &aNumOfPages) : currentPatron(nullptr) {

}


Book::~Book() {

}


string Book::getTitle() const{
    return title;
}


string Book::getIsbn() const{
    return isbn;
}


string Book::getDatePub() const{
    return datePublished;
}


string Book::getPublisher() const{
    return publisher;
}


string Book::getNumOfPages() const{
    return numOfPages;
}


void Book::setTitle(string title) {
    this->title = title;
}


void Book::setIsbn(string isbn) {
    this->isbn = isbn;
}


void Book::setDatePub(string datePublished) {
    this->datePublished = datePublished;
}


void Book::setPublisher(string publisher) {
    this->publisher = publisher;
}


void Book::setNumOfPages(string numOfPages) {
    this->numOfPages = numOfPages;
}

void Book::setPatron(shared_ptr<Patron> aPatron) {
    if(!this->isChecked()){
        currentPatron = aPatron;
    } else {
        throw logic_error("Invalid, Book is not available.");
    }
}

bool Book::isChecked() {
    /*search title
    if not available, then checked out*/
    bool checked = false;
    if(currentPatron != nullptr){
        checked = true;
    }

    return checked;

}
ostream &operator<<(ostream &out, const Book& aBook){

    out <<
         setw(10) << aBook.getTitle() << " -- " <<
         setw(10) << aBook.getAuthor() << " -- " <<endl;
}

string Book::getAuthor() const {
    vector<shared_ptr<Author>> author = authors->toVector();
    return author[0]->getName();
}

shared_ptr<LinkedQueue<shared_ptr<Patron>>> Book::getHold() const {
    return waitingPatrons;
}

