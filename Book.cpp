//
// Created by dariu on 7/25/2021.
//

#include "Book.h"

Book::Book() {

}


Book::Book(const string &aTitle, const string &aIsbn, const string &aDatePublished,
           const string &aPublisher, const string &aNumOfPages) {

}


Book::~Book() {

}


string Book::getTitle() {
    return title;
}


string Book::getIsbn() {
    return isbn;
}


string Book::getDatePub() {
    return datePublished;
}


string Book::getPublisher() {
    return publisher;
}


string Book::getNumOfPages() {
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
        this->currentPatron = aPatron;
    } else {
        throw logic_error("Invalid, Book is not available.");
    }
}

bool Book::isChecked() {

}

