#include <fstream>
#include <sstream>
#include <iostream>
#include "UserServices.h"
#include <vector>


// Read all users from users.csv and returns them as a list
std::vector<User> UserService::getAllUsers() {
std::vector<User> users; // empty list to start
std::ifstream file("users.csv");

    if (!file) {
        std::cout << "Unable to open users.csv file\n";
        return users;
    }

    std::string line;
    while (std::getline(file, line)) {
    std::stringstream ss(line);
    User user;
    std::string id;
    std::string clearanceLevel;

    std::getline(ss, id, ',');
    user.id = std::stoi(id);
    std::getline(ss, user.name, ',');
    std::getline(ss, user.email, ',');
    std::getline(ss, user.phonenumber, ',');
    std::getline(ss, user.card, ',');
    std::getline(ss, clearanceLevel, ',');
    user.clearanceLevel = std::stoi(clearanceLevel);
    std::getline(ss, user.role, ',');

    users.push_back(user);
}

    file.close();
    return users; // returns the full list
}

// Saves a new user to users.csv
void UserService::saveUser(User user) {
    std::ofstream file("users.csv", std::ios::app);

    if (!file) {
        std::cout << "Unable to open users.csv\n";
        return;
    }

    file << user.id << ','
         << user.name << ','
         << user.email << ','
         << user.phonenumber << ','
         << user.card << ','
         << user.clearanceLevel << ','
         << user.role << '\n';

    std::cout << "User saved successfully!\n";
    file.close();
}

User UserService::findUser(std::string input) {
    std::vector<User> users = getAllUsers(); // get all users from CSV file

    for (User user : users) {
        // check if input matches id or name
        if (user.name == input || std::to_string(user.id) == input) {
            return user; // return user if found
        }
    }

    // if no user found, return an empty user
    return User{};
}

void UserService::deleteUser(int id) {
    std::vector<User> users = getAllUsers(); 

    // open file for writing
    std::ofstream file("users.csv");

    if (!file) {
        std::cout << "Unable to open users.csv\n";
        return;
    }

    bool found = false;
    for (User user : users) {
        if (user.id == id) {
            found = true;
            continue; // skip this user — effectively deleting them
        }
        // write everyone else back to the fileS
        file << user.id << ','
             << user.name << ','
             << user.email << ','
             << user.phonenumber << ','
             << user.card << ','
             << user.clearanceLevel << ','
             << user.role << '\n';
    }

    file.close();

    if (found) {
        std::cout << "User deleted successfully!\n";
    } else {
        std::cout << "User not found!\n";
    }
}