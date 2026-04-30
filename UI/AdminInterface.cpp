#include <iostream>
#include "AdminInterface.h"
#include "MainInterface.h"
#include "../Services/UserServices.h"
#include "../Services/AdminServices.h"
#include <fstream> // Input/Output fie stream library

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

    AdminServices adminservices;
    Admin admin = adminservices.findAdmin(id, password);

    if(admin.name.empty()){
        cout << "Login failed! Invalid id or password.\n";
        return;
    } else {
        cout << "Welcome, " << admin.name << ".\n";
    }
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
        cin.clear(); // stops accepting the new input, resets the error
        cin.ignore(1000, '\n'); // leftover input is deleted
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
    UserService userservice;
    std::vector<User> users = userservice.getAllUsers();

    cout << "* Admin login *\n";
    for (User user : users) {
    std::cout << "ID: "    << user.id    << "\n";
    std::cout << "Name: "  << user.name  << "\n";
    std::cout << "Email: " << user.email << "\n";
    std::cout << "Phone: " << user.phonenumber << "\n";
    std::cout << "Card: "  << user.card  << "\n";
    std::cout << "----------------------\n";
    }
}

void AdminInterface::createNewUser() {
    User user;
    user.role = "user"; // always "user" when admin creates one

    std::cout << "Enter id: ";
    std::cin >> user.id;
    std::cout << "Enter name: ";
    std::cin >> user.name;
    std::cout << "Enter email: ";
    std::cin >> user.email;
    std::cout << "Enter phone: ";
    std::cin >> user.phonenumber;
    std::cout << "Enter card number: ";
    std::cin >> user.card;

    UserService userService;
    userService.saveUser(user); // hands off to service
}
