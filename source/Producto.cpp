#include <iostream>
#include "Producto.h"

Producto::Producto(){
    id = "0";
    nombre = "default";
    categoria = "default";
    marca = "default";
    otros_detalles = "default";
    stock = 0;
    precio = 0.0f;
    user_proveedor = "default";
}

Producto::Producto(std::string id, std:: string nombre, std:: string categoria, std:: string marca, std:: string otros_detalles, int stock, float precio, std::string user_proveedor){
    this->id = id;
    this->nombre = nombre;
    this->categoria = categoria;
    this->marca = marca;
    this->otros_detalles = otros_detalles;
    this->stock = stock;
    this->precio = precio;
    this->user_proveedor = user_proveedor;
}


std::string Producto::getId(){ return id; }
std::string Producto::getNombre(){ return nombre; }
std::string Producto::getCategoria(){ return categoria; }
std::string Producto::getMarca(){ return marca; }
std::string Producto::getOtros_detalles(){ return otros_detalles; }
int Producto::getStock(){ return stock; }
float Producto::getPrecio(){ return precio; }
std::string Producto::getUser_proveedor(){ return user_proveedor; }

void Producto::setId(std:: string id){this->id = id;}
void Producto::setNombre(std:: string nombre){this->nombre = nombre;}
void Producto::setCategoria(std:: string categoria){this->categoria = categoria;}
void Producto::setMarca(std:: string marca){this->marca = marca;}
void Producto::setOtros_detalles(std:: string otros_detalles){this->otros_detalles = otros_detalles;}
void Producto::setStock(int stock){this->stock = stock;}
void Producto::setPrecio(float precio){this->precio = precio;}
