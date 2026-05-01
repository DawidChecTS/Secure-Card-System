#ifndef USER_H
#define USER_H
#include <string>

struct User{
    int id;
    std::string name;
    std::string email;
    std::string phonenumber;
    std::string card;
    int clearanceLevel;
    std::string role;
};


#endif