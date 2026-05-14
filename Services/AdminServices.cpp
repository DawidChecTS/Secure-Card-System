#include <fstream>
#include <sstream>
#include <iostream>
#include "AdminServices.h"

// Function to find an admin by ID and password
Admin AdminServices::findAdmin(int id, std::string password) {
    std::ifstream file("admins.csv");

    if (!file) {
        std::cout << "Unable to open admins.csv\n";
        return Admin{};
    }
    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Admin admin;
        std::string adminId;

        // Parse the line into admin fields
        std::getline(ss, adminId, ',');
        admin.id = std::stoi(adminId);
        std::getline(ss, admin.name, ',');
        std::getline(ss, admin.email, ',');
        std::getline(ss, admin.phonenumber, ',');
        std::getline(ss, admin.password, ',');
        std::getline(ss, admin.card, ',');
        std::getline(ss, admin.role, ',');

        // check if both id AND password match
        if (admin.id == id && admin.password == password) {
            return admin;
        }
    }

    file.close();
    return Admin{}; // no match found
}