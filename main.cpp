#include "UI/UserInterface.h"
#include "UI/AdminInterface.h"
#include "UI/MainInterface.h"
#include "Services/UserServices.h"
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
                
                while(true){
                    userinterface.displayUserOperations();
                    userChoice = maininterface.validateUserInput();

                    if (userChoice == 1){
                        userinterface.listAllFloors();
                    }
                    else if (userChoice == 2){
                        userinterface.showInfoAboutAccount();
                    }
                    else if (userChoice == 3){
                        maininterface.printLogOut();
                        break; // exit to main menu
                    }
                    else  {
                        cout << "Invalid choice\n";
                    }
                }
                break;
            case 2 :
                admininterface.adminLogin();
                
                while(true){
                    admininterface.displayAdminOperations();
                    userChoice = maininterface.validateUserInput();

                    if (userChoice == 1){
                        admininterface.chooseFloor();
                    }
                    else if (userChoice == 2){
                        admininterface.listAllUsersView();
                    }
                    else if (userChoice == 3){
                        admininterface.createNewUser();
                    }
                    else if (userChoice == 4){
                        maininterface.printLogOut();
                        break; // exit to main menu
                    }
                    else  {
                        cout << "Invalid choice\n";
                    }
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