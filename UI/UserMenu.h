#ifndef USERMENU_H
#define USERMENU_H

class Interface {
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
    void welcomeAdmin();
    void listAllFloors();
    void showInfoAboutAccount();
    bool isUserChoiceValidNumber(int a);
    void displayEnteringOptions();
    void displayUserOperations();
    int validateUserInput();
    bool isAdminLoggedIn = false;
};


#endif