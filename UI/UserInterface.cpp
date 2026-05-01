#include <iostream>
#include "UserInterface.h"
#include "MainInterface.h"
#include <string>
#include "../Services/UserServices.h"
#include "../Services/FloorServices.h"

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

void UserInterface::listAllFloors(){
    FloorServices floorService;
    vector<Floor> floors = floorService.getAllFloors();

    MainInterface maininterface;
    maininterface.headline();
    cout << '\n';
    cout << "List with the all floors: \n";

    for (Floor floor : floors){
        cout << "ID: " << floor.id << '\n';
        cout << "Name: " << floor.name << '\n';
        cout << "Clearance level: " << floor.clearanceLevel << "\n\n";
        cout << "-------------------------\n";
    }
}

void UserInterface::showInfoAboutAccount(User user){
    MainInterface maininterface;
    maininterface.headline();
    cout << '\n';
    cout << "Info about account: \n";
    cout << "Name: " << user.name << "\n";
    cout << "Email: " << user.email << "\n";
    cout << "Phone number: " << user.phonenumber << "\n";
    cout << "Card: " << user.card << "\n";
}

void UserInterface::displayUserOperations(){

    MainInterface maininterface;
    maininterface.headline();
    cout << "* User login *\n";
    cout << "[1] List all available floors \n";
    cout << "[2] Show personal information \n";
    cout << "[3] Log out \n"; 
}
