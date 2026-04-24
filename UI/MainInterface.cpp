#include <iostream>
#include "MainInterface.h"
#include "AdminInterface.h"

using namespace std;

void MainInterface::headline(){
    cout << "----- SECURE CARD SYSTEM -------\n";
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
    return (a >= 0 && a <= 4);
}

void MainInterface::displayEnteringOptions(){
    cout << "[1] User \n";
    cout << "[2] Admin \n";
    cout << "[0] Exit \n";
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
