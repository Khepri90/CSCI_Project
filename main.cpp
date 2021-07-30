#include <iostream>
#include <memory>
#include "Book.h"
#include "Library.h"




using namespace std;
int displayMenu(){
    cout << "=============================================================" << endl;
    cout << "                   CSE LIBRARY MAIN MENU                " << endl;
    cout << "=============================================================" << endl;
    cout << "1) Book: Add " << endl;
    cout << "2) Book: List Available " << endl;
    cout << "3) Book: List Check Out " << endl;
    cout << "4) Book: Remove by title " << endl;
    cout << "5) Book: Search " << endl;
    cout << "-------------------------------------------- " << endl;
    cout << "6) Patrons: Add " << endl;
    cout << "7) Patrons: List " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "8) Check Out Book " << endl;
    cout << "9) Place Hold " << endl;
    cout << "10) Place Book to Drop Box " << endl;
    cout << "11) Check In Books From Drop Box " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "20) Load Data " << endl;
    cout << "21) Save Data " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "99) Quit." << endl;
    cout << "============================================" << endl;

    int choice =0;
    cout << endl << endl;
    while (choice < 1 || choice > 21) {
        cout << "   Select your option [1-11 / 20-21 / 99]    " << endl;
        cin >> choice;
        if (choice == 99) {
            return -1;
        }
        return choice;
    }

}

void loadBookDatabase(shared_ptr<Library>&  myLibrary){
    cout <<"Loading initial Book data to Library"<<endl;

    myLibrary->addBook("Book1", "0001", "2000", "Pearson", "150");
    myLibrary->addBook("Book2", "0002", "2005", "Pearson", "345");
    myLibrary->addBook("Book3", "0003", "2010", "Pearson", "1170");
    myLibrary->addBook("Book4", "0004", "2015", "Pearson", "200");
    myLibrary->listAvailBooks();



}


int main() {
    auto myLibrary = make_shared<Library>();
    loadBookDatabase(myLibrary);
    /*

    // Book variables
    string Title, ISBN, aDataPublished, aPublisher, NumOfPages;
     // Patron variables
    string name, address, phoneNum;
    int choice = 0;
    while(choice>=0){
        choice = displayMenu();
        switch(choice){
            case 1: // Add a book
                bool loop = true;
                string answer;
                while(loop){
                    cout<<"Enter book information to be added to library"<<endl;

                    cin>> Title>>ISBN>>aDataPublished>>aPublisher>>NumOfPages;
                    myLibrary->addBook(Title, ISBN, aDataPublished, aPublisher, NumOfPages);
                    cout<<"Do you want to add another book (Y/N)?"<<endl;
                    cin >> answer;
                    if(answer == "Y" || answer == "y")
                        loop = true;
                    else
                        loop = false;
                break;
            case 2: // List available books
                myLibrary->listAvailBooks();
                break;
            case 3: // List checked out books
                myLibrary->listCheckOut();
                break;
            case 4: // Remove a book by title
                cout<<"Which book would you like to remove? (enter Book Title)"<<endl;
                cin>> Title>>endl;
                myLibrary->removeBook(Title);
                break;
            case 5: // Search for a book
                cout<<"What would you like to search for? (enter Book Title)"<<endl;
                cin>>Title;
                myLibrary->searchBookExact(Title)
                break;
            case 6: // Add a patron
                cout<<"Enter Patron information to be added to Library"<<endl;
                cin>> name>>address>>phoneNum;

                break;
            case 7: // List patrons
                break;
            case 8: // Check out a book
                break;
            case 9: // Place a hold
                break;
            case 10: // Place a book into dropbox
                break;
            case 11: // Check in books from dropbox
                break;
            case 20: // Load data
                break;
            case 21: // Save data
                break;



        }

    }
     */








    return 0;
}
