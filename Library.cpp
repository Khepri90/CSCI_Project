//
// Created by dariu on 7/25/2021.
//


#include "Library.h"

#include "regex"
using namespace std;

Library::Library() { //Default constructor
shared_ptr<Comparator<shared_ptr<Book>>> aBookComparator = make_shared<BookComparator>();
bookIndex = make_shared<BinarySearchTree<shared_ptr<Book>>>(aBookComparator);
}


Library::~Library() { //Default deconstructor
    vector<shared_ptr<Book>> vecBooks = books->toVector();
    /* getting error for no toVector in linked list with patrons
    vector<shared_ptr<Patron>> vecPatron = patrons->toVector();
     */

    for (const shared_ptr<Book>& aBook: vecBooks){
        books->remove(aBook);
    }
}




bool Library::removeBook(string title) { //remove available books from inventory
    auto aBook = searchBookExact(title);
    if(isAvailable(aBook->getTitle())){
        this->books->remove(aBook); //placeholder need to find pointer to book with title and remove it.
        this->bookIndex->remove(aBook);
        return true;
    }
}


bool Library::addPatron(string name, string address, string phoneNum) {
    auto newPatron = make_shared<Patron>(name, address, phoneNum);
    return(this->patrons->insert(patrons->getLength() + 1, newPatron));
}


bool Library::isAvailable(string title) {
    auto aBook = searchBookExact(title);
        if(aBook->getTitle() == title)
            return true;

}


bool Library::isCheckedOut(string title) {
    auto aBook = searchBookExact(title);
        if(aBook->getTitle() == title)
            return true;
}


bool Library::addBook(const string &aTitle, const string &aIsbn, const string &aDatePublished,

                               const string &aPublisher, const string &aNumOfPages) {

    auto newBook = make_shared<Book>(aTitle, aIsbn, aDatePublished, aPublisher, aNumOfPages);
    this->books->add(newBook);
    bookIndex->add(newBook);
    return true;
}


void Library::checkout(string phoneNum, string title) {
    bool canCheckout = isAvailable(title);
    auto aBook = searchBookExact(title);


    if (canCheckout){
        for (int i = 0; i < patrons->getLength(); i++){
            if (patrons->getEntry(i)->getPhoneNumber()==phoneNum)
                aBook->setPatron(patrons->getEntry(i));
        }
        checkedBook->add(aBook);
        books->remove(aBook);
    }

}


void Library::placeHold(string title, string phoneNum) {
  /*  auto aBook = searchBookExact(title);
    shared_ptr<Patron> aPatron = nullptr;
    for (int i = 0; i < patrons->getLength(); i++){
        if (patrons->getEntry(i)->getPhoneNumber()==phoneNum)
             aPatron = patrons->getEntry(i);
    }
    aBook->getHold()->enqueue(aPatron);
    */
}


bool Library::returnBook(string title) { //drop off books into drop box
    auto aBook = searchBookExact(title);
    dropbox.push(aBook);
}



void Library::listAvailBooks() { //display a list of all available books.
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Book Title" << " -- " <<
         setw(10) << "First Author" << " -- " <<
         setw(10) << "Available" << " -- " << endl;
    cout << string(57, '=') << endl;

    vector<shared_ptr<Book>> book = this->books->toVector();
    for(int i = 0; i < books->getCurrentSize(); i++){
        cout << left <<
             setw(10) << book[i]->getTitle() << " -- " <<
             setw(10) << "First Author" << " -- " <<
             setw(10) << book[i]->isChecked() << " -- " << endl;
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

    vector<shared_ptr<Book>> book = this->checkedBook->toVector();
    for(int i = 0; i < books->getCurrentSize(); i++){
        cout << left <<
             setw(10) << book[i]->getTitle() << " -- " <<
             setw(10) << "First Author" << " -- " <<
             setw(10) << book[i]->isChecked() << " -- " << endl;
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

        vector<shared_ptr<Book>> bookVector = this->books->toVector();
        for (int i=0; i < this->books->getCurrentSize(); i++){
            string bookTitle = bookVector[i]->getTitle();
            transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::toupper);

            if (regex_match(bookTitle, txt_regex)){
                foundBooks.push_back(bookVector[i]);
            }
        }
        return foundBooks;
    //return vector<shared_ptr<Book>>();
}


shared_ptr<Book> Library::searchBookExact(string title) {
    for (const shared_ptr<Book>& aBook:this->books->toVector())
        if (aBook->getTitle() == title)
            return aBook;
    return nullptr;
}


void Library::checkIn() {
   /* while(!dropbox.isEmpty()){
       if(!dropbox.peek()->getHold()->isEmpty()) {
           dropbox.peek()->setPatron(dropbox.peek()->getHold()->peekFront());
           dropbox.peek()->getHold()->dequeue();
           checkedBook->add(dropbox.peek());
       } else {
           books->add(dropbox.peek());
       }
        dropbox.pop();
    }*/
}
