#include <iostream>
#include "UserMenu.h"

using namespace std;

void headline(){
    cout << "----- SECURE CARD SYSTEM -------\n";
}

void showMainMenu(){
    headline();
    cout << "[1] User \n";
    cout << "[2] Admin \n";
    cout << "[0] Exit \n";
}

