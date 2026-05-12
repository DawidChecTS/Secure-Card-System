#ifndef ADMIN_H
#define ADMIN_H
#include <string>

// Admin struct to represent admin users in the system
struct Admin {
    int id;
    std::string name;
    std::string password;
    std::string role;

};

#endif