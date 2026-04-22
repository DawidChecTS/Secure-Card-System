#include <iostream>
#include "UserMenu.h"

using namespace std;

void MainInterface::headline(){
    cout << "----- SECURE CARD SYSTEM -------\n";
}

void MainInterface::showMainMenu(){

    headline();
    
    displayEnteringOptions();
}

void UserInterface::userLogin(){
    int id;
    MainInterface maininteface;

    maininteface.headline();

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

void UserInterface::userOperations(){

    int userChoice;
    MainInterface maininterface;

    maininterface.headline();
    displayUserOperations();

    while (true){
        if (!(cin >> userChoice && (maininterface.isUserChoiceValidNumber(userChoice)))){
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(1000, '\n');
            displayUserOperations();
            continue;
        }  
    }
}

void AdminInterface::adminOperations(){
    int userChoice;
    MainInterface maininterface;

    maininterface.headline();
    cout << "* Admin login *\n";

    while (true){
        if (!(cin >> userChoice && (maininterface.isUserChoiceValidNumber(userChoice)))){
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        } 

    }
}

void AdminInterface::adminLogin(){
    int id;
    string password;
    MainInterface maininterface;

    maininterface.headline();
    cout << "* Admin login *\n";
    cout << "Enter employee id: ";
    cin >> id;
    cout << "Enter password: \n";
    cin >> password;
}

void MainInterface::printExit() {
    cout << "You choose to Exit the Secure Card System!\n";
}

void MainInterface::printLogOut() {
    cout << "You are logging out. \n";
}

void UserInterface::listAllFloors(){
    cout << "* User login *\n";
    cout << "All floors listed: \n";
}

void UserInterface::showInfoAboutAccount(){
    cout << "* User login *\n";
    cout << "Info about account: \n";
}

bool MainInterface::isUserChoiceValidNumber(int a){
    AdminInterface admininterface;

    if (admininterface.isAdminLoggedIn){
            if(a < 5 && a > 0){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if(a < 4 && a > 0){
            return true;
        }
        else {
            return false;
        }
    }
}

void MainInterface::displayEnteringOptions(){
    cout << "[1] User \n";
    cout << "[2] Admin \n";
    cout << "[0] Exit \n";
}

void UserInterface::displayUserOperations(){

    MainInterface maininterface;
    maininterface.headline();
    cout << "* User login *\n";
    cout << "[1] List all available floors \n";
    cout << "[2] Show personal information \n";
    cout << "[3] Log out \n"; 
}

int MainInterface::validateUserInput(){
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

void AdminInterface::displayAdminOperations(){
    AdminInterface::isAdminLoggedIn = true;
    MainInterface maininterface;

    maininterface.headline();
    cout << "* Admin login *\n";
    cout << "[1] List all floors \n";
    cout << "[2] List all users \n";
    cout << "[3] Create a new user \n";
    cout << "[4] Log out \n";
}

void AdminInterface::chooseFloor(){
    int floor;
    
        while (true){
        cout << "* Admin login *\n";
        cout << "Choose floor: \n";

        if (cin >> floor){
            break; // if input is valid, exit the loop
        }
        cout << "Invalid input! Please enter a number! \n";
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
        }
}

void AdminInterface::chooseUser(){
    MainInterface mainterface;

    mainterface.headline();
    cout << "* User login *\n";
    cout << "Choose user: \n";
}

