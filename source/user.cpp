#include "User.h"
#include <iostream>
#include <string> 

User::User(){
    username = "username";
    name = "Name";
    last_name = "Name";
    password = "Name";
    role = "Name";
}

User::User(std::string username, std::string name, std::string last_name, std::string password, std::string role){
    this->username = username;
    this->name = name;
    this->last_name = last_name;
    this->password = password;
    this->role = role;
}

void User::hi() {
    std::cout << "Hola, soy un usuario." << std::endl;
}

std::string User::getUsername(){
    return username;
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

void User::setName(std::string name){
    this->name = name;
}

void User::setUsername(std::string username){
    this->username = username;
}

void User::setLast_name(std::string last_name){
    this->last_name = last_name;
}

void User::setPassword(std::string password){
    this->password = password;
}

void User::setRole(std::string role){
    this->role = role;
}
