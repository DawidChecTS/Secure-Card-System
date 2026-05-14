#include <iostream>
#include "UserInterface.h"
#include "MainInterface.h"
#include <string>
#include "../Services/UserServices.h"
#include "../Services/FloorServices.h"
#include "../Services/LogServices.h"
#include "../Services/ValidationServices.h"
#include "../Services/CardServices.h"

using namespace std;

User UserInterface::userLogin(){
    string input;
    MainInterface maininterface;

    maininterface.headline();
    cout << '\n';
    cout << "Enter id or name: ";
    cin >> input;

    UserService userService;
    User loggedInUser = userService.findUser(input);

    if (loggedInUser.name.empty()) {
        // empty name means no user is found
        cout << "User not found!\n";
        return User{}; // return an empty user to indicate failure
    } else {
        cout << '\n'<< "Welcome, " << loggedInUser.name << "\n";
        return loggedInUser; // return the logged-in user
    }
}

// a method to list all floors and allow the user to choose one to access
void UserInterface::listAllFloors(User user, LogServices& logServices){
    FloorServices floorService;
    vector<Floor> floors = floorService.getAllFloors();
    Card card = CardService().findCardByUserId(user.id);

    MainInterface maininterface;
    maininterface.headline();
    cout << "\n All floors: \n";
 
    for (Floor floor : floors){
        cout << "ID: " << floor.id << '\n';
        cout << "Name: " << floor.name << '\n';
        cout << "Clearance level: " << floor.clearanceLevel << "\n";
        cout << "-------------------------\n";
    }

    while (true) { 
        cout << "[0,1,2,3] Choose which floor id to access\n";
        cout << "[4] Go back\n";
        int floorChoice;

        // validate user input
        if (!(cin >> floorChoice)) {
            cout << "\n Invalid input! Must be a floor number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue; 
        }

        if (floorChoice == 4) return; 

        bool found = false;
        // check if the chosen floor exists
        for (Floor floor : floors) {
            // if it exists, check clearance level
            if (floor.id == floorChoice) {
                found = true;
                if (card.clearanceLevel >= floor.clearanceLevel) {
                    cout << "ACCESS GRANTED \n";
                    logServices.addLog(user.name, floor.name, true);
                } else {
                    cout << "ACCESS DENIED! Your clearance level is too low.\n";
                    logServices.addLog(user.name, floor.name, false);
                }
                return; // exit after access attempt
            }
        }

        if (!found) {
            cout << "Floor not found!\n";
            continue;
        }
    }
}

void UserInterface::showInfoAboutAccount(User& user){
    MainInterface maininterface;
    Card card = CardService().findCardByUserId(user.id);

    while (true) {
        maininterface.headline();

        cout << "\nYour account:\n";
        cout << "----------------------\n";
        cout << "Name: " << user.name << "\n";
        cout << "Email: " << user.email << "\n";
        cout << "Phone number: " << user.phonenumber << "\n";
        cout << "Card ID: " << card.id << "\n";
        cout << "Clearance level: " << card.clearanceLevel << "\n";
        cout << "----------------------\n";
        cout << "[1] Change information\n";
        cout << "[2] Go back\n";

        int choice = maininterface.validateUserInput();

        if (choice == -1) continue;
        else if (choice == 1) {
            changeInformation(user);
        }
        else if (choice == 2) {
            return;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
}

void UserInterface::displayUserOperations(){

    MainInterface maininterface;
    maininterface.headline();
    cout << "\n";
    cout << "[1] List all available floors \n";
    cout << "[2] Show personal information \n";
    cout << "[3] Log out \n"; 
}

void UserInterface::changeInformation(User& user){
    UserService userService;
    ValidationServices validationService;

    // validate ID
    std::string tempName;
    std::cout << "Enter new name (" << user.name << "): ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, tempName);
    if (!tempName.empty()) user.name = tempName; // only update if not empty

    // validate email
    while (true) {
        std::string tempEmail;
        std::cout << "Enter new email (" << user.email << "): ";
        if (!(std::cin >> tempEmail)) {
            std::cout << "Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        if (validationService.isValidEmail(tempEmail)) {
            user.email = tempEmail;
            break;
        }
        std::cout << "Invalid email!\n";
    }

    // validate phone number
    while (true) {
        std::string tempPhone;
        std::cout << "Enter new phone (" << user.phonenumber << "): ";
        if (!(std::cin >> tempPhone)) {
            std::cout << "Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        if (validationService.isValidPhoneNumber(tempPhone)) {
            user.phonenumber = tempPhone;
            break;
        }
        std::cout << "Invalid phone!\n";
    }
    userService.updateUser(user);
    std::cout << "Users information updated successfully!\n";
}