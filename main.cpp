#include "UI/UserInterface.h"
#include "UI/AdminInterface.h"
#include "UI/MainInterface.h"
#include <iostream>

using namespace std;

int main(){

    int userChoice;
    MainInterface maininterface;
    UserInterface userinterface;
    AdminInterface admininterface;

    do {
        maininterface.showMainMenu();
        userChoice = maininterface.validateUserInput();

        switch (userChoice){
            case 1 : 
                userinterface.userLogin();   
                userinterface.displayUserOperations();
                userChoice = maininterface.validateUserInput();
                if (userChoice == 1){
                    userinterface.listAllFloors();
                }
                else if (userChoice == 2){
                    userinterface.showInfoAboutAccount();
                }
                else { 
                    maininterface.printLogOut();
                }
                break;
            case 2 :
                admininterface.adminLogin();
                admininterface.displayAdminOperations();
                userChoice = maininterface.validateUserInput();
                if (userChoice == 1){
                    admininterface.chooseFloor();
                    break;
                }
                else if (userChoice == 2){
                    cout << "Not implemented yet! \n";
                }
                else if (userChoice == 3){
                    cout << "Not implemented yet! \n";
                }
                else { maininterface.printLogOut();
                }
                break;
            case 0 :
                maininterface.printExit();
                break;
            default:
            cout << "Invalid choice";
            }   
        }
    while (userChoice != 0);


    return 0;
}