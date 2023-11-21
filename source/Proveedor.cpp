#include "Proveedor.h"
#include <iostream>
#include <string> 


Proveedor::Proveedor(){
    ubicacion_sucursal = "ubicacion";
    telefono = "0000000000";
}
Proveedor::Proveedor(std::string username, std::string name, std::string last_name, std::string password, std::string role, std::string ubicacion_sucursal, std::string telefono){
    setUsername(username);
    setName(name);
    setLast_name(last_name);
    setPassword(password);
    setRole(role);
    this->ubicacion_sucursal = ubicacion_sucursal;
    this->telefono = telefono;
}

std::string Proveedor::getUbicacion_sucursal(){
    return ubicacion_sucursal;
}

std::string Proveedor::getTelefono(){
    return telefono;
}

void Proveedor::setUbicacion_sucursal(std::string ubicacion_sucursal){
    this->ubicacion_sucursal = ubicacion_sucursal;
}

void Proveedor::setTelefono(std::string telefono){
    this->telefono = telefono;
}

