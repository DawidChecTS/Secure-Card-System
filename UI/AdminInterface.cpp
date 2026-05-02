#include <iostream>
#include "AdminInterface.h"
#include "MainInterface.h"
#include "../Services/UserServices.h"
#include "../Services/AdminServices.h"
#include "../Services/FloorServices.h"
#include <fstream> // Input/Output fie stream library

using namespace std;

void AdminInterface::adminOperations(){
    int userChoice;
    MainInterface maininterface;

    maininterface.headline();
    cout << '\n';

    while (true){
        if (!(cin >> userChoice && (maininterface.isUserChoiceValidNumber(userChoice)))){
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        } 
    }
}

bool AdminInterface::adminLogin(){
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
