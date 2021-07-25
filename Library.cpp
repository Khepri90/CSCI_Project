//
// Created by dariu on 7/25/2021.
//


#include "Library.h"
using namespace std;
template<class ItemType>
Library<ItemType>::Library() { //Default constructor

}

template<class ItemType>
Library<ItemType>::~Library() { //Default deconstructor

}

template<class ItemType>
bool Library<ItemType>::returnBook() { //drop off books into drop box
    return false;
}

template<class ItemType>
bool Library<ItemType>::removeBook(string title) { //remove available books from inventory
    return this->books.remove(title); //placeholder need to find pointer to book with title and remove it.
}

template<class ItemType>
void Library<ItemType>::listAvailBooks() { //display a list of all available books.
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Book Title" << " -- " <<
         setw(10) << "First Author" << " -- " <<
         setw(10) << "Available" << " -- " << endl;
    cout << string(57, '=') << endl;

    vector<shared_ptr<Book>> book = this->availBooks.toVector();
    for(int i = 0; i < availBooks.getCurrentSize(); i++){
        cout << left <<
             setw(10) << availBooks[i]->getTitle() << " -- " <<
             setw(10) << "First Author" << " -- " <<
             setw(10) << availBooks[i]->isChecked() << " -- " << endl;
        cout << string(57, '=') << endl;
    }

}

template<class ItemType>
bool Library<ItemType>::addPatron(string name, string address, string phoneNum) {
    return false;
}

template<class ItemType>
bool Library<ItemType>::isAvailable(string title) {
    return false;
}

template<class ItemType>
bool Library<ItemType>::isCheckedOut(string title) {
    return false;
}

template<class ItemType>
bool Library<ItemType>::addBook(const string &aTitle, const string &aIsbn, const string &aDatePublished,
                                const string &aPublisher, const string &aNumOfPages) {
    return false;
}

template<class ItemType>
void Library<ItemType>::checkout(string phoneNum, string title) {
    bool canCheckout = isAvailable(title);
    if (canCheckout){


    }
}

template<class ItemType>
void Library<ItemType>::placeHold() {

}

template<class ItemType>
void Library<ItemType>::listCheckedOut() {

}

template<class ItemType>
void Library<ItemType>::listPatrons() {

}

template<class ItemType>
void Library<ItemType>::loadFile() {

}

template<class ItemType>
void Library<ItemType>::saveFile() {

}

template<class ItemType>
vector<shared_ptr<Book>> Library<ItemType>::search(string title) {
    return vector<shared_ptr<Book>>();
}
