#ifndef USER_SERVICE
#define USER_SERVICE
#include "../Models/User.h"

#include <vector>


class UserService {

    public :
        std::vector<User> getAllUsers();
        void saveUser(User user);
        
        User findUser(std::string input);
};



#endif