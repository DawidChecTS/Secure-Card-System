#ifndef USERMENU_H
#define USERMENU_H

class MainInterface {
    public :

        void showMainMenu();
        void headline();
        void printExit();
        void printLogOut();
        bool isUserChoiceValidNumber(int a);
        void displayEnteringOptions();
        int validateUserInput();
        

};

class AdminInterface{
    public :
        bool isAdminLoggedIn = false;
        void adminLogin();
        void adminOperations();
        void displayAdminOperations();
        void chooseFloor();
        void chooseUser();
        void listAllFloorsView();
        
};

class UserInterface{
    public :
        void userLogin();
        void userOperations();
        void displayUserOperations();
        void showInfoAboutAccount();
        void listAllFloors();
};


#endif