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

bool ValidationServices::isValidEmail(std::string email) {
    // find @ symbol
    int atPos = -1;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            atPos = i;
            break;
        }
    }
    // no @ found or @ is at start
    if (atPos <= 0) return false;

    // find dot after @
    int dotPos = -1;
    for (int i = atPos; i < email.length(); i++) {
        if (email[i] == '.') {
            dotPos = i;
            break;
        }
    }
    // if no dot found, dot is right after @ or dot is at the end
    if (dotPos == -1 || dotPos == atPos + 1) return false;
    if (dotPos == email.length() - 1) return false;

    return true;
}