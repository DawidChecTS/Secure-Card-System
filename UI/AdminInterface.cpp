#include <iostream>
#include "AdminInterface.h"
#include "MainInterface.h"
#include "../Services/UserServices.h"
#include "../Services/AdminServices.h"
#include "../Services/FloorServices.h"
#include "../Services/ValidationServices.h"
#include <fstream>

using namespace std;

bool AdminInterface::adminLogin(){
    int id;
    string password;
    MainInterface maininterface;

    maininterface.headline();
    cout << "* Admin login *\n";

    // validate id input
    while (true) {
        cout << "Enter employee id: ";
        if (cin >> id) break; // if valid number, continue
        cout << "Invalid id! Must be a number.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Enter password: ";
    cin >> password;

    AdminServices adminservices;
    Admin admin = adminservices.findAdmin(id, password);

    if(admin.name.empty()){
        cout << "Login failed! Invalid id or password.\n";
        return false;
    } else {
        cout << "Welcome, " << admin.name << ".\n";
        return true;
    }
}

void AdminInterface::displayAdminOperations(){
    MainInterface maininterface;

    maininterface.headline();
    cout << '\n';
    cout << "[1] List all floors \n";
    cout << "[2] List all users \n";
    cout << "[3] Create a new user \n";
    cout << "[4] Log out \n";
}

void AdminInterface::chooseFloor(LogServices& logServices){
    FloorServices floorService;
    std::vector<Floor> floors = floorService.getAllFloors();

    // show all floors
    cout << '\n';
    cout << "All floors:\n\n";
    for (Floor floor : floors) {
        cout << "ID: " << floor.id << "\n";
        cout << "Name: " << floor.name << "\n";
        cout << "Clearance level: " << floor.clearanceLevel << "\n";
        cout << "-------------------------\n";
    }

    // pick a floor
    cout << "Choose floor id: ";
    int floorChoice;
    cin >> floorChoice;

    // find the chosen floor
    for (Floor floor : floors) {
        if (floor.id == floorChoice) {
            // show options for this floor
            cout << "\n[1] View access history\n";
            cout << "[2] Back\n";
            int choice;
            cin >> choice;

            if (choice == 1) {
                // get logs for this floor
                std::vector<LogEntry> logs = logServices.getLogsByFloor(floor.name);

                if (logs.empty()) {
                    cout << "No access history for this floor yet.\n";
                } else {
                    cout << "\nAccess history for " << floor.name << ":\n\n";
                    for (LogEntry entry : logs) {
                        cout << "User: " << entry.userName << "\n";
                        cout << "Time: " << entry.time << "\n";
                        cout << "Result: " << (entry.accessGranted ? "GRANTED" : "DENIED") << "\n";
                        cout << "-------------------------\n";
                    }
                }
            }
            return;
        }
    }
    cout << "Floor not found!\n";
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

    cout << '\n';
    for (User user : users) {
    std::cout << "ID: " << user.id << "\n";
    std::cout << "Name: " << user.name << "\n";
    std::cout << "Email: " << user.email << "\n";
    std::cout << "Phone: " << user.phonenumber << "\n";
    std::cout << "Card: " << user.card << "\n";
    std::cout << "Clearance level: " << user.clearanceLevel << "\n";
    std::cout << "----------------------\n";
    }

    cout << "\n[1] Delete a user\n";
    cout << "[2] Back\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int id;
        std::cout << "Enter users id to delete: ";
        std::cin >> id;
        userservice.deleteUser(id);
    }
}

void AdminInterface::createNewUser() {
    User user;
    user.role = "user";
    ValidationServices validationService;

    // valdiate ID
    while (true) {
    std::cout << "Enter id: ";
    if (std::cin >> user.id && validationService.isValidId(user.id)) break;
    std::cout << "Invalid id! Must be a positive number.\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    }   

    // Validate name
    while (true) {
    std::cout << "Enter name: ";
    std::cin >> user.name;
    if (validationService.isNameValid(user.name)) break;
    std::cout << "Invalid name! Name can not be empty! \n";
    } 

    // validate email
    while (true) {
        std::cout << "Enter email: ";
        std::cin >> user.email;
        if (validationService.isValidEmail(user.email)) break;
        std::cout << "Invalid email! Must be local@domain.tld\n";
    }

    // validate phone
    while (true) {
        std::cout << "Enter phone: ";
        std::cin >> user.phonenumber;
        if (validationService.isValidPhoneNumber(user.phonenumber)) break;
        std::cout << "Invalid phone! Must be 07XXXXXXXX or +467XXXXXXXX\n";
    }

    std::cout << "Enter card number: ";
    std::cin >> user.card;

    // validate clearance level
    while (true) {
        std::cout << "Enter clearance level (0-5): ";
        if (std::cin >> user.clearanceLevel && 
        user.clearanceLevel >= 0 && 
        user.clearanceLevel <= 3) 
        break;
        std::cout << "Invalid! Must be a number between 0 and 5.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
}

    UserService userService;
    userService.saveUser(user);
}
