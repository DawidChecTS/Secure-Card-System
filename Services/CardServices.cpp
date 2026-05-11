#include <fstream>
#include <sstream>
#include <iostream>
#include "CardServices.h"

// a getter method to read all cards from the csv file and return them as a vector of Floor objects
std::vector<Card> CardService::getAllCards() {
    std::vector<Card> cards;
    std::ifstream file("cards.csv");

    if (!file) {
        std::cout << "Unable to open cards.csv\n";
        return cards;
    }
    // read each line of the file, create a card object, and add it to the vector
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        Card card;
        std::string id;
        std::string userId;
        std::string clearanceLevel;
        // read the id, userId, and clearance level from the line and set them in the Card object
        std::getline(ss, id, ',');
        card.id = std::stoi(id);
        std::getline(ss, userId, ',');
        card.userId = std::stoi(userId);
        std::getline(ss, clearanceLevel, ',');
        card.clearanceLevel = std::stoi(clearanceLevel);

        cards.push_back(card);
    }

    file.close();
    return cards;
}

void CardService::saveCard(Card card) {
    std::ofstream file("cards.csv", std::ios::app);

    if (!file) {
        std::cout << "Unable to open cards.csv file\n";
        return;
    }

    file << card.id << ','
    << card.userId << ','
    << card.clearanceLevel << '\n';

    file.close();
}

Card CardService::findCardByUserId(int userId) {
    std::vector<Card> cards = getAllCards();

    for (Card card : cards) {
        if (card.userId == userId) {
            return card;
        }
    }

    return Card{}; // in case no card found
}