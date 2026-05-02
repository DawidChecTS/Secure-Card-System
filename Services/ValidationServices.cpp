#include <iostream>
#include "ValidationServices.h"

bool ValidationServices::isValidPassword(std::string password){
    // check if password is at least 8 characters long and contains at least one uppercase letter, one lowercase letter, and one digit
    if (password.length() < 8) {
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasNumber = false;
    bool hasSpecial = false;

    for (char c : password) {
        if (isupper(c)) hasUpper = true; // check for uppercase
        if (islower(c)) hasLower = true; // check for lowercase
        if (isdigit(c)) hasNumber = true; // check for number
        if (ispunct(c)) hasSpecial = true; // check for special character

    }

    return hasUpper && hasLower && hasNumber && hasSpecial;
}