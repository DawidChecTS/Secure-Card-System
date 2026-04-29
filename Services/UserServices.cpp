#include <fstream>
#include <sstream>
#include <iostream>
#include "UserService.h"


// Read all users from users.csv and returns them as a list
std::vector<User> UserService::getAllUsers() {
std::vector<User> users; // empty list to start
std::ifstream file("users.csv");

    if (!file) {
        std::cout << "Unable to open users.csv file\n";
        return;
    }

std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        User user;
        std::string id;

        std::getline(ss, id, ',');
        user.id = std::stoi(id);
        std::getline(ss, user.name, ',');
        std::getline(ss, user.email, ',');
        std::getline(ss, user.phonenumber, ',');
        std::getline(ss, user.card, ',');
        std::getline(ss, user.role, ',');

        users.push_back(user); // adds user to the list
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
         << user.role << '\n';

    std::cout << "User saved successfully!\n";
    file.close();
}