#ifndef USER_H
#define USER_H
#include <string>

// User struct to represent users in the system
struct User{
    int id;
    std::string name;
    std::string email;
    std::string phonenumber;
    std::string role;
};
#endif