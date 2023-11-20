#include "User.h"
#include <iostream>
#include <string> 

User::User(){
    name = "Name";
    last_name = "Name";
    password = "Name";
    role = "Name";
}

User::User(std::string name, std::string last_name, std::string password, std::string role){
    this->name = name;
    this->last_name = last_name;
    this->password = password;
    this->role = role;
}

void User::hi() {
    std::cout << "Hola, soy un usuario." << std::endl;
}

std::string User::getName(){
    return name;
}

std::string User::getLast_name(){
    return last_name;
}

std::string User::getPassword(){
    return password;
}

std::string User::getRole(){
    return role;
}