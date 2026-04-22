#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

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

#endif