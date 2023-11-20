#ifndef USER_H
#define USER_H
#include <string> 

class User{
    private:
        std::string username;
        std::string name;
        std::string last_name;
        std::string password;
        std::string role;
    public:
        User();
        User(std::string username, std::string name, std::string last_name, std::string password, std::string role);
        void hi();
        std::string getUsername();
        std::string getName();
        std::string getLast_name();
        std::string getPassword();
        std::string getRole();

        void setUsername(std::string username);
        void setName(std::string name);
        void setLast_name(std::string last_name);
        void setPassword(std::string password);
        void setRole(std::string role);
};

#endif