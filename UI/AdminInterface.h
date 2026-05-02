#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H
#include "../Models/User.h"
#include "../Services/LogServices.h"


class AdminInterface{
    public :
        bool adminLogin();
        void adminOperations();
        void displayAdminOperations();
        void chooseFloor(LogServices& logServices);
        void chooseUser();
        void listAllFloorsView();
        void listAllUsersView();
        void createNewUser();
};

#endif