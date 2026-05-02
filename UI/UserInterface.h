#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "../Models/User.h"
#include "../Services/LogServices.h"

class UserInterface{
    public :
        User userLogin();
        void userOperations();
        void displayUserOperations();
        void showInfoAboutAccount(User user);
        void listAllFloors(User user, LogServices& logServices);
};

#endif