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

    
    // Validate user input
    while (true){
        if(!(cin >> userChoice && isUserChoiceValidNumber(userChoice))){
            cout << "Invalid input!\n";
            cin.clear(); // reset
            cin.ignore(1000, '\n'); // remove input
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
    int id;
    
    headline();
    cout << "* User login *\n";

    while (true){
        cout << "Enter employee id or name: \n";

        if (cin >> id){
            break; // if input is valid, exit the loop
        }
        cout << "Invalid input! Please enter a number! \n";
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
    userOperations();
}

void UserMenu::userOperations(){

    int userChoice;

    headline();
    welcomeUser();
    cout << "[1] List all available floors \n";
    cout << "[2] Show personal information \n";
    cout << "[0] Log out \n"; 

    while (true){
        if (!(cin >> userChoice && (isUserChoiceValidNumber(userChoice)))){
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
    
        switch (userChoice){
            case 1 : 
                listAllFloors();   
                return;
            case 2 :
                showInfoAboutAccount();
                return ;
            case 0 :
                printExit();
                return;
        }
    }
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
    cout << "[0] Exit \n";
}

void UserMenu::printExit() {
    cout << "You choose to Exit the Secure Card System!\n";
}

void UserMenu::welcomeUser(){
    cout << "Welcome User!\n";
}

void UserMenu::listAllFloors(){
    cout << "All floors listed: \n";
}

void UserMenu::showInfoAboutAccount(){
    cout << "Info about account: \n";
}

bool UserMenu::isUserChoiceValidNumber(int a){

    if(a < 3 && a > -1){
        return true;
    }
    else {
        return false;
    }
}