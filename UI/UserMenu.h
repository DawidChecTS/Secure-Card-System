#ifndef USERMENU_H
#define USERMENU_H

class UserMenu {
public :
    void adminLogin();
    void adminOperations();
    void displayAdminOperations();
    void showMainMenu();
    void headline();
    void userLogin();
    void userOperations();
    void printExit();
    void printLogOut();
    void welcomeUser();
    void listAllFloors();
    void showInfoAboutAccount();
    bool isUserChoiceValidNumber(int a);
    void displayEnteringOptions();
    void displayUserOperations();
    int validateUserInput();
};


#endif