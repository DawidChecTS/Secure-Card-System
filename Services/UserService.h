#ifndef USER_SERVICES
#define USER_SERVICES
#include "../Models/User.h"

#include <vector>


class UserService {

    public :
        std::vector<User> getAllUsers();
        void saveUser(User user);
};



#endif