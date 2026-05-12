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

    cout << "Choose floor id to access: ";
    int floorChoice;
    // validate floor choice
    if (!(cin >> floorChoice)) {
        cout << "Invalid input! Must be a floor number.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    for (Floor floor : floors) {
        if (floor.id == floorChoice) {
            // check clearance
            if (card.clearanceLevel >= floor.clearanceLevel) {
                cout << "ACCESS GRANTED to " << floor.name << "!\n";
                logServices.addLog(user.name, floor.name, true); // log if access granted
            } else {
                cout << "ACCESS DENIED!\n";
                logServices.addLog(user.name, floor.name, false); // log if access denied
            }
            return;
        }
    }
    cout << "Floor not found!\n";
}

void UserInterface::showInfoAboutAccount(User user){
    MainInterface maininterface;
    Card card = CardService().findCardByUserId(user.id);

     while (true) {
        maininterface.headline();

        cout << "\nInfo about account:\n";
        cout << "Name: " << user.name << "\n";
        cout << "Email: " << user.email << "\n";
        cout << "Phone number: " << user.phonenumber << "\n";
        cout << "Card ID: " << card.id << "\n";
        cout << "Clearance level: " << card.clearanceLevel << "\n";

        cout << "\n[1] Go back\n";
        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input! Must be a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            return; // go back to previous menu
        }

        cout << "Invalid choice!\n";
    }
}

void UserInterface::displayUserOperations(){

    MainInterface maininterface;
    maininterface.headline();
    cout << "\n";
    cout << "[1] List all available floors \n";
    cout << "[2] Show personal information \n";
    cout << "[3] Change personal information \n";
    cout << "[4] Log out \n"; 
}

void UserInterface::changeInformation(User& user){
    UserService userService;
    ValidationServices validationService;

    std::string tempName;
    std::cout << "Enter new name (" << user.name << "): ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, tempName);
    user.name = tempName;

    while (true) {
        std::string tempEmail;
        std::cout << "Enter new email (" << user.email << "): ";
        std::cin >> tempEmail;
        if (validationService.isValidEmail(tempEmail)) {
            user.email = tempEmail;
            break;
        }
        std::cout << "Invalid email!\n";
    }

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

    userService.updateUser(user);
}