//
// Created by dariu on 7/25/2021.
//


#include "Library.h"

#include "regex"
using namespace std;

Library::Library() { //Default constructor
shared_ptr<Comparator<shared_ptr<Book>>> aBookComparator = make_shared<BookComparator>();
//bookIndex = make_shared<AVLTree<shared_ptr<Book>>>(aBookComparator);
bookIndex = make_shared<BinarySearchTree<shared_ptr<Book>>>(aBookComparator);
}


Library::~Library() { //Default destructor

    books.clear();
    patrons.clear();

}




bool Library::removeBook(string title) { //remove available books from inventory
    auto aBook = searchBookExact(title);
    if(isAvailable(title)) {

        for (int i = 1; i < books.getLength(); i++) {
            if (books.getEntry(i)->getTitle() == title) {
                this->books.remove(i);
                //this->bookIndex->remove(aBook);
                return true;
            }
        }
    }
        return false;
}


bool Library::addPatron(string name, string address, string phoneNum) {
    auto newPatron = make_shared<Patron>(name, address, phoneNum);
    return(this->patrons.insert(patrons.getLength() + 1, newPatron));
}


bool Library::isAvailable(string title) {
    auto aBook = searchBookExact(title);
        if(aBook->getTitle() == title)
            return true;
        else
            return false;
}


bool Library::isCheckedOut(string title) {
    auto aBook = searchCheckBookExact(title);
        if(aBook->getTitle() == title)
            return true;
        else
            return false;
}


bool Library::addBook(const string &aTitle, const string &aIsbn, const string &aDatePublished,

                               const string &aPublisher, const string &aNumOfPages) {
    bool added;
    auto newBook = make_shared<Book>(aTitle, aIsbn, aDatePublished, aPublisher, aNumOfPages);
    added = (this->books.insert(books.getLength()+1, newBook));
    //bookIndex->add(newBook);

    return added;
}


void Library::checkout(string phoneNum, string title) {
    bool canCheckout = isAvailable(title);
    auto aBook = searchBookExact(title);


    if (canCheckout){
        for (int i = 0; i < patrons->getLength(); i++){
            if (patrons->getEntry(i)->getPhoneNumber()==phoneNum)
                aBook->setPatron(patrons->getEntry(i));
        }
        checkedBook.insert(books.getLength()+1, aBook);
        removeBook(title);
    }

}


void Library::placeHold(string title, string phoneNum) {
    auto aBook = searchBookExact(title);
    shared_ptr<Patron> aPatron = nullptr;
    for (int i = 0; i < patrons->getLength(); i++){
        if (patrons->getEntry(i)->getPhoneNumber()==phoneNum)
             aPatron = patrons->getEntry(i);
    }
    aBook->getHold().enqueue(aPatron);

}


bool Library::returnBook(string title) { //drop off books into drop box
    auto aBook = searchBookExact(title);
    dropbox.push(aBook);
    return true;
}



void Library::listAvailBooks() { //display a list of all available books.
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Book Title" << " -- " <<
         setw(10) << "First Author" << " -- " <<
         setw(10) << "Available" << " -- " << endl;
    cout << string(57, '=') << endl;


    for(int i = 1; i <= this->books.getLength(); i++){
        cout << left <<
             setw(10) << this->books.getEntry(i)->getTitle()<< " -- "<<
             setw(10) << "First Author"<< " -- "<<
             setw(10) << this->books.getEntry(i)->isChecked() << " -- " << endl;
        cout << string(57, '=') << endl;
    }

}



void Library::listCheckedOut() {
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Book Title" << " -- " <<
         setw(10) << "First Author" << " -- " <<
         setw(10) << "Available" << " -- " << endl;
    cout << string(57, '=') << endl;


    for(int i = 1; i <= this->checkedBook.getLength(); i++){
        cout << left <<
             setw(10) << this->checkedBook.getEntry(i)->getTitle() <<
             setw(10) << "First Author" << " -- "<<
             setw(10) << this->checkedBook.getEntry(i)->isChecked() << " -- " << endl;
        cout << string(57, '=') << endl;
    }
}


void Library::listPatrons() {
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Name" << " -- " <<
         setw(10) << "Address" << " -- " <<
         setw(10) << "Phone Number" << " -- " << endl;
    cout << string(57, '=') << endl;
    int length = patrons->getLength();
    for(int i = 0; i < length; i++){
        cout << string(57, '=') << endl;
        cout <<
             setw(10) << patrons->getEntry(i)->getName() << " -- " <<
             setw(10) << patrons->getEntry(i)->getAddress()<< " -- " <<
             setw(10) << patrons->getEntry(i)->getPhoneNumber() << " -- " << endl;
        cout << string(57, '=') << endl;


    }

}


void Library::loadFile() {

}


void Library::saveFile() {

}


vector<shared_ptr<Book>> Library::search(string title) {
    vector<shared_ptr<Book>> foundBooks;

    string searchTitle = ".*"+title+".*";

    transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::toupper);
        const regex txt_regex(searchTitle);

        for (int i=1; i < this->books.getLength(); i++){
            string bookTitle = books.getEntry(i)->getTitle();
            transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::toupper);

            if (regex_match(bookTitle, txt_regex)){
                foundBooks.push_back(books.getEntry(i));
            }
        }
        return foundBooks;

}


shared_ptr<Book> Library::searchBookExact(string title) {
    shared_ptr<Book> aBook;
    for (int i = 1; i <= books.getLength(); i++) {
        if (books.getEntry(i)->getTitle() == title){
            aBook = books.getEntry(i);
            return aBook;
        }
    }
    return nullptr;

}

shared_ptr<Book> Library::searchCheckBookExact(string title) {
    shared_ptr<Book> aBook;
    for (int i = 1; i <= checkedBook.getLength(); i++) {
        if (checkedBook.getEntry(i)->getTitle() == title){
            aBook = checkedBook.getEntry(i);
            return aBook;
        }
    }
    return nullptr;

}

void Library::checkIn() {
    while(!dropbox.isEmpty()){
       if(!dropbox.peek()->getHold().isEmpty()) {
           dropbox.peek()->setPatron(dropbox.peek()->getHold().peekFront());
           dropbox.peek()->getHold().dequeue();
           checkedBook.insert(checkedBook.getLength()+1, dropbox.peek());
       } else {
           books.insert(books.getLength()+1, dropbox.peek());
       }
        dropbox.pop();
    }
}

bool Library::addAuthor(const string &name) {
shared_ptr<Author> anAuthor = make_shared<Author>(name);
    this->authors.add(anAuthor);
    return true;
}

bool Library::addAuthorToBook(const string &title, const string &authorName) {
    shared_ptr<Book> aBook;
    shared_ptr<Author> anAuthor;
    aBook = searchBookExact(title);
    anAuthor = searchAuthor(authorName);
    if (aBook != nullptr && anAuthor != nullptr)
        return aBook->addAuthor(anAuthor);
    else
        return false;
}

shared_ptr<Author> Library::searchAuthor(const string &authorName) {
    for (const shared_ptr<Author>& anAuthor: this->authors.toVector()) {
        if (anAuthor->getName() == authorName)
            return anAuthor;
    }
    return nullptr;
}
