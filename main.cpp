#include <iostream>
#include "Library.cpp"de

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

int main() {
    auto myLibrary = make_shared<Library>();
    int choice = 0;
    string Title;

    while(choice>=0){

    }








    return 0;
}
