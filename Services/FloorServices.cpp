#include <fstream>
#include <sstream>
#include <iostream>
#include "FloorServices.h"

// a getter method to read all floors from the csv file and return them as a vector of Floor objects
std::vector<Floor> FloorServices::getAllFloors() {
    std::vector<Floor> floors;
    std::ifstream file("floors.csv");

    if (!file) {
        std::cout << "Unable to open floors.csv\n";
        return floors;
    }
    // read each line of the file, create a Floor object, and add it to the vector
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Floor floor;
        std::string id;
        std::string clearanceLevel;
        // read the id, name, and clearance level from the line and set them in the Floor object
        std::getline(ss, id, ',');
        floor.id = std::stoi(id);
        std::getline(ss, floor.name, ',');
        std::getline(ss, clearanceLevel, ',');
        floor.clearanceLevel = std::stoi(clearanceLevel);

        floors.push_back(floor);
    }

    file.close();
    return floors;
}