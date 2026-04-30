#include <fstream>
#include <sstream>
#include <iostream>
#include "AdminServices.h"

Admin AdminServices::findAdmin(int id, std::string password) {
    std::ifstream file("admins.csv");

    if (!file) {
        std::cout << "Unable to open admins.csv\n";
        return Admin{};
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Admin admin;
        std::string adminId;

        std::getline(ss, adminId, ',');
        admin.id = std::stoi(adminId); // convert string to integer
        std::getline(ss, admin.name, ',');
        std::getline(ss, admin.password, ',');
        std::getline(ss, admin.role, ',');

        // check if both id AND password match
        if (admin.id == id && admin.password == password) {
            return admin; // found and verified!
        }
    }

    file.close();
    return Admin{}; // no match found
}