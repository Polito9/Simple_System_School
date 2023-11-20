#ifndef COMPRADOR_H
#define COMPRADOR_H
#include <string> 
#include "User.h"

class Comprador: public User{
    private:
        std::string direccion;
        std::string telefono1;
        std::string telefono2;
        float dinero;
    public:
        Comprador();
        Comprador(std::string username, std::string name, std::string last_name, std::string password, std::string role, std::string direccion, std::string telefono1, std::string telefono2, float dinero);
        std::string getDireccion();
        std::string getTel1();
        std::string getTel2();
        float getDinero();

        void setDireccion(std::string direction);
        void setTel1(std::string tel1);
        void setTel2(std::string tel2);
        void setDinero(float dinero);
};

#endif