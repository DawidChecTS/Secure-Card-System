#include <iostream>
#include "ValidationServices.h"


bool ValidationServices::isValidId(int id) {
    return id > 0; // id must be a positive number
}

bool ValidationServices::isNameValid(std::string name) {
    return !name.empty(); // name can not be empty
}

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

// size_t is an unsigned integer type that can represent the size of any object in bytes. 

bool ValidationServices::isValidEmail(std::string email) {
    // find @ symbol
    size_t atPos = -1;
    for (size_t i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            atPos = i;
            break;
        }
    }
    // no @ found or @ is at start
    if (atPos == std::string::npos || atPos == 0) return false; 

    // find dot after @
    size_t dotPos = -1;
    for (size_t i = atPos; i < email.length(); i++) {
        if (email[i] == '.') {
            dotPos = i;
            break;
        }
    }
    // if no dot found, dot is right after @ or dot is at the end
    if (dotPos == std::string::npos || dotPos == atPos + 1) return false;
    if (dotPos == email.length() - 1) return false;

    return true;
}

bool ValidationServices::isValidPhoneNumber(std::string phone) {
    // must be 07XXXXXXXX (10 digits) or +467XXXXXXXX (12 chars)
    if (phone.length() == 10) {
        // start with 07
        if (phone[0] == '0' && phone[1] == '7') {
            for (size_t i = 2; i < phone.length(); i++) {
                if (!isdigit(phone[i])) return false;
            }
            return true;
        }
    }

    if (phone.length() == 12) {
        // start with +467
        if (phone[0] == '+' && phone[1] == '4' && 
            phone[2] == '6' && phone[3] == '7') {
            for (size_t i = 4; i < phone.length(); i++) {
                if (!isdigit(phone[i])) return false;
            }
            return true;
        }
    }

    return false;
}