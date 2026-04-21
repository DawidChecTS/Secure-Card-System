#include "UI/UserMenu.h"
#include <iostream>

using namespace std;

int main(){

    int userChoice;
    //int userLogin;
    //char userPassword;
    Interface interface;

    do {
        interface.showMainMenu();
        userChoice = interface.validateUserInput();

        switch (userChoice){
            case 1 : 
                interface.userLogin();   
                interface.displayUserOperations();
                userChoice = interface.validateUserInput();
                if (userChoice == 1){
                    interface.listAllFloors();
                }
                else if (userChoice == 2){
                    interface.showInfoAboutAccount();
                }
                else { interface.printLogOut();
                    break;
                }
                break;
            case 2 :
                interface.adminLogin();
                interface.displayAdminOperations();
                userChoice = interface.validateUserInput();
                if (userChoice == 1){

                }
                else if (userChoice == 2){

                }
                else if (userChoice == 3){

                }
                else { interface.printLogOut();
                    break;
                }
            case 0 :
                interface.printExit();
                break;
            default:
            cout << "Invalid choice";
            }   
        }
    while (userChoice != 0);


    return 0;
}