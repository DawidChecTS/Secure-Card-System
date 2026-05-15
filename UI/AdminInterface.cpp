#include <iostream>
#include "AdminInterface.h"
#include "MainInterface.h"
#include "../Services/UserServices.h"
#include "../Services/AdminServices.h"
#include "../Services/FloorServices.h"
#include "../Services/ValidationServices.h"
#include "../Services/CardServices.h"
#include <fstream>

using namespace std;

bool AdminInterface::adminLogin(){
    int id;
    string password;
    MainInterface maininterface;
    ValidationServices validationService;

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

    // validate password format
    // validationService will check if the password valid before checking the csv file
    // not specified in the requirements
    while (true) {
        cout << "Enter password: ";
        cin >> password;
        if (validationService.isValidPassword(password)) break;
        cout << "Invalid password format! Must be at least 8 characters, with 1 uppercase, 1 lowercase, 1 number and 1 special character.\n";
    }

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
    if (!(cin >> floorChoice)) {
        cout << "Invalid input! Must be a number.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return; // go back to admin menu
    }

    // find the chosen floor
    for (Floor floor : floors) {
        if (floor.id == floorChoice) {
            // show options for this floor
            cout << "\n[1] View access history\n";
            cout << "[2] Change floor information\n";
            cout << "[3] Back\n";

            int choice;
            if (!(cin >> choice)) {
                cout << "Invalid input! Must be a number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                return; // go back to admin menu
            }

            if (choice == 1) {
                // get logs for this floor
                std::vector<LogEntry> logs = logServices.getLogsByFloor(floor.name);
                // display logs
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
            else if (choice == 2) {
                std::string tempName;
                std::cout << "Enter new name (" << floor.name << "): ";
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, tempName);
                floor.name = tempName;


                while (true) {
                    std::cout << "Enter new clearance level (" << floor.clearanceLevel << "): ";
                    if (std::cin >> floor.clearanceLevel &&
                        floor.clearanceLevel >= 0 &&
                        floor.clearanceLevel <= 3) break;
                    std::cout << "Invalid! Must be between 0 and 3.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                floorService.updateFloor(floor);
            }
            return;
        }
    }
    cout << "Floor not found!\n";
}

void AdminInterface::listAllUsersView(){
    UserService userservice;
    std::vector<User> users = userservice.getAllUsers();
    CardService cardService;

    cout << '\n';
    for (User user : users) {
    Card card = cardService.findCardByUserId(user.id);
    std::cout << "ID: " << user.id << "\n";
    std::cout << "Name: " << user.name << "\n";
    std::cout << "Email: " << user.email << "\n";
    std::cout << "Phone: " << user.phonenumber << "\n";
    std::cout << "Card ID: " << card.id << "\n";
    std::cout << "Clearance level: "<< card.clearanceLevel << "\n";
    std::cout << "----------------------\n";
    }

    cout << "\n[1] Delete a user\n";
    cout << "[2] Change user information\n";
    cout << "[3] Back\n";

    MainInterface maininterface;

    int choice;
    // validate user input
    while (true) {
        choice = maininterface.validateUserInput();
        if (choice == -1) continue;
        if (choice >= 1 && choice <= 3) break;
        cout << "Invalid choice!\n";
}

    if (choice == 1) {
            int id;
    // validate id input
    while (true) {
        std::cout << "Enter user id to delete: ";
        if (std::cin >> id) break;
        std::cout << "Invalid id! Must be a number.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    userservice.deleteUser(id);
    CardService cardService;
    cardService.deleteCardByUserId(id);
    }

    else if (choice == 2) {
        int id;
        std::cout << "Enter user id to change: ";
        std::cin >> id;

        // find the user first
        User user = userservice.findUser(std::to_string(id));
        if (user.name.empty()) {
            std::cout << "User not found!\n";
            return;
        }

        // change name
        std::string tempName;
        std::cout << "Enter new name (" << user.name << "): ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, tempName);
        user.name = tempName;

        ValidationServices validationService;

        // change email +  validation
        while (true) {
            std::string tempEmail;
            std::cout << "Enter new email (" << user.email << "): ";
            std::cin >> tempEmail;

            if (validationService.isValidEmail(tempEmail)) {
                user.email = tempEmail; // only update if valid
                break;
            }
            std::cout << "Invalid email!\n";
        }

        // change phone + validation
        while (true) {
        std::string tempPhone;
        std::cout << "Enter new phone (" << user.phonenumber << "): ";
        std::cin >> tempPhone;
        if (validationService.isValidPhoneNumber(tempPhone)) {
            user.phonenumber = tempPhone;
            break;
        }
        std::cout << "Invalid phone!\n";
        }

        userservice.updateUser(user);
    }
}

void AdminInterface::createNewUser() {
    User user;
    user.role = "user";
    ValidationServices validationService;
    CardService cardService;

    // valdiate ID
    while (true) {
        std::cout << "Enter id: ";
    if (std::cin >> user.id && validationService.isValidId(user.id)) {
        UserService userService;
        if (!userService.isIdTaken(user.id)) break;
        std::cout << "ID already exists!\n";
    } else {
        std::cout << "Invalid id! \n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        }
    }   

    // Validate name
    while (true) {
        std::cout << "Enter name: ";
        std::cin >> user.name;
        if (validationService.isNameValid(user.name)) break;
        std::cout << " Name can not be empty! \n";
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

    Card card;
    card.userId = user.id;

    // validate card id
    while (true) {
        std::cout << "Enter card id: ";
        if (std::cin >> card.id && card.id > 0) {
            Card existing = cardService.findCardById(card.id); // check if card id already exists
            if (existing.id == 0) break; // 0 means not found = id is free
            std::cout << "Card id already exists! \n";
        } else {
            std::cout << "Invalid card id! \n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

    // validate clearance level
    while (true) {
        std::cout << "Enter clearance level (0-3): ";
        if (std::cin >> card.clearanceLevel && 
        card.clearanceLevel >= 0 && 
        card.clearanceLevel <= 3) 
        break;
        std::cout << "Invalid clearance level!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    // save user and card
    UserService userService;
    userService.saveUser(user);
    cardService.saveCard(card);
}

