//
// Created by dariu on 7/25/2021.
//


#include "Library.h"

#include "regex"
using namespace std;
template<class ItemType>
Library<ItemType>::Library() { //Default constructor

}

template<class ItemType>
Library<ItemType>::~Library() { //Default deconstructor
    vector<shared_ptr<Book>> vecBooks = books->toVector();
    /* getting error for no toVector in linked list with patrons
    vector<shared_ptr<Patron>> vecPatron = patrons->toVector();
     */

    for (const shared_ptr<Book>& aBook: vecBooks){
        books->remove(aBook);
    }
}



template<class ItemType>
bool Library<ItemType>::removeBook(string title) { //remove available books from inventory
    auto aBook;
    if(isAvailable(aBook)) {
        this->books.remove(aBook); //placeholder need to find pointer to book with title and remove it.
        this->bookIndex.remove(aBook)
        return true;
    }
}

template<class ItemType>
bool Library<ItemType>::addPatron(string name, string address, string phoneNum) {
    Patron newPatron = Patron(name, address, phoneNum);
    return(this->patrons.add(newPatron));
}

template<class ItemType>
bool Library<ItemType>::isAvailable(string title) {
    for(Book aBook: this->books.toVector())
        if(aBook.getTitle() == title)
            return true;

}

template<class ItemType>
bool Library<ItemType>::isCheckedOut(string title) {
    return false;
}

template<class ItemType>
bool Library<ItemType>::addBook(const string &aTitle, const string &aIsbn, const string &aDatePublished,

                               const string &aPublisher, const string &aNumOfPages) {
    Book newBook = Book(aTitle, aIsbn, aDatePublished, aPublisher, aNumOfPages);
    this->books.add(newBook)
    bookIndex->add(newBook);
}

template<class ItemType>
void Library<ItemType>::checkout(string phoneNum, string title) {
   /*
    bool canCheckout = isAvailable(title);
    if (canCheckout){


    }
    */
}

template<class ItemType>
void Library<ItemType>::placeHold(string title, string phoneNum) {

}

template<class ItemType>
bool Library<ItemType>::returnBook(string title) { //drop off books into drop box
    return false;
}


template<class ItemType>
void Library<ItemType>::listAvailBooks() { //display a list of all available books.
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Book Title" << " -- " <<
         setw(10) << "First Author" << " -- " <<
         setw(10) << "Available" << " -- " << endl;
    cout << string(57, '=') << endl;

    vector<shared_ptr<Book>> book = this->books.toVector();
    for(int i = 0; i < books->getCurrentSize(); i++){
        cout << left <<
             setw(10) << book[i]->getTitle() << " -- " <<
             setw(10) << "First Author" << " -- " <<
             setw(10) << book[i]->isChecked() << " -- " << endl;
        cout << string(57, '=') << endl;
    }

}


template<class ItemType>
void Library<ItemType>::listCheckedOut() {
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Book Title" << " -- " <<
         setw(10) << "First Author" << " -- " <<
         setw(10) << "Available" << " -- " << endl;
    cout << string(57, '=') << endl;

    vector<shared_ptr<Book>> book = this->checkedBook.toVector();
    for(int i = 0; i < books->getCurrentSize(); i++){
        cout << left <<
             setw(10) << book[i]->getTitle() << " -- " <<
             setw(10) << "First Author" << " -- " <<
             setw(10) << book[i]->isChecked() << " -- " << endl;
        cout << string(57, '=') << endl;
    }
}

template<class ItemType>
void Library<ItemType>::listPatrons() {
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

template<class ItemType>
void Library<ItemType>::loadFile() {

}

template<class ItemType>
void Library<ItemType>::saveFile() {

}

template<class ItemType>
vector<shared_ptr<Book>> Library<ItemType>::search(string title) {
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
