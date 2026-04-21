#include <iostream>
#include "UserMenu.h"

using namespace std;

void Interface::headline(){
    cout << "----- SECURE CARD SYSTEM -------\n";
}

void Interface::showMainMenu(){

    headline();
    
    displayEnteringOptions();
}

void Interface::userLogin(){
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
}

void Interface::userOperations(){

    int userChoice;

    headline();
    welcomeUser();
    displayUserOperations();

    while (true){
        if (!(cin >> userChoice && (isUserChoiceValidNumber(userChoice)))){
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(1000, '\n');
            displayUserOperations();
            continue;
        }  
    }
}

void Interface::adminOperations(){
    int userChoice;
    headline();
    welcomeUser();

    while (true){
        if (!(cin >> userChoice && (isUserChoiceValidNumber(userChoice)))){
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(1000, '\n');
            displayUserOperations();
            continue;
        } 

    }
}

void Interface::adminLogin(){
    int id;
    string password;

    headline();
    cout << "* Admin login *\n";
    cout << "Enter employee id: ";
    cin >> id;
    cout << "Enter password: \n";
    cin >> password;
}

void Interface::printExit() {
    cout << "You choose to Exit the Secure Card System!\n";
}

void Interface::printLogOut() {
    cout << "You are logging out.";
}

void Interface::welcomeUser(){
    cout << "Welcome User!\n";
}

void Interface::welcomeAdmin(){
    cout << "Welcome Admin!\n";
}

void Interface::listAllFloors(){
    cout << "All floors listed: \n";
}

void Interface::showInfoAboutAccount(){
    cout << "Info about account: \n";
}

bool Interface::isUserChoiceValidNumber(int a){
    if (isAdminLoggedIn){
            if(a < 4 && a > -1){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if(a < 3 && a > -1){
            return true;
        }
        else {
            return false;
        }
    }
}

void Interface::displayEnteringOptions(){
    cout << "[1] User \n";
    cout << "[2] Admin \n";
    cout << "[0] Exit \n";
}

void Interface::displayUserOperations(){
    cout << "[1] List all available floors \n";
    cout << "[2] Show personal information \n";
    cout << "[0] Log out \n"; 
}

int Interface::validateUserInput(){
    int b;
        while (true){
        if (!(cin >> b && (isUserChoiceValidNumber(b)))){
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        return b;
    }
}

void Interface::displayAdminOperations(){
    Interface::isAdminLoggedIn = true;

    headline();
    welcomeAdmin();
    cout << "[1] List all floors \n";
    cout << "[2] List all users \n";
    cout << "[3] Create a new user \n";
    cout << "[0] Log out \n";
}