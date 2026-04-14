#include <iostream>
#include "UserMenu.h"

using namespace std;

void UserMenu::headline(){
    cout << "----- SECURE CARD SYSTEM -------\n";
}

void UserMenu::showMainMenu(){
    int userChoice;

    headline();
    
    cout << "[1] User \n";
    cout << "[2] Admin \n";
    cout << "[0] Exit \n";

    cin >> userChoice;
    // Validate user input
    while (true){
        if(!(cin >> userChoice)){
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (userChoice){
            case 1 : 
                userLogin();   
                break;
            case 2 :
                adminLogin();
                break ;
            case 0 :
                printExit();
                return;
        }

    }   
}


void UserMenu::userLogin(){
    headline();
    cout << "* User login *\n";
    cout << "Enter employee id or name: \n";
}

void UserMenu::userOperations(){
    headline();
    cout << "[1] List all available floors \n";
    cout << "[2] Show personal information \n";
    cout << "[3] Log out \n"; 
}

void UserMenu::adminLogin(){
    int id;
    string password;

    headline();
    cout << "* Admin login *\n";
    cout << "Enter employee id: ";
    cin >> id;
    cout << "Enter password: \n";
    cin >> password;
}

void UserMenu::adminOperations(){

}

void UserMenu::printExit() {
    cout << "You choose to Exit the Secure Card System!\n";
}