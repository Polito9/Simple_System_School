#include "Comprador.h"
#include <iostream>
#include <string> 

Comprador::Comprador(){
    direccion = "directions";
    telefono1 = "0000000000";
    telefono2 = "0000000000";
    dinero = 0.0f;
}
Comprador::Comprador(std::string username, std::string name, std::string last_name, std::string password, std::string role, std::string direccion, std::string telefono1, std::string telefono2, float dinero){
    setUsername(username);
    setName(name);
    setLast_name(last_name);
    setPassword(password);
    setRole(role);
    this->direccion = direccion;
    this->telefono1 = telefono1;
    this->telefono2 = telefono2;
    this->dinero = dinero;
}

std::string Comprador::getDireccion(){
    return direccion;
}

std::string Comprador::getTel1(){
    return telefono1;
}

std::string Comprador::getTel2(){
    return telefono2;
}

float Comprador::getDinero(){
    return dinero;
}

void Comprador::setDireccion(std::string direccion){
    this->direccion = direccion;
}

void Comprador::setTel1(std::string tel1){
    telefono1 = tel1;
}

void Comprador::setTel2(std::string tel2){
    telefono2 = tel2;
}

void Comprador::setDinero(float dinero){
    this->dinero = dinero;
}