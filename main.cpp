#include "UI/UserMenu.h"
#include <iostream>

using namespace std;

int main(){

    int userChoice;
    //int userLogin;
    //char userPassword;
    UserMenu usermenu;

    do {
        usermenu.showMainMenu();
        userChoice = usermenu.validateUserInput();

        switch (userChoice){
            case 1 : 
                usermenu.userLogin();   
                usermenu.displayUserOperations();
                userChoice = usermenu.validateUserInput();
                if (userChoice == 1){
                    usermenu.listAllFloors();
                }
                else if (userChoice == 2){
                    usermenu.showInfoAboutAccount();
                }
                else { usermenu.printLogOut();
                    break;
                }
                break;
            case 2 :
                usermenu.adminLogin();
                usermenu.displayAdminOperations();
                break;
            case 0 :
                usermenu.printExit();
                break;
            default:
            cout << "Invalid choice";
            }   
        }
    while (userChoice != 0);


    return 0;
}