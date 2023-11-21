#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include <string> 
#include "User.h"

class Proveedor: public User{
    private:
        std::string ubicacion_sucursal;
        std::string telefono;
    public:
        Proveedor();
        Proveedor(std::string username, std::string name, std::string last_name, std::string password, std::string role, std::string ubicacion_sucursal, std::string telefono);
        std::string getUbicacion_sucursal();
        std::string getTelefono();

        void setUbicacion_sucursal(std::string ubicacion_sucursal);
        void setTelefono(std::string telefono);

        bool recordObjectToFile();
};

#endif