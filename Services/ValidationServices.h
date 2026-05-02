#ifndef VALIDATIONSERVICES_H
#define VALIDATIONSERVICES_H
#include <string>

class ValidationServices{
    public:
        bool isValidPassword(std::string password);
        bool isValidEmail(std::string email);
        bool isValidPhoneNumber(std::string phoneNumber);
};



#endif