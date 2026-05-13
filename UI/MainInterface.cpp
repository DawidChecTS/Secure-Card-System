#include <iostream>
#include "MainInterface.h"
#include "AdminInterface.h"

using namespace std;

void MainInterface::headline(){
    cout << "\n----- SECURE CARD SYSTEM -------\n";
}

void MainInterface::showMainMenu(){
    headline();
    displayEnteringOptions();
}

void MainInterface::printExit() {
    cout << "You choose to Exit the Secure Card System!\n";
}

void MainInterface::printLogOut() {
    cout << "You are logging out. \n";
}

bool MainInterface::isUserChoiceValidNumber(int a){
    return a >= 0 && a <= 4;
}

void MainInterface::displayEnteringOptions(){
    cout << "[1] User \n";
    cout << "[2] Admin \n";
    cout << "[0] Exit \n";
}

int MainInterface::validateUserInput(){
    std::string input;
    cin >> input;

    // check if input is empty
    if (input.empty()) {
        cout << "Invalid Input!\n";
        return -1;
    }

    // check if input contains only digits
    for (char c : input) {
        if (!isdigit(c)) {
            cout << "Invalid Input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return -1;
        }
    }
    // convert string to integer and check if it's a valid choice
    try {
        int b = stoi(input);
        if (!isUserChoiceValidNumber(b)) {
            cout << "Invalid Input!\n";
            return -1;
        }
        return b;
    } catch (...) {
        cout << "Invalid Input!\n";
        return -1;
    }
}




