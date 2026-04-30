#ifndef ADMIN_SERVICES_H
#define ADMIN_SERVICES_H
#include "../Models/Admin.h"

class AdminServices {

public:
    Admin findAdmin(int id, std::string password);

};


#endif