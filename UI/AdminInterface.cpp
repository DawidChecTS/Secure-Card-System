#include <iostream>
#include "AdminInterface.h"
#include "MainInterface.h"
#include <fstream>

using namespace std;

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
    cout << "Enter password: ";
    cin >> password;
}

void AdminInterface::displayAdminOperations(){
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
    cout << "Choose user: ";
}

void AdminInterface::listAllUsersView(){
    cout << "* Admin login *\n";
    cout << "All users listed: \n";
}

void AdminInterface::createNewUser() {
    int id;
    std::string username;
    std::string password;

    std::cout << "Enter new user id: ";
    std::cin >> id;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ofstream file("users.csv", std::ios::app);
    if (!file) {
        std::cout << "Unable to open users.csv file\n";
        return;
    }

    file << id << ',' << username << ',' << password << ",user\n";
    std::cout << "User saved to users.csv\n";
}