#ifndef ADMIN_H
#define ADMIN_H
#include <string>

// Admin struct to represent admin users in the system
struct Admin {
    int id;
    std::string name;
    std::string email;
    std::string phonenumber;
    std::string password;
    std::string card;
    std::string role;
};

#endif