#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

class AdminInterface{
    public :
        bool adminLogin();
        void adminOperations();
        void displayAdminOperations();
        void chooseFloor();
        void chooseUser();
        void listAllFloorsView();
        void listAllUsersView();
        void createNewUser();
};

#endif