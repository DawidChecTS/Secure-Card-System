#ifndef CARDSERVICE_H
#define CARDSERVICE_H

#include <vector>
#include "../Models/Card.h"

class CardService {
    public:
        std::vector<Card> getAllCards();
        void saveCard(Card card);
        Card findCardByUserId(int userId);
        void deleteCardByUserId(int userId);
        Card findCardById(int id);
        Card findCardByAdminId(int adminId);
};

#endif