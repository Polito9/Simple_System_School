#ifndef USER_H
#define USER_H
#include <string> 

class User{
    private:
        std::string name;
        std::string last_name;
        std::string password;
        std::string role;
    public:
        User();
        User(std::string name, std::string last_name, std::string password, std::string role);
        void hi();
        std::string getName();
        std::string getLast_name();
        std::string getPassword();
        std::string getRole();
};

#endif